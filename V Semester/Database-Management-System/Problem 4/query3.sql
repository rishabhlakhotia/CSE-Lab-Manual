-- Give the details of the authors who have 2 or more books in the catalog and the price of the books is greater
-- than the average price of the books in the catalog and the year of publication is after 2000.

SELECT *
FROM Author A
WHERE EXISTS (
		SELECT A1.authorid, COUNT(A1.authorid)
		FROM Author A1, Catalog C
		WHERE 
			A1.authorid = C.authorid AND
			A.authorid = A1.authorid AND
			C.yearofpublish > 2000 AND
			C.price > (
					SELECT AVG(price)
					FROM Catalog
				)
		GROUP BY A1.authorid
		HAVING COUNT(A1.authorid) >= 2
	)
;

