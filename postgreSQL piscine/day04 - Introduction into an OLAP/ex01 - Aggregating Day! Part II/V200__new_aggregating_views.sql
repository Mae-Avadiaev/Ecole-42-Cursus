CREATE VIEW v_country_indicator_unemployment_rate AS
	SELECT 
		c.name AS name,
		max(ci.value) AS maximum,
		min(ci.value) AS minimum,
		round(avg(ci.value), 2) AS average,
		count(ci.value) AS amount,
		max(ci.value) - min(ci.value) AS range
	FROM
		country c
	INNER JOIN
		country_indicator ci
	ON c.id = ci.c_id
	AND ci.i_id = (SELECT id FROM indicator WHERE name = 'Unemployment rate')
	GROUP BY c.name
	ORDER BY name;


CREATE VIEW v_country_indicator_infected_humans_covid AS
	SELECT
		c.name AS name,
		max(ci.value) AS maximum,
		min(ci.value) AS minimum,
		round(avg(ci.value), 2) AS average,
		count(ci.value) AS amount,
		sum(ci.value) AS total
	FROM 
		country c
	INNER JOIN
		country_indicator ci
	ON c.id = ci.c_id
	AND ci.i_id = (SELECT id FROM indicator WHERE name = 'Infected humans COVID-19')
	GROUP BY c.name
	ORDER BY sum(ci.value) DESC
	LIMIT 10;