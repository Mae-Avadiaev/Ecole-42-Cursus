CREATE OR REPLACE VIEW  v_get_data_distribution AS
	SELECT 
		relname AS "Table Name",
		n_live_tup AS "Amount of Rows"
	  FROM pg_stat_user_tables 
	  ORDER BY (substring(relname, 4))::int ASC;