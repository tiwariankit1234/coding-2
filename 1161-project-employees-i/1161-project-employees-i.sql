# Write your MySQL query statement below
SELECT 
p.project_id,ROUND(AVG(experience_years),2) as average_years

FROM
project as p,employee as e
WHERE
p.employee_id=e.employee_id
GROUP BY
p.project_id;