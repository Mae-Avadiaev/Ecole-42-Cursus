CREATE VIEW v_country_groupped AS
	SELECT
		continent_name,
		count(country_name) AS cnt
	FROM
		v_continent_country
	GROUP BY 
		continent_name
	ORDER BY
		continent_name;


CREATE VIEW v_country_groupped_having_50 AS
	SELECT
		continent_name,
		count(country_name) AS cnt
	FROM
		v_continent_country
	GROUP BY 
		continent_name
	HAVING
		count(country_name) > 50
	ORDER BY
		continent_name;


CREATE VIEW v_country_name_duplicates AS
	SELECT
		c.name country_name
	FROM
		country c
	GROUP BY 
		c.name
	HAVING
		count(c.name) > 1;


