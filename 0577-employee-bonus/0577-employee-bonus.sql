# Write your MySQL query statement below
SELECT 
name,bonus
FROM
employee as e
LEFT JOIN
bonus as b
ON
e.empID=b.empId
WHERE
(b.bonus is NULL
or b.bonus<1000)
;
