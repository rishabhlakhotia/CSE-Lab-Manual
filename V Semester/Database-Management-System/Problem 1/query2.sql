-- Find the names of all classes that either meet in room R128 or have five or more Students enrolled.

SELECT DISTINCT C.cname 
FROM Class C
WHERE
	C.room = 'R128' OR
	C.cname IN (
			SELECT E.cname
			FROM Enrolled E
			GROUP BY E.cname
			HAVING COUNT(*) >= 5
		)
;
