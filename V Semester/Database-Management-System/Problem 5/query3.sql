-- Find all the customers who have at least two accounts at the Main branch.

SELECT *
FROM BankCustomer C
WHERE EXISTS (
		SELECT D.customername, COUNT(D.customername)
		FROM Depositer D, BankAccount BA
		WHERE 
			D.accno = BA.accno AND
			C.customername = D.customername AND
			BA.branchname = 'RESIDENCY ROAD'

		GROUP BY D.customername
		HAVING COUNT(D.customername) >= 2
	)
;

