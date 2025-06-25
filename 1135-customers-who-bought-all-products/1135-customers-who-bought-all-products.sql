With distinctkey as(
    SELECT
    DISTINCT product_key
    FROM
    Product
),
distprod as (
SELECT
COUNT(product_key) as total_products
FROM
distinctkey
)

SELECT
    C.customer_id
FROM
    Customer C
GROUP BY
    C.customer_id
HAVING
    COUNT(DISTINCT C.product_key) = (SELECT total_products FROM distprod);