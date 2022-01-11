--Hello and welcome to our script!
--Let's go!

--Creating
DROP TABLE IF EXISTS indicator CASCADE;
CREATE TABLE indicator (
	id bigint NOT NULL,
	name varchar NOT NULL,
	unit varchar NOT NULL,
	CONSTRAINT pk_indicator PRIMARY KEY (id),
	CONSTRAINT uk_indicator_name UNIQUE (name),
	CONSTRAINT uk_indicator_id UNIQUE (id)
);

DROP TABLE IF EXISTS country CASCADE; 
CREATE TABLE country (
	id bigint NOT NULL,
	name varchar  NOT NULL,
	par_id bigint,
	object_type varchar DEFAULT 'country' NOT NULL,
	CONSTRAINT pk_country PRIMARY KEY (id),
	CONSTRAINT uk_country_name_object_type UNIQUE (name, object_type),
	CONSTRAINT uk_country_id UNIQUE (id)
);

DROP TABLE IF EXISTS country_indicator CASCADE;
CREATE TABLE country_indicator (
	id bigint NOT NULL,
	c_id bigint NOT NULL, 
	i_id bigint NOT NULL,
	value numeric,
	actual_date timestamp default current_timestamp NOT NULL,
	CONSTRAINT pk_country_indicator PRIMARY KEY (id),
	CONSTRAINT uk_country_indicator_c_id_i_id_actual_date UNIQUE (c_id, i_id, actual_date),
	CONSTRAINT uk_country_indicator_id UNIQUE (id)
);

ALTER TABLE country_indicator 
	ADD CONSTRAINT fk_c_id_country FOREIGN KEY (c_id) REFERENCES country (id),
	ADD CONSTRAINT fk_i_id_country FOREIGN KEY (i_id) REFERENCES indicator (id);
	
ALTER TABLE country
	ADD CONSTRAINT fk_par_id_country FOREIGN KEY (par_id) REFERENCES country (id)
