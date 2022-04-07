ALTER TABLE indicator
	ADD CONSTRAINT ch_indicator_time_start CHECK (time_start >= '1972.01.01'::timestamp), 
	ADD CONSTRAINT ch_indicator_time_end CHECK (time_end <= '9999.01.01'::timestamp),
	ADD CONSTRAINT ch_indicator_unit CHECK (unit in ('human', 'percent'));
	
ALTER TABLE country
	ADD CONSTRAINT ch_country_time_start CHECK (time_start >= '1972.01.01'::timestamp), 
	ADD CONSTRAINT ch_country_time_end CHECK (time_end <= '9999.01.01'::timestamp),
	ADD CONSTRAINT ch_country_object_type CHECK (object_type in ('country', 'continent'));

ALTER TABLE country_indicator
	ADD CONSTRAINT ch_country_indicator_value CHECK (value >= 0);

ALTER TABLE country_indicator
	ALTER COLUMN value SET NOT NULL;