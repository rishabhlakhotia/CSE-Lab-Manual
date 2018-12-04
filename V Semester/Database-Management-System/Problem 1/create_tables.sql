-- Creating Student table

CREATE TABLE Student (
	snum INT,
	sname VARCHAR(15),
	major VARCHAR(15),
	slevel VARCHAR(15),
	age INT,
	PRIMARY KEY (snum)
);

DESC Student;


-- Creating Faculty table

CREATE TABLE Faculty (
	fid INT,
	fname VARCHAR(15),
	deptid INT,
	PRIMARY KEY (fid)
);

DESC Faculty;


-- Creating Class table

CREATE TABLE Class (
	cname VARCHAR(15), 
	meets_at VARCHAR(15), 
	room VARCHAR(15), 
	fid INT,
	PRIMARY KEY (cname),
	FOREIGN KEY (fid) REFERENCES Faculty (fid)
);

DESC Class;


-- Creating Enrolled table

CREATE TABLE Enrolled (
	snum INT,
	cname VARCHAR(15),
	FOREIGN KEY (snum) REFERENCES Student (snum),
	FOREIGN KEY (cname) REFERENCES Class (cname)
);

DESC Enrolled;

