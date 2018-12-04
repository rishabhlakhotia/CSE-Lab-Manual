-- Find the names of pilots whose salary is less than the price of the cheapest route from Bengaluru to Frankfurt.

SELECT E.ename 
FROM Employees E
WHERE E.salary < (
			SELECT MIN(F.price) 
			FROM Flights F
			WHERE 
				F.ffrom = 'Bengaluru' AND
				F.tto = 'Frankfurt' 			
		)
;
