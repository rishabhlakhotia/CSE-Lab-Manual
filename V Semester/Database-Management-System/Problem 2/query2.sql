-- For each pilot who is certified for more than three aircrafts, find the eid and the maximum cruisingrange of 
-- the aircraft for which she or he is certified.

SELECT C.eid, MAX(A.cruisingrange)
FROM Certified C, Aircraft A
WHERE A.aid = C.aid
GROUP BY C.eid 
HAVING COUNT(*) > 3
	
;

		
