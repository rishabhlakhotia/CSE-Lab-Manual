-- Creating Branch table

CREATE TABLE Branch (
	branchname VARCHAR(30),
	branchcity VARCHAR(30),
	assets REAL,
	PRIMARY KEY (branchname)
);

DESC Branch;


-- Creating BankAccount table

CREATE TABLE BankAccount (
	accno INT,
	branchname VARCHAR(30),
	balance REAL,
	PRIMARY KEY (accno),
	FOREIGN KEY (branchname) REFERENCES Branch (branchname)
);

DESC BankAccount;


-- Creating BankCustomer table

CREATE TABLE BankCustomer (
	customername VARCHAR(30),
	customerstreet VARCHAR(30),
	customercity VARCHAR(30),
	PRIMARY KEY (customername)
);

DESC BankCustomer;


-- Creating Depositer table

CREATE TABLE Depositer (
	customername VARCHAR(30),
	accno INT,
	PRIMARY KEY (customername, accno),
	FOREIGN KEY (customername) REFERENCES BankCustomer (customername),
	FOREIGN KEY (accno) REFERENCES BankAccount (accno)
);

DESC Depositer;


-- Creating Loan table

CREATE TABLE Loan (
	loannumber INT,
	branchname VARCHAR(30),
	amount REAL,
	PRIMARY KEY (loannumber),
	FOREIGN KEY (branchname) REFERENCES Branch (branchname)
);

DESC Loan;


-- Creating Borrower table

CREATE TABLE Borrower (
	customername VARCHAR(30),
	loannumber INT,
	PRIMARY KEY (customername, loannumber),
	FOREIGN KEY (customername) REFERENCES BankCustomer (customername),
	FOREIGN KEY (loannumber) REFERENCES Loan (loannumber)
);

DESC Borrower;
