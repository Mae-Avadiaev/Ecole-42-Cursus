INSERT INTO country_indicator
	(c_id, i_id, value, actual_date)
	SELECT	
		c.id,
		i.id,
		31415926,
		'2020-05-01'::date
	FROM
		country c,
		indicator i
	WHERE c.name = 'Austria'
	AND i.name = 'Infected humans COVID-19'
	ON CONFLICT (c_id, i_id, actual_date)
	DO UPDATE
		SET value = EXCLUDED.value;


REFRESH MATERIALIZED VIEW mv_country_indicator_infected_humans_covid;