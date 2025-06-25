# Write your MySQL query statement below
WITH CTE AS(
    SELECT product_id,MIN(year)as min_year
    FROM
    Sales
    GROUP BY
    product_id
)


SELECT
s.product_id, s.year as first_year,s.quantity,s.price
FROM
Sales as s
INNER JOIN
CTE as ct
ON
s.product_id=ct.product_id
AND
s.year=ct.min_year

