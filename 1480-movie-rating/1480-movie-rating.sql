-- CTE to find the number of ratings per user
WITH UserRatingCounts AS (
    SELECT 
        user_id, 
        COUNT(*) AS rated_movies 
    FROM 
        MovieRating 
    GROUP BY 
        user_id
),
-- CTE to find the average rating for movies in February 2020
MovieAvgFebRating AS (
    SELECT 
        movie_id, 
        AVG(rating) AS avg_rating 
    FROM 
        MovieRating 
    WHERE 
        created_at >= '2020-02-01' AND created_at < '2020-03-01' -- Using '<' is safer for timestamps
    GROUP BY 
        movie_id
)

-- Query 1: Find the user who rated the most movies
(SELECT 
    u.name AS results 
FROM 
    Users u
JOIN 
    UserRatingCounts urc ON u.user_id = urc.user_id 
ORDER BY 
    urc.rated_movies DESC, u.name ASC -- Tie-break by name alphabetically
LIMIT 1)

UNION ALL -- Use UNION ALL for better performance since the two results are distinct

-- Query 2: Find the movie with the highest average rating in Feb 2020
(SELECT 
    m.title AS results 
FROM 
    Movies m
JOIN 
    MovieAvgFebRating mafr ON m.movie_id = mafr.movie_id 
ORDER BY 
    mafr.avg_rating DESC, m.title ASC -- Tie-break by title alphabetically
LIMIT 1);