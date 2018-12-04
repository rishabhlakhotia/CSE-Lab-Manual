-- Find the author of the book which has maximum sales.

SELECT DISTINCT A.NAME
FROM Author A, Catalog C, OrderDetails ODM
WHERE 
	A.authorid = C.authorid AND 
	ODM.bookid = C.bookid AND
	EXISTS (
			SELECT OD.bookid, SUM(OD.quantity)
			FROM OrderDetails OD
			WHERE OD.bookid = ODM.bookid
			GROUP BY bookid
			HAVING SUM(OD.quantity) >= ALL (
							SELECT SUM(quantity)
							FROM OrderDetails
							GROUP BY bookid
							)
		)
;
			
