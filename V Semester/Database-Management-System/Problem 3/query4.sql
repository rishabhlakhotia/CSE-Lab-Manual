-- Produce a list of text books (include Course #, Book-ISBN, Book-title) in the alphabetical order for courses
-- offered by the ‘CS’ department that use more than two books.

SELECT C.course, T.bookisbn, T.booktitle 
FROM Course C, BookAdoption BA, Text T 
WHERE 
	C.course = BA.course AND
	BA.bookisbn = T.bookisbn AND 
	C.dept = 'CS' AND
	EXISTS (
			SELECT *
			FROM BookAdoption BA1
			WHERE BA1.course = C.course
			GROUP BY BA1.course
			HAVING COUNT(BA1.course) > 2
		) 
ORDER BY T.booktitle

; 
