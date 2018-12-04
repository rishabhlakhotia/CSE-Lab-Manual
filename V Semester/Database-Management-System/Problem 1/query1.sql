-- Find the names of all Juniors (level = JR) who are enrolled in a class taught by Prof. Venkatesan

SELECT DISTINCT S.sname
FROM Student S, Enrolled E, Class C, Faculty F
WHERE
	S.snum = E.snum AND
	E.cname = C.cname AND
	C.fid = F.fid AND
	F.fname = 'Prof. Venkatesan' AND
	S.slevel = 'JR'
;
