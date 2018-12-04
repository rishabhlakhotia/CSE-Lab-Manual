-- Filling Branch table with values

INSERT INTO Branch VALUES
	('CHAMRAJPET', 'BANGALORE', 50000),
	('RESIDENCY ROAD', 'BANGALORE', 10000),
	('M G ROAD', 'BOMBAY', 100000),
	('CP', 'DELHI', 100000),
	('JANTARMANTAR', 'DELHI', 100000)
;

SELECT * FROM Branch;		


-- Filling BankAccount table with values

INSERT INTO BankAccount VALUES
	(1, 'CHAMRAJPET', 2000),
	(2, 'RESIDENCY ROAD', 5000),
	(3, 'M G ROAD', 6000),
	(4, 'CP', 9999),
	(5, 'JANTARMANTAR', 999),
	(6, 'M G ROAD', 999),
	(8, 'RESIDENCY ROAD', 999),
	(9, 'CP', 10000),
	(10, 'RESIDENCY ROAD', 5000),
	(11, 'JANTARMANTAR', 9999)
;

SELECT * FROM BankAccount;


-- Filling BankCustomer table with values

INSERT INTO BankCustomer VALUES
	('ANNE', 'BULL TEMPLE ROAD', 'BANGALORE'),
	('DANNY', 'BANNERGATTA ROAD', 'BANGALORE'),
	('TOM', 'J C ROAD', 'BANGALORE'),
	('NICK', 'CP', 'DELHI'),
	('ROVER', 'JANTARMANTAR', 'DELHI')
;

SELECT * FROM BankCustomer;


-- Filling Depositer table with values

INSERT INTO Depositer VALUES
	('ANNE', 1),
	('DANNY', 2),	
	('NICK', 4),
	('ROVER', 5),	
	('ANNE', 8),
	('NICK', 9),
	('DANNY', 10),
	('NICK', 11)
;

SELECT * FROM Depositer;


-- Filling Loan table with values

INSERT INTO Loan VALUES
	(1, 'CHAMRAJPET', 1000),
	(2, 'RESIDENCY ROAD', 2000),
	(3, 'M G ROAD', 3000),
	(4, 'CP', 4000),
	(5, 'JANTARMANTAR', 5000)
;

SELECT * FROM Loan;


-- Filling Borrower table with values

INSERT INTO Borrower VALUES
	('ANNE', 1),
	('ANNE', 2),
	('TOM', 3),
	('NICK', 4),
	('ROVER', 5)
;

SELECT * FROM Borrower;

