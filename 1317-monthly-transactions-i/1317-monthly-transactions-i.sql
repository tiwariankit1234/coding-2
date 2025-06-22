# Write your MySQL query statement below
SELECT 
country,
LEFT(trans_date,7) as month,
COUNT(id) as trans_count,
SUM(state='approved')as approved_count,
SUM(amount)as trans_total_amount,
SUM((state='approved')*amount)as approved_total_amount

FROM
 Transactions as t






GROUP BY
country,
month;