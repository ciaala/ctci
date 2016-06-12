UPDATE Request r JOIN (SELECT 
        r1.ID, a.BuildingID
    FROM
        Request r1
    JOIN Appartment a ON r1.AppartmentID = a.ID)  as rr
    ON rr.ID = r.ID
SET 
    r.status = 'closed'
WHERE
    rr.buildingID = 4