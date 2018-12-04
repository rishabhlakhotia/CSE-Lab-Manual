-- Filling Student table with values

INSERT INTO Student VALUES
	('1DS16CS735', 'Rishabh', 'DBMS', '1994-06-24'),
	('1DS16CS747', 'Siddharth', 'ADA', '1993-11-9'),
	('1DS16CS701', 'Aditya', 'GTC', '1994-04-28'),
	('1DS16CS703', 'Amit', 'SE', '1993-10-7'),
	('1DS16CS730', 'Gargi', 'DS', '1993-09-12')
;

SELECT * FROM Student;


-- Filling Course table with values

INSERT INTO Course VALUES
	(1, 'DBMS', 'CS'),
	(2, 'ADA', 'CS'),
	(3, 'GTC', 'TC'),
	(4, 'SE', 'EE'),
	(5, 'DS', 'EC'),
	(6, 'DS', 'CS')
;

SELECT * FROM Course;


-- Filling Text table with values

INSERT INTO Text VALUES
	(1, 'FUNDAMENTALS OF DBMS', 'PEARSON', 'RAMEZ ELMASRI'),
	(2, 'DESGIN OF ALGORITHMS','UNIVERSITY PRESS', 'SAHNI'),
	(3, 'GRAPH THEORY', 'PRISM', 'DSC'),
	(4, 'SE BIBLE','PEARSON', 'MEENA'),
	(5, 'POWER OF JAVA', 'SUN', 'JAMES GOSLING'),
	(6, 'POWER OF C', 'JOHN WILEY', 'DENNISRITCHIE'),
	(7, 'CORMEN ALGORITHMS', 'PEARSON', 'CLRS'),
	(8, 'INTRODUCTION TO C++', 'JOHN WILEY', 'HERBERT SHIELD'),
	(9, 'DATABASE', 'JOHN WILEY', 'SHAMKANT'),
	(10, 'ENGG MATH', 'PRISM', 'KSC')
;
SELECT * FROM Text;



-- Filling Enroll table with values

INSERT INTO Enroll VALUES
	('1DS16CS735', 1, 5, 98),
	('1DS16CS747', 2, 3, 88),
	('1DS16CS701', 3, 5, 91),
	('1DS16CS703', 4, 5, 76),
	('1DS16CS730', 5, 5, 49)
;

SELECT * FROM Enroll;



-- Filling BookAdoption table with values

INSERT INTO BookAdoption VALUES
	(1, 5, 1),
	(1, 4, 4),
	(2, 3, 2),
	(3, 5, 3),
	(4, 5, 4),
	(5, 5, 5),
	(6, 4, 6),
	(6, 4, 7),
	(6, 4, 8)
;

SELECT * FROM BookAdoption;
