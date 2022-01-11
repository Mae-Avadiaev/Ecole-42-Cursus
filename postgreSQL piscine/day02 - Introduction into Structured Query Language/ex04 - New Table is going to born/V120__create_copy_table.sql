CREATE TABLE country_north_america (
	LIKE country INCLUDING ALL
);

INSERT INTO country_north_america
	SELECT *
	FROM country
	WHERE par_id = (SELECT id FROM country WHERE name = 'North America');