SELECT 
    ROUND(
        COUNT(CASE WHEN order_date = customer_pref_delivery_date THEN 1 END) * 100.0 
        / COUNT(*), 
        2
    ) AS immediate_percentage
FROM 
    delivery
WHERE 
    (customer_id, order_date) IN (
        SELECT 
            customer_id, 
            MIN(order_date) AS first_order
        FROM 
            delivery
        GROUP BY 
            customer_id
    );
