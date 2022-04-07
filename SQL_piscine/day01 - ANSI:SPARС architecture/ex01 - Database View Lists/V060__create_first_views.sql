CREATE VIEW v_dictionary_unit AS
	SELECT 
		id,
		value
	FROM 
		dictionary d 
	WHERE d.dic_name = 'unit' 
	AND current_timestamp BETWEEN d.time_start AND d.time_end 
	ORDER BY d.order_num;


CREATE VIEW v_dictionary_land AS
	SELECT 
		id, 
		value 
	FROM 
		dictionary d 
	WHERE d.dic_name = 'land' 
	AND current_timestamp BETWEEN d.time_start AND d.time_end 
	ORDER BY d.order_num;


