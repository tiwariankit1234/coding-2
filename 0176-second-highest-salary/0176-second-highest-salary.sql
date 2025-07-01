
   SELECT (SELECT DISTINCT COALESCE(salary, 0) -- Corrected COALESCE syntax
     FROM Employee
     ORDER BY salary DESC
     LIMIT 1 OFFSET 1
    ) as SecondHighestSalary






