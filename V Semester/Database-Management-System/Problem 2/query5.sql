-- Find the names of pilots certified for some Boeing aircraft.

SELECT DISTINCT E.ename 
FROM Employees E, Certified C, Aircraft A
WHERE 
	E.eid = C.eid AND
	A.aid = C.aid AND
	A.aname = 'Boeing'
;
