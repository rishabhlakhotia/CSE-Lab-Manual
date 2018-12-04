-- Demonstrate how you increase the price of books published by a specific publisher by 10%.

UPDATE  Catalog 
SET price = (1.1) * price
WHERE authorid = ( 
			SELECT authorid
			FROM Author 
			WHERE name = 'NAVATHE'
		)
;
