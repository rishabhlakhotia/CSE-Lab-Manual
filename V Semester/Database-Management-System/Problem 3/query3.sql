-- Demonstrate how you add a new text book to the database and make this book be adopted by some
-- department.

INSERT INTO Text VALUES (11, 'DATABASE FUNDAMENTALS', 'TATA MCGRAW HILL', 'SCHIELD');
INSERT INTO BookAdoption VALUES (1, 3, 11);
