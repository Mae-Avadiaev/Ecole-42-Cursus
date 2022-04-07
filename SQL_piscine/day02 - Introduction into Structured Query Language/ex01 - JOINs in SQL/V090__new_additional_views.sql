CREATE VIEW v_country_indicator AS
	SELECT 
		c.name AS country_name, 
		i.name AS indicator_name, 
		ci.value AS value, 
		ci.actual_date AS actual_date
	FROM
		country_indicator ci
	INNER JOIN 
		indicator i
	ON 
		ci.i_id = i.id
	INNER JOIN
		country c
	ON ci.c_id = c.id
	AND c.par_id IS NOT NULL
	ORDER BY 
		country_name,
		indicator_name,
		actual_date DESC;


CREATE VIEW v_continent_country AS
	SELECT
		c.name AS continent_name, 
		c1.name AS country_name
	FROM
		country c 
	INNER JOIN
		country c1
	ON c.id = c1.par_id
	ORDER BY 
		continent_name,
		country_name;


CREATE VIEW v_check_country_01_05_2020_COVID AS
	SELECT *
	FROM
		(SELECT
			c.name AS name, 
			ci.value AS value
		FROM
			country c
		LEFT JOIN
			country_indicator ci
		ON ci.c_id = c.id
		AND ci.i_id = (SELECT id FROM indicator WHERE name = 'Infected humans COVID-19')
		AND ci.actual_date = '2020-05-01'::date) t1
	WHERE value is null;
	

CREATE OR REPLACE VIEW v_average_humans_per_country AS
	SELECT 
		c.name,
		round((ci.value/ci1.value)::numeric, 3) AS value
	FROM 
		country c
	LEFT JOIN 
		country_indicator ci 
	ON ci.c_id = c.id
	AND actual_date = '2019-05-01'::date
	AND ci.i_id = (SELECT id from indicator WHERE name = 'Population of country')
	INNER JOIN 
		country_indicator ci1
	ON ci1.c_id = c.id
	AND ci1.actual_date = '2020-05-01'::date 
	AND ci1.i_id = (SELECT id from indicator WHERE name = 'Area of the land')
	ORDER BY 1;


	
	