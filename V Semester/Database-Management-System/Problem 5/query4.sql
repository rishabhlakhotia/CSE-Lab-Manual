-- Find all the customers who have an account at all the branches located in a specific city.

SELECT *
FROM BankCustomer BC
WHERE NOT EXISTS (
			SELECT branchname
			FROM Branch
			WHERE 
				branchcity = 'DELHI' AND
				(branchname) NOT IN (
							SELECT BA.branchname
							FROM Depositer D, BankAccount BA
							WHERE 
								D.accno = BA.accno AND
								BC.customername = D.customername 
						)		
		)
;	
