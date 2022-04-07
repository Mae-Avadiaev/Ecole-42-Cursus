CREATE VIEW v_dictionary AS
	SELECT * 
	FROM 
		v_dictionary_unit
	UNION
	SELECT * 
	FROM 
		v_dictionary_land
	ORDER BY value ASC; 


CREATE VIEW v_dictionary_all AS
	SELECT 
		id, 
		dic_name, 
		value
	FROM 
		dictionary
	ORDER BY 
		dic_name ASC, 
		value ASC; 


CREATE VIEW v_dictionary_minus AS
	SELECT 
		id, 
		dic_name, 
		value 
	FROM 
		v_dictionary_all
	EXCEPT 
	SELECT 
		id, 
		'land', 
		value 
	FROM 
		v_dictionary_land;


CREATE VIEW v_dictionary_intersect AS
	SELECT 
		id, 
		dic_name, 
		value 
	FROM 
		v_dictionary_all
	INTERSECT 
	SELECT 
		id, 
		'land', 
		value 
	FROM 
		v_dictionary_land
	INTERSECT
	SELECT 
		id, 
		'unit', 
		value 
	FROM 
		v_dictionary_unit;

CREATE VIEW	v_dictionary_symmetric_minus AS
	(SELECT *
	FROM
		v_dictionary_all
	UNION
	SELECT 
		id, 
		'land', 
		value
	FROM
		v_dictionary_land
	)
	EXCEPT
	(SELECT *
	FROM
		v_dictionary_all
	INTERSECT
	SELECT 
		id,
		'land',
		value
	FROM
		v_dictionary_land);
	