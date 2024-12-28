# Write your MySQL query statement be

SELECT 
 e2.name
FROM 
Employee as e1,
Employee as e2
WHERE
e1.managerId=e2.id
GROUP BY
e2.id
HAVING
count(e2.id)>=5;

-- This is more optimized