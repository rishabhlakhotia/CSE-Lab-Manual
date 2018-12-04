-- Creating Author table

CREATE TABLE Author (
	authorid INT,
	name VARCHAR(30),
	city VARCHAR(30),
	country VARCHAR(30),
	PRIMARY KEY (authorid)
);

DESC Author;


-- Creating Publisher table

CREATE TABLE Publisher (
	publisherid INT,
	name VARCHAR(30),
	city VARCHAR(30),
	country VARCHAR(30),
	PRIMARY KEY (publisherid)
);

DESC Publisher;


-- Creating BookCategory table

CREATE TABLE BookCategory (
	categoryid INT ,
	description VARCHAR(30),
	PRIMARY KEY (categoryid)
);

DESC BookCategory;


-- Creating Catalog table

CREATE TABLE Catalog (
	bookid INT,
	title VARCHAR(30),
	authorid INT,
	publisherid INT,
	categoryid INT,
	yearofpublish INT,
	price INT,
	PRIMARY KEY (bookid),
	FOREIGN KEY (authorid) REFERENCES Author (authorid),
	FOREIGN KEY (publisherid) REFERENCES Publisher (publisherid),
	FOREIGN KEY (categoryid) REFERENCES BookCategory (categoryid)
);

DESC Catalog;


-- Creating OrderDetails table

CREATE TABLE OrderDetails (
	orderno INT,
	bookid INT,
	quantity INT,
	PRIMARY KEY (orderno, bookid),
	FOREIGN KEY (bookid) REFERENCES Catalog(bookid)
);

DESC OrderDetails;
