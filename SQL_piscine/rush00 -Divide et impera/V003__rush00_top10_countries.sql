CREATE OR REPLACE FUNCTION cr_v_mask_union(t_name text, t_base text)
	RETURNS void
	LANGUAGE plpgsql
	AS
	$$
		BEGIN
			EXECUTE (
				SELECT 
					'CREATE OR REPLACE VIEW ' || t_name || ' AS 
						SELECT 
							"Country",
							SUM("Amount of Transactions") AS "Amount of Transactions"
						FROM 
							(SELECT 
								country_tx AS "Country",
								count(internaltxnumber) AS "Amount of Transactions"
							FROM ' 
								  || string_agg(quote_ident(relname), ' 
							GROUP BY "Country"
							UNION ALL 
							SELECT 
								country_tx AS "Country",
								count(internaltxnumber) AS "Amount of Transactions"
							FROM ') || ' 
							GROUP BY "Country") AS t_data' || '
						GROUP BY "Country";'
				FROM 
					pg_stat_user_tables
				WHERE relname LIKE (t_base || '%'));
		END 
	$$;

	
SELECT * FROM cr_v_mask_union('v_get_top10_tx_countries', 'tx_');