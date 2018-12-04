-- Filling Aircraft table with values

INSERT INTO Aircraft VALUES	
	(1, 'Airbus', 2000),
	(2, 'Boeing', 700),
	(3, 'Jet', 550),
	(4, 'Dreamliner', 5000),
	(5, 'Boeing', 4500),
	(6, 'Airbus', 2200)	
;

SELECT * FROM Aircraft;


-- Filling Employees table with values

INSERT INTO Employees VALUES
	(162, 'Andrew', 50000),
	(183, 'Laeddis', 60000),
	(192, 'Rachel', 70000),
	(204, 'Solando', 82000),
	(300, 'Tony', 5000)
;

SELECT * FROM Employees;


-- Filling Certified table with values

INSERT INTO Certified VALUES
	(162, 2),
	(162, 4),
	(162, 5),
	(162, 6),
	(183, 1),
	(183, 3),
	(183, 5),
	(192, 2),
	(192, 3),
	(192, 5),
	(192, 6),
	(204, 6),
	(204, 1),
	(204, 3),
	(300, 3)
;

SELECT * FROM Certified;


-- Filling Flights table with values

INSERT INTO Flights VALUES
	(1, 'Bengaluru', 'New Delhi', 500, TIMESTAMP '2014-11-4 09:24:26', TIMESTAMP '2014-11-4 09:24:26', 5000),
	(2, 'Bengaluru', 'Chennai', 300, TIMESTAMP '2014-11-4 09:24:26', TIMESTAMP '2014-11-4 09:24:26', 3000),
	(3, 'Trivandrum', 'New Delhi', 800, TIMESTAMP '2014-11-4 09:24:26', TIMESTAMP '2014-11-4 09:24:26', 6000),	
	(4, 'Bengaluru', 'Frankfurt', 10000, TIMESTAMP '2014-11-4 09:24:26', TIMESTAMP '2014-11-4 09:24:26', 50000),
	(5, 'Kolkata', 'New Delhi', 2400, TIMESTAMP '2014-11-4 09:24:26', TIMESTAMP '2014-11-4 09:24:26', 9000),
	(6, 'Bengaluru', 'Frankfurt', 8000, TIMESTAMP '2014-11-4  09:24:26', TIMESTAMP '2014-11-4 09:24:26', 40000)
;

SELECT * FROM Flights;
