-- Creating Student table

CREATE TABLE Student (
	regno VARCHAR(30),
	sname VARCHAR(30),
	major VARCHAR(30),
	bdate DATE,
	PRIMARY KEY (regno)
); 

DESC Student;


-- Creating Course table

CREATE TABLE Course (
	course INT,
	cname VARCHAR(30),
	dept VARCHAR(30),
	PRIMARY KEY (course)
); 

DESC Course;


-- Creating Enroll table

CREATE TABLE Enroll (
	regno VARCHAR(30),
	course INT,
	sem INT,
	marks INT,
	PRIMARY KEY (regno, course, sem),
	FOREIGN KEY (regno) REFERENCES Student(regno),
	FOREIGN KEY (course) REFERENCES Course(course)); 

DESC Enroll;


-- Creating Text table

CREATE TABLE Text (
	bookisbn INT,
	booktitle VARCHAR(30),
	publisher VARCHAR(30),
	author VARCHAR(30),
	PRIMARY KEY (bookisbn)
);

DESC Text;


-- Creating BookAdoption table

CREATE TABLE BookAdoption (
	course INT,
	sem INT,
	bookisbn INT,
	PRIMARY KEY (course, sem, bookisbn),
	FOREIGN KEY (course) REFERENCES Course (course),
	FOREIGN KEY (bookisbn) REFERENCES Text (bookisbn)
); 

DESC BookAdoption;


