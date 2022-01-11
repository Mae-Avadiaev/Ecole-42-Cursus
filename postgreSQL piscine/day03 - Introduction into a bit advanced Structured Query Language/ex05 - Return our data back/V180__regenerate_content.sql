TRUNCATE country_indicator; -- full cleanup of country_indicator table

INSERT INTO country_indicator 
	(c_id, i_id, value, actual_date)
	WITH RECURSIVE CTE_gen_data AS
		(SELECT 
			c.id AS c_id, 
			i.id AS i_id, 
			(random() * 1000000)::int AS value, 
			'2019-01-01'::date AS actual_date
		FROM
			country c,
			indicator i
		WHERE c.object_type_id != (SELECT id FROM dictionary WHERE value = 'continent')
		AND i.name = 'Population of country'
		UNION 
		SELECT 
			CTE_gen_data.c_id AS c_id, 
			CTE_gen_data.i_id AS i_id, 
			(random() * 1000000)::int AS value, 
			(CTE_gen_data.actual_date + '1 month'::interval)::date AS actual_date
		FROM
			CTE_gen_data
		WHERE (CTE_gen_data.actual_date + '1 month'::interval)::date  <= '2019-12-31'::date)
	
	SELECT *
	FROM CTE_gen_data
	ORDER BY 
		CTE_gen_data.c_id,
		actual_date;


INSERT INTO country_indicator 
	(c_id, i_id, value, actual_date)
	WITH RECURSIVE CTE_gen_data AS
		(SELECT 
			c.id AS c_id, 
			i.id AS i_id, 
			(random() * 100)::int AS value, 
			'2019-01-01'::date AS actual_date
		FROM
			country c,
			indicator i
		WHERE c.object_type_id != (SELECT id FROM dictionary WHERE value = 'continent')
		AND i.name = 'Unemployment rate'
		UNION 
		SELECT 
			CTE_gen_data.c_id AS c_id, 
			CTE_gen_data.i_id AS i_id, 
			(random() * 100)::int AS value, 
			(CTE_gen_data.actual_date + '1 month'::interval)::date AS actual_date
		FROM
			CTE_gen_data
		WHERE (CTE_gen_data.actual_date + '1 month'::interval)::date  <= '2019-12-31'::date)
	
	SELECT *
	FROM CTE_gen_data
	ORDER BY 
		CTE_gen_data.c_id,
		actual_date;


INSERT INTO country_indicator 
	(c_id, i_id, value, actual_date)
	WITH RECURSIVE CTE_gen_data AS
		(SELECT 
			c.id AS c_id, 
			i.id AS i_id, 
			(random() * 50)::int AS value, 
			'2020-05-01'::date AS actual_date
		FROM
			country c,
			indicator i
		WHERE c.object_type_id != (SELECT id FROM dictionary WHERE value = 'continent')
		AND i.name = 'Infected humans COVID-19'
		UNION 
		SELECT 
			CTE_gen_data.c_id AS c_id, 
			CTE_gen_data.i_id AS i_id, 
			(random() * 50)::int AS value, 
			(CTE_gen_data.actual_date + '1 day'::interval)::date AS actual_date
		FROM
			CTE_gen_data
		WHERE (CTE_gen_data.actual_date + '1 day'::interval)::date  <= '2020-08-31'::date)
	
	SELECT *
	FROM CTE_gen_data
	ORDER BY 
		CTE_gen_data.c_id,
		actual_date;


INSERT INTO country_indicator 
	(c_id, i_id, value, actual_date)
	WITH CTE_gen_data AS
		(SELECT 
			c.id AS c_id, 
			i.id AS i_id, 
			(random() * 9990000 + 10000)::int AS value, 
			'2020-05-01'::date AS actual_date
		FROM
			country c,
			indicator i
		WHERE c.object_type_id != (SELECT id FROM dictionary WHERE value = 'continent')
		AND i.name = 'Area of the land')
	
	SELECT *
	FROM CTE_gen_data
	ORDER BY 
		CTE_gen_data.c_id,
		actual_date;