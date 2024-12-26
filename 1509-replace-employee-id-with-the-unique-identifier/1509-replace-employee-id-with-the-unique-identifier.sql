# Write your MySQL query statement below
SELECT NAME,UNIQUE_ID FROM Employees AS E LEFT JOIN EmployeeUNI AS EU ON
E.ID=EU.ID