# Write your MySQL query statement below
SELECT PRODUCT_NAME,YEAR,PRICE FROM SALES as s INNER JOIN PRODUCT AS p on s.product_id=p.product_id;