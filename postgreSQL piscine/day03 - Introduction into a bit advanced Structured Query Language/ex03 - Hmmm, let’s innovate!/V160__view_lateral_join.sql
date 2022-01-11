CREATE VIEW v_fibonacci_country_lateral AS
	WITH RECURSIVE CTE_fibonacci_country AS 
		(SELECT
			1 AS fibonacci,
			0 AS fibonacci1
		UNION ALL
		SELECT
			CTE_fc.fibonacci + CTE_fc.fibonacci1 AS fibonacci,
			CTE_fc.fibonacci AS fibonacci1
		FROM 
			CTE_fibonacci_country AS CTE_fc
		WHERE CTE_fc.fibonacci + CTE_fc.fibonacci1 < 2000)
				
	SELECT 
		f.fibonacci, 
		t1.country_id, 
		t1.country_name 
	FROM 
		CTE_fibonacci_country f
	LEFT JOIN LATERAL 
		(SELECT 
			c.id AS country_id,
			c.name AS country_name
		FROM
			country c
		WHERE c.object_type_id = (SELECT id FROM dictionary WHERE value = 'country')) 
	AS t1
	ON t1.country_id = f.fibonacci + f.fibonacci1
	ORDER BY fibonacci;