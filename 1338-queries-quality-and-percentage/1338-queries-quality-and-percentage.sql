SELECT
    query_name,
    ROUND(AVG(q.rating / q.position), 2) AS quality,
    ROUND(
        (SELECT COUNT(*) FROM Queries WHERE rating < 3 AND query_name = q.query_name) * 100.0 / COUNT(q.query_name),
        2
    ) AS poor_query_percentage
FROM
    Queries AS q
GROUP BY
    query_name;
