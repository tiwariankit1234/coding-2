-- ALTER TABLE views
-- CHANGE COLUMN author_id id INT;

-- SELECT DISTINCT id
-- FROM views
-- WHERE id = viewer_id
-- ORDER BY id;
SELECT DISTINCT author_id as id FROM views where author_id=viewer_id ORDER BY id;

