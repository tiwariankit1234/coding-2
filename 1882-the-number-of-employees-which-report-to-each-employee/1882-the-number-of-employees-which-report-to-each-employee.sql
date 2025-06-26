# Write your MySQL query statement below
SELECT
e2.employee_id,e2.name,ROUND(COUNT(e1.reports_to))as reports_count,ROUND(AVG(e1.age)) as average_age

FROM
Employees as e1 
INNER JOIN
Employees as e2
ON
e1.reports_to=e2.employee_id
GROUP BY
e2.employee_id
ORDER BY
e2.employee_id

