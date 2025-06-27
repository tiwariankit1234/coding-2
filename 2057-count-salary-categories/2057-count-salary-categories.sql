# Write your MySQL query statement below
with cte as(
    SELECT *
    FROM Accounts
    WHERE
    income<20000
),
cte2 as(
    SELECT *
    FROM
    Accounts
    WHERE
    income<=50000 and income>=20000
),
cte3 as (
    SELECT *
    FROM
    Accounts
    WHERE
    income>50000
)

SELECT 'Low Salary' as category,count(*) as accounts_count
FROM cte
UNION 
SELECT 'Average Salary' as category,count(*) as accounts_count
FROM cte2
UNION
SELECT 'High Salary' as category,count(*) as accounts_count
FROM cte3
