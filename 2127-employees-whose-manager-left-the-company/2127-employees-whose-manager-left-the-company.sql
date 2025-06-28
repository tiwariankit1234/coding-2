WITH CTE AS (
    SELECT
        employee_id,
        manager_id
    FROM Employees
    WHERE salary < 30000
)
SELECT
    CTE.employee_id
   
FROM CTE
LEFT JOIN Employees AS mgr
    ON CTE.manager_id = mgr.employee_id
WHERE mgr.employee_id IS NULL
AND CTE.manager_id IS NOT NULL
ORDER BY
 CTE.employee_id;
