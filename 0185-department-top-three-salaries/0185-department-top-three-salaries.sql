# Write your MySQL query statement below
WITH CTE as(
    SELECT
    id,name,salary,departmentId,DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC)as popularity
    FROM
    Employee
)
 

    SELECT
    d.name as Department,CTE.name as Employee,CTE.salary as Salary
    FROM
    Department as d
    INNER JOIN
    CTE
    ON
    d.id=CTE.departmentId
    WHERE
    CTE.popularity<=3
    ORDER BY
    d.name;

