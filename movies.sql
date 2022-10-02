SELECT title
FROM   movies
WHERE  year = 2008
;


SELECT birth
FROM   people
WHERE  name = 'Emma Stone'
;


SELECT title
FROM   movies
WHERE  year >= 2018
ORDER BY title
;


SELECT COUNT(movie_id)
FROM   ratings
WHERE  rating = 10
;


SELECT title, year
FROM   movies
WHERE  title LIKE 'Harry Potter%'
ORDER BY year
;


SELECT AVG(rating)
FROM   ratings
WHERE  movie_id IN (
                     SELECT id
                     FROM   movies
                     WHERE  year = 2012
                   )
;


SELECT  movies.title,
        ratings.rating
FROM    movies
INNER JOIN ratings
ON      movies.id = ratings.movie_id
WHERE   movie_id IN (
                      SELECT  id
                      FROM    movies
                      WHERE   year = 2010
                    )
AND     rating IS NOT NULL
ORDER BY rating DESC,
        title ASC
;


SELECT name
FROM   people
WHERE  id IN (
               SELECT person_id
               FROM   stars
               WHERE  movie_id = (
                                   SELECT id
                                   FROM   movies
                                   WHERE  title = 'Toy Story'
                                 )
             )
;


SELECT DISTINCT name
FROM   people
WHERE  id IN (
               SELECT person_id
               FROM   stars
               WHERE  movie_id IN (
                                    SELECT id
                                    FROM movies
                                    WHERE year = 2004
                                  )
             )
ORDER BY birth
;


SELECT DISTINCT name
FROM   people
WHERE  id IN (
               SELECT person_id
               FROM   directors
               WHERE  movie_id IN (
                                    SELECT movie_id
                                    FROM   ratings
                                    WHERE  rating >= 9.0
                                  )
             )
;


SELECT movies.title
FROM   movies
JOIN   ratings
ON     movies.id = ratings.movie_id
WHERE  movie_id IN (
                     SELECT movie_id
                     FROM   stars
                     WHERE  person_id = (
                                          SELECT id
                                          FROM   people
                                          WHERE  name = 'Chadwick Boseman'
                                        )
                   )
ORDER BY rating DESC
LIMIT 5
;


SELECT movies.title
FROM   movies
JOIN   stars
ON     movies.id = stars.movie_id
WHERE  movie_id IN (
                     SELECT movie_id
                     FROM   stars
                     WHERE  person_id IN (
                                           SELECT id
                                           FROM   people
                                           WHERE  name = 'Johnny Depp'
                                         )
                   )
INTERSECT SELECT movies.title
FROM             movies
JOIN             stars
ON               movies.id = stars.movie_id
WHERE            movie_id IN (
                               SELECT movie_id
                               FROM   stars
                               WHERE  person_id IN (
                                                     SELECT id
                                                     FROM people
                                                     WHERE name = 'Helena Bonham Carter'
                                                   )
                             )
;


SELECT name
FROM   people
WHERE  id IN (
               SELECT person_id
               FROM   stars
               WHERE  movie_id IN (
                                    SELECT movie_id
                                    FROM   stars
                                    WHERE  person_id IN (
                                                          SELECT id
                                                          FROM people
                                                          WHERE name = 'Kevin Bacon' AND birth = 1958
                                                        )
                                  )
              )
EXCEPT
SELECT name
FROM   people
WHERE name = 'Kevin Bacon'
;
