Problem Statement
=================

### Relations

The following relations keep track of airline flight information:

Flights (no: integer, from: string, to: string, distance: integer, Departs: time, arrives: time, price: real)

Aircraft (aid: integer, aname: string, cruisingrange: integer)

Certified (eid: integer, aid: integer)

Employees (eid: integer, ename: string, salary: integer)


Note that the Employees relation describes pilots and other kinds of employees as well; Every pilot is certified
for some aircraft, and only pilots are certified to fly.

### Queries

Write each of the following queries in SQL:

1. Find the names of aircraft such that all pilots certified to operate them have salaries more than Rs.80, 000.

2. For each pilot who is certified for more than three aircrafts, find the eid and the maximum cruisingrange of
the aircraft for which she or he is certified.

3. Find the names of pilots whose salary is less than the price of the cheapest route from Bengaluru to Frankfurt.

4. For all aircraft with cruisingrange over 1000 Kms,. Find the name of the aircraft and the average salary of all
pilots certified for this aircraft.

5. Find the names of pilots certified for some Boeing aircraft.

6. Find the aids of all aircraft that can be used on routes from Bengaluru to New Delhi.
