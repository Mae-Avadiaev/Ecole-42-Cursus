CREATE SEQUENCE IF NOT EXISTS id_indicator_seq INCREMENT BY 10 
	OWNED BY indicator.id;
CREATE SEQUENCE IF NOT EXISTS id_country_seq INCREMENT BY 10 
	OWNED BY country.id;
CREATE SEQUENCE IF NOT EXISTS id_country_indicator_seq INCREMENT BY 10 
	OWNED BY country_indicator.id;


SELECT setval('id_indicator_seq', max(i.id)) FROM indicator i;
ALTER TABLE indicator
	ALTER COLUMN id SET DEFAULT nextval('id_indicator_seq');


SELECT setval('id_country_seq', max(c.id)) FROM country c;
ALTER TABLE country
	ALTER COLUMN id SET DEFAULT nextval('id_country_seq'); 

SELECT setval('id_country_indicator_seq', max(ci.id)) FROM country_indicator ci;
ALTER TABLE country_indicator
	ALTER COLUMN id SET DEFAULT nextval('id_country_indicator_seq');