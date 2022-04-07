\set initialize_random_for_id random(1, 1000000)

BEGIN;

	SELECT * 
	FROM country_indicator
	WHERE id = :initialize_random_for_id;

END;