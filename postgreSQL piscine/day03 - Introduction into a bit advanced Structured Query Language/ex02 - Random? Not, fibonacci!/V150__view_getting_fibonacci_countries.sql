CREATE VIEW v_fibonacci_country AS
	WITH RECURSIVE CTE_fibonacci_country AS (
		SELECT
			1 AS fibonacci,
			0 AS fibonacci1,
			c.id AS country_id,
			c.name AS country_name
		FROM 
			country c
		WHERE 
			c.id = 1
		UNION ALL
		SELECT
			CTE_fc.fibonacci + CTE_fc.fibonacci1 AS fibonacci,
			CTE_fc.fibonacci AS fibonacci1,
			c.id AS country_id,
			c.name AS country_name
		FROM 
			CTE_fibonacci_country AS CTE_fc
		LEFT JOIN 
			country c
		ON c.id = CTE_fc.fibonacci + CTE_fc.fibonacci1
		WHERE CTE_fc.fibonacci + CTE_fc.fibonacci1 < 2000
	)
	SELECT 
		fibonacci, 
		country_id, 
		country_name 
	FROM 
		CTE_fibonacci_country
	ORDER BY fibonacci;