-- For all aircraft with cruisingrange over 1000 Kms,. Find the name of the aircraft and the average salary of all 
-- pilots certified for this aircraft.

SELECT A.aname, AVG (E.SALARY) 
FROM Aircraft A, Certified C, Employees E
WHERE 
	A.aid = C.aid AND
	C.eid = E.eid AND 
	A.cruisingrange > 1000

GROUP BY A.aid, A.aname

;
