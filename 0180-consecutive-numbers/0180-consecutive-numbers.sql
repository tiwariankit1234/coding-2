# Write your MySQL query statement below
SELECT 
DISTINCT
l1.num as ConsecutiveNums
FROM
Logs l1
INNER JOIN
Logs l2 ON l1.id+1=l2.id and l1.num=l2.num
INNER JOIN
logs l3 ON l2.id+1=l3.id and l2.num=l3.num;
