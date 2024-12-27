# Write your MySQL query statement below
SELECT w2.id
FROM 
WEATHER w1,WEATHER w2
WHERE 
DATEDIFF(w2.recordDate,W1.recordDate)=1
AND
w2.temperature>w1.temperature;