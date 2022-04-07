CREATE VIEW v_test00_01_1 AS
	SELECT 
		t1.time
	FROM
		test00_01_1 t1
	WHERE client_id = 5
	ORDER BY 
		time_us,
		transaction_no;

CREATE VIEW v_test00_01_2 AS
	SELECT 
		t2.time
	FROM
		test00_01_2 t2
	WHERE client_id = 5
	ORDER BY 
		time_us,
		transaction_no;