DELETE FROM country_indicator 
	WHERE i_id = (SELECT id FROM indicator WHERE name = 'Unemployment rate')
	AND (actual_date = '2019-01-01'::date
	OR actual_date = '2019-11-01'::date);


UPDATE country_indicator ci
	SET value = value + 100
	FROM country c
	WHERE c.id = ci.c_id
	AND c.par_id = (SELECT id FROM country WHERE name = 'Asia');