Problem Statement
=================

### Relations

The following tables are maintained by a book dealer.

AUTHOR (author-id:int, name:string, city:string, country:string)

PUBLISHER (publisher-id:int, name:string, city:string, country:string)

CATALOG (book-id:int, title:string, author-id:int, publisher-id:int, category-id:int, year:int, price:int)

CATEGORY (category-id:int, description:string)

ORDER-DETAILS (order-no:int, book-id:int, quantity:int)


### Queries


1. Create the above tables by properly specifying the primary keys and the foreign keys.

2. Enter at least five tuples for each relation.

3. Give the details of the authors who have 2 or more books in the catalog and the price of the books is greater
than the average price of the books in the catalog and the year of publication is after 2000.

4. Find the author of the book which has maximum sales.

5. Demonstrate how you increase the price of books published by a specific publisher by 10%.

6. Generate suitable reports.

7. Create suitable front end for querying and displaying the results.
