# Write your MySQL query statement below
SELECT
sell_date,COUNT(DISTINCT product) as num_sold,
  GROUP_CONCAT( DISTINCT product ORDER BY product)as products
FROM
Activities
GROUP BY
sell_date;