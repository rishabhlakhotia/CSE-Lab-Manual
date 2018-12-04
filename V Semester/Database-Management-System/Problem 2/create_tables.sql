-- Creating Flights table

CREATE TABLE Flights (
	flno INT,
	ffrom VARCHAR(15),
	tto VARCHAR(15),
	distance INTEGER,
	departs TIMESTAMP,
	arrives TIMESTAMP,
	price REAL,
	PRIMARY KEY (flno)
);

DESC Flights;


-- Creating Aircraft table

CREATE TABLE Aircraft (
	aid INT,
	aname VARCHAR(15),
	cruisingrange INT,
	PRIMARY KEY (aid)
);

DESC Aircraft;


-- Creating Employees table

CREATE TABLE Employees (
	eid INT,
	ename VARCHAR(15),
	salary REAL,
	PRIMARY KEY (eid)
);

DESC Employees;


-- Creating Certified table

CREATE TABLE Certified (
	eid INT,
	aid INT,
	PRIMARY KEY (eid, aid), 
	FOREIGN KEY (eid) REFERENCES Employees (eid),
	FOREIGN KEY (aid) REFERENCES Aircraft (aid)
);

DESC Certified;

