
DROP TABLE IF EXISTS dictionary;
CREATE TABLE dictionary (
	id bigint NOT NULL,
	time_start timestamp NOT NULL DEFAULT '1972.01.01'::timestamp,
	time_end timestamp NOT NULL DEFAULT '9999.01.01'::timestamp,
	dic_name varchar,
	value varchar,
	order_num bigint NOT NULL DEFAULT 0,
	CONSTRAINT pk_dictionary PRIMARY KEY (id),
	CONSTRAINT uk_dictionary_dic_name_value UNIQUE (dic_name, value)
);


INSERT INTO dictionary 
	(id, dic_name, value, order_num)
	SELECT
		row_number() OVER(),
		'unit', unit, 
		row_number() over () - 1 
	FROM 
		indicator 
	GROUP BY unit; 


INSERT INTO dictionary 
	(id, dic_name, value, order_num)
	SELECT 
		row_number() OVER() + (SELECT MAX(id) FROM dictionary),
		'land', 
		object_type, 
		row_number() over () - 1 
	FROM 
		country 
	GROUP BY object_type;


INSERT INTO dictionary 
	(id, dic_name, value, order_num)
	SELECT  
		row_number() OVER() + (SELECT MAX(id) from dictionary),
		'unit', 
		'square kilometer', 
		row_number() over () + (SELECT MAX(order_num) 
	FROM dictionary); 


ALTER TABLE indicator
	DROP CONSTRAINT ch_indicator_unit;
	UPDATE indicator i
		SET unit = (SELECT id FROM dictionary d WHERE d.dic_name = 'unit' AND i.unit = d.value);


ALTER TABLE indicator
	ALTER COLUMN unit TYPE bigint USING unit::bigint;


ALTER TABLE indicator
	RENAME COLUMN unit TO unit_id;


ALTER TABLE indicator
	ADD CONSTRAINT fk_id_dictionary FOREIGN KEY (unit_id) REFERENCES dictionary (id) ON DELETE RESTRICT ON UPDATE RESTRICT;


INSERT INTO indicator 
	(id, name, unit_id)
	SELECT 
		row_number() OVER () + (SELECT MAX(id) FROM indicator), 
		'Area of the land', 
		(SELECT id FROM dictionary WHERE value = 'square kilometer');


ALTER TABLE country 
	DROP CONSTRAINT ch_country_object_type;


ALTER TABLE country
	ALTER COLUMN object_type DROP DEFAULT;


UPDATE country c
	SET object_type = (SELECT id FROM dictionary d WHERE d.dic_name = 'land' AND c.object_type = d.value);


ALTER TABLE country
	ALTER COLUMN object_type TYPE bigint USING object_type::bigint;


ALTER TABLE country
	RENAME COLUMN object_type TO object_type_id;


ALTER TABLE country
	ADD CONSTRAINT fk_id_dictionary FOREIGN KEY (object_type_id) REFERENCES dictionary (id) ON DELETE RESTRICT ON UPDATE RESTRICT;