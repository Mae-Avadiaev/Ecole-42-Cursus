CREATE VIEW v_check_country_01_05_2020_COVID_cte AS
	WITH CTE_id_indicator_infected_humans_COVID AS
		(SELECT id 
		FROM indicator 
		WHERE name = 'Infected humans COVID-19'),
	CTE_country_indicator_by_id AS
		(SELECT *
		FROM country_indicator
		WHERE i_id = (SELECT * FROM CTE_id_indicator_infected_humans_COVID))
	SELECT *
	FROM
		(SELECT
			c.name AS name, 
			ci.value AS value
		FROM
			country c
		LEFT JOIN
			 CTE_country_indicator_by_id ci
		ON ci.c_id = c.id
		AND ci.actual_date = '2020-05-01'::date) t1
	WHERE value is null;


CREATE VIEW v_check_country_01_05_2020_COVID_check AS
	SELECT 
		v1.name name_cte, 
		v2.name name_previous, 
		(v1.value = v2.value) check_row
	FROM
		v_check_country_01_05_2020_COVID_cte v1
	FULL JOIN
		v_check_country_01_05_2020_COVID v2
	ON v1.name = v2.name
	ORDER BY 
		name_cte NULLS FIRST,
		name_previous NULLS FIRST;