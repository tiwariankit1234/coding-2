# Write your MySQL query statement below
WITH CTE AS(
    SELECT 
    COUNT(student)as number,
    class
    FROM
    Courses
    GROUP BY
    class
)

SELECT
class 
FROM
CTE
WHERE
number>=5