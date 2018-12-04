--  Demonstrate how you delete all account tuples at every branch located in a specific city.

DELETE FROM BankAccount
WHERE Branchname IN (
			SELECT Branchname
			FROM Branch
			WHERE branchcity = 'BOMBAY'
		)
;
