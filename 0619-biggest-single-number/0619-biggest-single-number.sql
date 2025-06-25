# Write your MySQL query statement below

SELECT
MAX(num) as num
FROM
(
SELECT
num
FROM
MyNumbers
GROUP BY
num
HAVING COUNT(num)=1)
as
New


/* GROUP BY used karte waqt jo bhi aggregate function used hote hain toh woh usi group me used hote hain
*/
