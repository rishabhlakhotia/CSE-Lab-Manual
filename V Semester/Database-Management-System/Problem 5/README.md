Problem Statement
=================

### Relations

Consider the following database for a banking enterprise

BRANCH(branch-name:string, branch-city:string, assets:real)

ACCOUNT(accno:int, branch-name:string, balance:real)

DEPOSITOR(customer-name:string, accno:int)

CUSTOMER(customer-name:string, customer-street:string, customer-city:string)

LOAN(loan-number:int, branch-name:string, amount:real)

BORROWER(customer-name:string, loan-number:int)


### Queries


1. Create the above tables by properly specifying the primary keys and the foreign keys

2. Enter at least five tuples for each relation

3. Find all the customers who have at least two accounts at the Main branch.

4. Find all the customers who have an account at all the branches located in a specific city.

5. Demonstrate how you delete all account tuples at every branch located in a specific city.

6. Generate suitable reports.

7. Create suitable front end for querying and displaying the results.
