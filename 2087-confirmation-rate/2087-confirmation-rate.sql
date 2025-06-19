# Write your MySQL query statement below
SELECT
sg.user_id,ROUND(AVG(if(con.action="confirmed",1.0,0.0)),2)as confirmation_rate 
FROM 
Signups as sg
LEFT JOIN
Confirmations as con

ON
sg.user_id=con.user_id
GROUP BY
sg.user_id
