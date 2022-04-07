CREATE EXTENSION IF NOT EXISTS "uuid-ossp";
CREATE FUNCTION create_table (t_name varchar(3))
	RETURNS VOID 
	LANGUAGE plpgsql
	AS
	$$
		BEGIN
			EXECUTE
				format('
					CREATE TABLE IF NOT EXISTS %I
						(card_number		VARCHAR(19) NOT NULL,
						card_holder			VARCHAR(10) NOT NULL,
						card_type			VARCHAR(50) NOT NULL,
						cardvalidto			DATE NOT NULL,
						card_pin			VARCHAR(3) NOT NULL,
						status_tx			VARCHAR(30) NOT NULL DEFAULT ''PROCESSING'',
						amount_money		NUMERIC(9,2) NOT NULL DEFAULT 0,
						currency_name		VARCHAR(3) NOT NULL,
						country_tx			VARCHAR(3) NOT NULL,
						internaltxnumber	UUID NOT NULL DEFAULT uuid_generate_v4()
				)', 'tx_' || t_name);
		END
	$$;

WITH RECURSIVE CTE_create_tables AS
	(SELECT
		2 AS next_t_name,
		create_table('1'::varchar(3))
	UNION ALL
	SELECT
		ct.next_t_name + 1 AS next_t_name,
		create_table(ct.next_t_name::varchar(3))
	FROM CTE_create_tables ct	
	WHERE ct.next_t_name <= 30)

	SELECT *
	FROM CTE_create_tables;