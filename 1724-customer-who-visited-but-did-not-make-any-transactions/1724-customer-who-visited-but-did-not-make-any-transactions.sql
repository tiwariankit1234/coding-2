# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans 
from Visits v 
LEFT JOIN Transactions t 
ON v.visit_id = t.visit_id  
WHERE t.transaction_id IS NULL 
GROUP BY v.customer_id; 


-- 1 23 12 910
-- 2 9  13  970
-- 4 30 null null
-- 5 54 3 310
--    5 54 2 310
--    5 54 9 200
--    6 96 null null
--    7 54 null null 
--    8 54 null null




