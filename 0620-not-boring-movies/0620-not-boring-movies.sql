# Write your MySQL query statement below
SELECT
*
FROM
Cinema as c
WHERE 
((id%2)=1)
AND
c.description<>'boring'
ORDER BY
rating
DESC;
