CREATE VIEW v_intervals_distribution AS
	WITH CTE_intervals_1 AS
	(SELECT
		min(t1.time) AS min_inter_1,
		(min(t1.time) + (avg(t1.time) - min(t1.time)) / 2)::int AS first_inter_1,
		(avg(t1.time) + (max(t1.time) - avg(t1.time)) / 2)::int AS second_inter_1,
		max(t1.time) AS max_inter_1,
		count(*) AS total_rows_1
	FROM
		test00_01_1 t1
	WHERE client_id = 9
	GROUP BY t1.script_no),
	
	CTE_intervals_2 AS
	(SELECT
		min(t2.time) AS min_inter_2,
		(min(t2.time) + (avg(t2.time) - min(t2.time)) / 2)::int AS first_inter_2,
		(avg(t2.time) + (max(t2.time) - avg(t2.time)) / 2)::int AS second_inter_2,
		max(t2.time) AS max_inter_2,
		count(*) AS total_rows_2
	FROM
		test00_01_2 t2
	WHERE client_id = 9
	GROUP BY t2.script_no)

	SELECT *
	FROM
		(SELECT 
			'test00_01_1' AS "Table Name",	
			'[' || i.min_inter_1 || ', ' || i.first_inter_1 || ')' AS "Interval",
			count(t1.time) AS "Amount of Rows",
			repeat('|', ceil((count(*) * 100) / i.total_rows_1)::int) AS "Histogram",
			ceil((count(*) * 100) / i.total_rows_1) AS "Percent"
		FROM
			CTE_intervals_1 i,
			test00_01_1 t1
		WHERE t1.time >= i.min_inter_1
		AND t1.time < i.first_inter_1
		AND client_id = 9
		GROUP BY i.min_inter_1, i.first_inter_1, i.total_rows_1
		UNION 
		SELECT 
			'test00_01_1' AS "Table Name",	
			'[' || i.first_inter_1 || ', ' || i.second_inter_1 || ')' AS "Interval",
			count(t1.time) AS "Amount of Rows",
			repeat('|', ceil((count(*) * 100) / i.total_rows_1)::int) AS "Histogram",
			ceil((count(*) * 100) / i.total_rows_1) AS "Percent"
		FROM
			CTE_intervals_1 i,
			test00_01_1 t1
		WHERE t1.time >= i.first_inter_1
		AND t1.time < i.second_inter_1
		AND client_id = 9
		GROUP BY i.first_inter_1, i.second_inter_1, i.total_rows_1
		UNION
		SELECT 
			'test00_01_1' AS "Table Name",	
			'[' || i.second_inter_1 || ', ' || i.max_inter_1 || ']' AS "Interval",
			count(t1.time) AS "Amount of Rows",
			repeat('|', ceil((count(*) * 100)::double precision / i.total_rows_1)::int) AS "Histogram",
			ceil((count(*) * 100)::double precision / i.total_rows_1) AS "Percent"
		FROM
			CTE_intervals_1 i,
			test00_01_1 t1
		WHERE t1.time >= i.second_inter_1
		AND t1.time <= i.max_inter_1
		AND client_id = 9
		GROUP BY i.max_inter_1, i.second_inter_1, i.total_rows_1
		
		UNION 
		
		SELECT 
			'test00_01_2' AS "Table Name",	
			'[' || i.min_inter_2 || ', ' || i.first_inter_2 || ')' AS "Interval",
			count(t2.time) AS "Amount of Rows",
			repeat('|', ceil((count(*) * 100) / i.total_rows_2)::int) AS "Histogram",
			ceil((count(*) * 100) / i.total_rows_2) AS "Percent"
		FROM
			CTE_intervals_2 i,
			test00_01_2 t2
		WHERE t2.time >= i.min_inter_2
		AND t2.time < i.first_inter_2
		AND client_id = 9
		GROUP BY i.min_inter_2, i.first_inter_2, i.total_rows_2
		UNION 
		SELECT 
			'test00_01_2' AS "Table Name",	
			'[' || i.first_inter_2 || ', ' || i.second_inter_2 || ')' AS "Interval",
			count(t2.time) AS "Amount of Rows",
			repeat('|', ceil((count(*) * 100) / i.total_rows_2)::int) AS "Histogram",
			ceil((count(*) * 100) / i.total_rows_2) AS "Percent"
		FROM
			CTE_intervals_2 i,
			test00_01_2 t2
		WHERE t2.time >= i.first_inter_2
		AND t2.time < i.second_inter_2
		AND client_id = 9
		GROUP BY i.first_inter_2, i.second_inter_2, i.total_rows_2
		UNION
		SELECT 
			'test00_01_2' AS "Table Name",	
			'[' || i.second_inter_2 || ', ' || i.max_inter_2 || ']' AS "Interval",
			count(t2.time) AS "Amount of Rows",
			repeat('|', ceil((count(*) * 100)::double precision / i.total_rows_2)::int) AS "Histogram",
			ceil((count(*) * 100)::double precision / i.total_rows_2) AS "Percent"
		FROM
			CTE_intervals_2 i,
			test00_01_2 t2
		WHERE t2.time >= i.second_inter_2
		AND t2.time <= i.max_inter_2
		AND client_id = 9
		GROUP BY i.max_inter_2, i.second_inter_2, i.total_rows_2) AS "data"
	ORDER BY 1, 2;
