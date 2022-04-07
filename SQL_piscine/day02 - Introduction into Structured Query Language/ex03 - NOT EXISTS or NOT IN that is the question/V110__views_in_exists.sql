/*
NOT EXISTS uses a special access method called hashed Subplan.
Any missing value should be only looked up once.
Table t_right is hashed and the hash table is looked up against all rows from t_left.

Table t_left contains 100,000 rows with 10,000 distinct values.
Table t_right contains 1,000,000 rows with 10,000 distinct values.

The query for t_left and t_right takes 1.10 s.
*/
CREATE VIEW v_missing_indicators_exists AS
	SELECT *
	FROM indicator i
	WHERE NOT EXISTS (SELECT 1 FROM country_indicator ci WHERE i.id = ci.i_id);

/*
NOT IN also uses a special access method called hashed Subplan.
But the difference is the need to look for the values twice.

The query for t_left and t_right takes 1.34 s.
*/
CREATE VIEW v_missing_indicators_in AS
	SELECT *
	FROM indicator i
	WHERE i.id NOT IN (SELECT i_id FROM country_indicator);