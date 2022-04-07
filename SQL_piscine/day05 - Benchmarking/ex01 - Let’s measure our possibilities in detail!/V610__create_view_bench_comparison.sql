CREATE VIEW v_compare_test_results AS
	SELECT
		'v_country_indicator_original' AS "Object Name",	
		max(t1.time) AS "Maximum time",
		min(t1.time) AS "Minimum time",	
		avg(t1.time) AS "Average time"
	FROM 
		test00_01_1 t1
	UNION
	SELECT
		'country_indicator' AS "Object Name",	
		max(t2.time) AS "Maximum time",
		min(t2.time) AS "Minimum time",	
		avg(t2.time) AS "Average time"
	FROM
		test00_01_2 t2