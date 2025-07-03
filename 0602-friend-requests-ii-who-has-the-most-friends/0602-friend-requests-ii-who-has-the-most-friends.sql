# Write your MySQL query statement below
WITH CTE1 as(
    SELECT requester_id,COUNT(*) as r_id
    FROM
    RequestAccepted 
    GROUP BY
    requester_id
),
CTE2 as (
      SELECT accepter_id,COUNT(*) as a_id
    FROM
    RequestAccepted 
    GROUP BY
    accepter_id
),
CTE3 as(
    SELECT
    CTE1.requester_id as id,SUM(CTE1.r_id+CTE2.a_id) as result
    FROM
    CTE1
    INNER JOIN
    CTE2
    ON
    CTE1.requester_id=CTE2.accepter_id
    GROUP BY
    CTE1.requester_id
    UNION
    SELECT
    CTE1.requester_id as id,SUM(CTE1.r_id)as num
    FROM
    CTE1
    GROUP BY
CTE1.requester_id
UNION
SELECT
CTE2.accepter_id as id,SUM(CTE2.a_id) as num
FROM
CTE2
GROUP BY
CTE2.accepter_id
)
SELECT 
id,result as num
FROM
CTE3
GROUP BY
id
ORDER BY
result
DESC
limit  1;

