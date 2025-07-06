
SELECT
visited_on,amount,ROUND(amount/7,2) as average_amount
FROM
(SELECT
distinct visited_on,SUM(amount)OVER(ORDER BY visited_on RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW)amount,MIN(visited_on) OVER() as first_date
FROM
Customer)as radhe
where visited_on>=first_date+6;