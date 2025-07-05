# Write your MySQL query statement below
WITH CTE as(
    SELECT
    product_id,order_date,unit
    FROM
    Orders
    WHERE
    order_date>='2020-02-01' and order_date<='2020-02-29'
),
CTE2 as(
    SELECT 
    product_id as atom,SUM(unit) as total_units
    FROM
    CTE
    GROUP BY
    atom
    HAVING
    total_units>=100 
)
SELECT 
p.product_name as product_name,CTE2.total_units as unit
FROM
Products as p
INNER JOIN
CTE2
ON
p.product_id=CTE2.atom;
