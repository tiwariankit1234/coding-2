# Write your MySQL query statement below
SELECT p.unique_id,e.name from Employees as e LEFT JOIN EmployeeUNI as p on e.id=p.id