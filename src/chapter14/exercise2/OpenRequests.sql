-- Open Requests

SELECT 
    b.*,
    bc.requests
FROM
    building b
        JOIN
			(SELECT 
				b.ID BuildingID, COUNT(r.ID) as requests
			FROM
				building b
			LEFT JOIN appartment a ON a.buildingID = b.ID
			LEFT JOIN request r ON r.AppartmentID = a.ID and r.status = 'open'
            
			GROUP BY b.ID)
    AS bc ON b.ID = bc.BuildingID