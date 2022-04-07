\set initialize_random_for_id random(1, 1000000)

BEGIN;

	SELECT * 
	FROM v_country_indicator_original
	WHERE id = :initialize_random_for_id;

END;