-- Filling Author table with values

INSERT INTO Author VALUES 
	(1, 'NAVATHE', 'ARLINGTON', 'USA'),
	(2, 'RAGHU RAMAKRISHNAN', 'CALIFORNIA', 'USA'),
	(3, 'DHAMDHERE', 'MUMBAI', 'INDIA'),
	(4, 'BJARNE', 'NEW JERSY', 'USA'),
	(5, 'TANENBAUM', 'AMSTERDAM','NETHERLAND')
;

SELECT * FROM Author;	


-- Filling Publisher table with values

INSERT INTO Publisher VALUES 
	(1, 'JOHN WILEY', 'NEW YORK', 'USA'),
	(2, 'PEARSON', 'BANGALORE', 'INDIA'),
	(3, 'O REILLY', 'NEW JERSY', 'USA'),
	(4, 'TMH', 'CALCUTTA', 'INDIA'),
	(5, 'JOHN WILEY', 'NEW DELHI', 'INDIA')
;

SELECT * FROM Publisher;


-- Filling BookCategory table with values

INSERT INTO BookCategory VALUES 
	(1, 'DATABASE MANAGEMENT'),
	(2, 'OPERATING SYSTEMS'),
	(3, 'C++'),
	(4, 'COMPUTER NETWORKS'),
	(5, 'C')
;

SELECT * FROM BookCategory;


-- Filling Catalog table with values

INSERT INTO Catalog VALUES 
	(1, 'FUNDAMENTALS OF DBMS', 1, 2, 1, 2004, 500),
	(2, 'PRINCIPLES OF DBMS', 2, 1, 1, 2004, 400),
	(3, 'OPERATING SYSTEMS', 3, 4, 2, 2004, 200),
	(4, 'C++ BIBLE', 4, 5, 3, 2003, 500),
	(5, 'COMPUTER NETWORKS', 5, 3, 4, 2002, 250),
	(6, 'FUNDAMENTALS OF C', 1, 2, 5, 2004, 700),
	(7, 'OPERATING SYSTEMS 2', 3, 2, 2, 2001, 600)
;

SELECT * FROM Catalog;


-- Filling OrderDetails table with values

INSERT INTO OrderDetails VALUES 
	(1, 1, 1),
	(2, 2, 1),
	(3, 3, 1),
	(4, 4, 1),
	(5, 5, 1),
	(6, 6, 7),
	(7, 7, 9)
;

SELECT * FROM OrderDetails;

