INSERT INTO dictionary
	(id, dic_name, value, order_num)
	SELECT 
		row_number() OVER() + (SELECT MAX(id) FROM dictionary),
		'land',
		'territory',
		(SELECT MAX(order_num) FROM dictionary WHERE dic_name = 'land') + 1;


INSERT INTO country 
	(name, par_id, object_type_id)
	VALUES 
		('Greenland',
		(SELECT id FROM country WHERE name = 'Denmark'),
		(SELECT id FROM dictionary WHERE value = 'territory')),

		('Gibraltar',
		(SELECT id FROM country WHERE name = 'United Kingdom'),
		(SELECT id FROM dictionary WHERE value = 'territory')),

		('Montserrat',
		(SELECT id FROM country WHERE name = 'United Kingdom'),
		(SELECT id FROM dictionary WHERE value = 'territory'));


WITH RECURSIVE CTE_hierarchy_europe AS
		(SELECT 
			c.id AS id,
			c.name AS name, 
			(SELECT value FROM dictionary d WHERE d.id = c.object_type_id) AS type_of_land, 
			1 AS level
		FROM 
			country c
 		WHERE c.name = 'Europe'
		UNION
		SELECT 
			c.id AS id,
			c.name AS name, 
			(SELECT value FROM dictionary d WHERE d.id = c.object_type_id) AS type_of_land, 
			CTE_hierarchy_europe.level + 1 AS level
		FROM
			country c
		INNER JOIN
			CTE_hierarchy_europe
 		ON c.par_id = CTE_hierarchy_europe.id
		OR c.par_id IN 
		 		(SELECT id 
				 FROM country 
				 WHERE par_id = CTE_hierarchy_europe.id))
	SELECT * FROM CTE_hierarchy_europe;


