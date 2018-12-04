-- Find the names of faculty members for whom the combined enrollment of the courses that they teach is less 
-- than five.

SELECT DISTINCT F.fname
FROM Faculty F
WHERE 5 > (
		SELECT COUNT(E.snum)
		FROM Class C, Enrolled E
		WHERE 
			C.cname = E.cname AND
			C.fid = F.fid
	)
;
