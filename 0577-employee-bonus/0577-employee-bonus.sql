# Write your MySQL query statement below
SELECT name,bonus FROM employee as e LEFT JOIN BONUS as b on e.empID=b.empID 
WHERE bonus<1000 or bonus is NULL