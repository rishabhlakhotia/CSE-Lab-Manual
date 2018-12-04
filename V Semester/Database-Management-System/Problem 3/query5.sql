-- List any department that has all its adopted books published by a specific publisher.

SELECT C.dept, T.booktitle, T.publisher 
FROM Course C, Text T, BookAdoption BA 
WHERE 
	C.course = BA.course AND 
	T.bookisbn = BA.bookisbn AND
	T.publisher = 'PEARSON'AND
	T.publisher = ALL (
				SELECT T1.publisher 
				FROM Course C1, BookAdoption BA1, Text T1 
				WHERE 
					BA1.bookisbn = T1.bookisbn AND 
					BA1.course = C1.course AND 
					C.dept = C1.dept
			)
; 

