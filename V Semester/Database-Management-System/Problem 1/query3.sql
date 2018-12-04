-- Find the names of all students who are enrolled in two classes that meet at the same time.

SELECT DISTINCT S.sname
FROM Student S
WHERE S.snum IN (
			SELECT E1.snum
			FROM Enrolled E1, Enrolled E2, Class C1, Class C2
			WHERE 
				E1.snum = E2.snum AND 
				E1.cname <> E2.cname AND
				E1.cname = C1.cname AND 
				E2.cname = C2.cname AND 
				C1.meets_at = C2.meets_at
		)
;

		
