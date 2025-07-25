# Write your MySQL query statement below
SELECT ROUND(SUM(tiv_2016),2) as tiv_2016
FROM
Insurance
WHERE
tiv_2015 IN(
    SELECT
    tiv_2015
    FROM
    INSURANCE
    GROUP BY
    tiv_2015
    HAVING
    COUNT(*)>1
)
AND
(lat,lon) IN
(
    SELECT lat,lon
    FROM
    Insurance
    GROUP BY
    lat,lon
    HAVING
    COUNT(*)=1

)

-- count(*) will give the row that have the same value
