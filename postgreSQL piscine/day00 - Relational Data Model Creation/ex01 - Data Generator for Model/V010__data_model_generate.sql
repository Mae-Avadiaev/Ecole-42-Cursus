INSERT INTO country_indicator
	(SELECT 
		row_number() OVER() id, 
		c.id c_id, 
		i.id i_id, 
		(random() * 1000000)::int AS value, 
		d_data.inter_date actual_date
	FROM
		country c, 
		indicator i
	CROSS JOIN
		(SELECT 
			inter_date::date FROM generate_series(
				'2019-01-01'::date,
				'2019-12-31'::date,
				'1 month'::interval
			) inter_date) 
		AS d_data
	WHERE 
		i.name='Population of country'
		AND c.object_type='country'
	ORDER BY 
		c_id);


INSERT INTO country_indicator
	(SELECT 
		(row_number() OVER() + (SELECT MAX(id) FROM country_indicator)) id, 
		c.id c_id, 
		i.id i_id, 
		(random() * 100)::int AS value, 
		d_data.inter_date actual_date
	FROM
		country c, 
		indicator i
	CROSS JOIN
		(SELECT 
		inter_date::date FROM generate_series(
			'2019-01-01'::date,
			'2019-12-31'::date,
			'1 month'::interval
		) inter_date) AS d_data
	WHERE 
		i.name='Unemployment rate'
		AND c.object_type='country'
	ORDER BY c_id);


INSERT INTO country_indicator
	(SELECT 
		(row_number() OVER() + (SELECT MAX(id) FROM country_indicator)) id,
		c.id c_id, 
		i.id i_id, 
		(random() * 50)::int AS value, 
		d_data.inter_date actual_date
	FROM
		country c, 
		indicator i
	CROSS JOIN
		(SELECT 
			inter_date::date FROM generate_series(
				'2020-05-01'::date,
				'2020-08-31'::date,
				'1 day'::interval
			) inter_date) 
		AS d_data
	WHERE 
		i.name='Infected humans COVID-19'
		AND c.object_type='country'
	ORDER BY c_id);