Problem Statement
=================

### Relations

Consider the following relations:

Student (snum: integer, sname: string, major: string, level: string, age: integer)

Class (name: string, meets at: string, room: string, fid: integer)

Enrolled (snum: integer, cname: string)

Faculty (fid: integer, fname: string, deptid: integer)


The meaning of these relations is straightforward; for example, Enrolled has one record per student-class pair
such that the student is enrolled in the class. Level is a two character code with 4 different values (example:
Junior: JR etc)

### Queries

Write the following queries in SQL. No duplicates should be printed in any of the answers.

1. Find the names of all Juniors (level = JR) who are enrolled in a class taught by Prof. Venkatesan

2. Find the names of all classes that either meet in room R128 or have five or more Students enrolled.

3. Find the names of all students who are enrolled in two classes that meet at the same time.

4. Find the names of faculty members who teach in every room in which some class is taught.

5. Find the names of faculty members for whom the combined enrollment of the courses that they teach is less
than five.
