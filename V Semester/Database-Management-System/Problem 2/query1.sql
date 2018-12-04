-- Find the names of Aircraft such that all pilots certified to operate them have salaries more than Rs.80,000.

SELECT DISTINCT A.aname
FROM Aircraft A
WHERE A.aid IN (
			SELECT C.aid
			FROM Certified C, Employees E
			WHERE 
				C.eid = E.eid AND
				NOT EXISTS (
						SELECT * 
						FROM Employees E1
						WHERE 
							E1.eid = E.eid AND 
							E1.salary <= 80000
					)
		)
;
