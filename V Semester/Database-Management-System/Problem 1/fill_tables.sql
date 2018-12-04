-- Filling Student table with values

INSERT INTO Student VALUES
		(2, 'Rishabh', 'EC', 'SR', 20),
		(3, 'Aditya', 'CS', 'SR', 20),
		(4, 'Siddharth', 'CS', 'JR', 18),
		(5, 'Amit', 'CS', 'SSR', 22),
		(6, 'Gargi', 'EC', 'SJR', 17)
	;

SELECT * FROM Student;

-- Filling Faculty table with values

INSERT INTO Faculty VALUES
		(55, 'Prof. Venkatasen', 7),
		(66, 'Prof. Prasad', 7),
		(77, 'Prof. Anupama', 8),
		(88, 'Prof. Poornima', 9),
		(99, 'Prof. Anil', 9)
	;

SELECT * FROM Faculty;


-- Filling Class table with values

INSERT INTO Class VALUES
		('CS1', '12 HR', 'R128', 55),
		('CS2', '11 HR', 'R138', 66),
		('CS3', '12 HR', 'R148', 77),
		('CS4', '11 HR', 'R158', 88),
		('CS5', '12 HR', 'R168', 99),
		('CS6', '1 HR', 'R138', 55),
		('CS7', '2 HR', 'R148', 55),
		('CS8', '3 HR', 'R158', 55),
		('CS9', '4 HR', 'R168', 55)
	;

SELECT * FROM Class;


-- Filling Enrolled table with values

INSERT INTO Enrolled VALUES
		(2, 'CS1'),
		(3, 'CS2'),
		(4, 'CS1'),
		(5, 'CS4'),
		(6, 'CS5'),
		(2, 'CS3'),
		(3, 'CS4')
	;

SELECT * FROM Enrolled;
