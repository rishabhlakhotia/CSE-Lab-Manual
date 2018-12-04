-- Find the aids of all aircraft that can be used on routes from Bengaluru to New Delhi.

SELECT DISTINCT A.aid
FROM Aircraft A
WHERE A.cruisingrange > (
				SELECT MIN(F.distance) 
				FROM Flights F 
				WHERE 
					F.ffrom = 'Bengaluru' AND 
					F.tto = 'New Delhi'
			)
; 
