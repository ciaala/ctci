-- Write a SQL query to get a list of tenants who are renting more than one appartments
USE exercise;
 
SELECT 
    *
FROM
    Tenant t
        JOIN
    (SELECT 
        t.ID as TenantID, COUNT(AppartmentID) AS count
    FROM
        Tenant t
    LEFT JOIN Appartment_Tenant ta ON t.ID = ta.TenantID
    GROUP BY t.ID) AS tc ON t.ID = tc.TenantID
WHERE
    tc.count > 1


