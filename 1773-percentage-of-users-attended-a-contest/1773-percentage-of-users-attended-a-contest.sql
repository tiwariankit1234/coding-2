# Write your MySQL query statement below
SELECT
contest_id,ROUND((COUNT(r.contest_id))/(SELECT COUNT(*)FROM USERS)*100,2) as percentage
FROM
register as r

GROUP BY
r.contest_id
ORDER BY
percentage DESC,
contest_id ;


