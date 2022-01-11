ALTER TABLE indicator
	ADD COLUMN time_start timestamp NOT NULL DEFAULT '1972.01.01'::timestamp,
	ADD COLUMN time_end timestamp NOT NULL DEFAULT '9999.01.01'::timestamp;

ALTER TABLE country
	ADD COLUMN time_start timestamp NOT NULL DEFAULT '1972.01.01'::timestamp,
	ADD COLUMN time_end timestamp NOT NULL DEFAULT '9999.01.01'::timestamp;