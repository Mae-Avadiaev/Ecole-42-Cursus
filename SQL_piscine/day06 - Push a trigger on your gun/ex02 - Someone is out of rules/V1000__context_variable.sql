CREATE OR REPLACE FUNCTION fnc_trg_dictionary_check_working_hours()
	RETURNS TRIGGER
	AS
		$$
		BEGIN
			IF (current_setting('aliens.pass') IS DISTINCT FROM 'SECRET') THEN
				IF (TG_OP = 'DELETE') THEN
					RETURN OLD;
				END IF;
				RETURN NEW;
			END IF;
			RAISE EXCEPTION 'Changing data is impossible! You have 1 second at midnight to make a change!';
			RETURN NULL;
		END;
		$$ LANGUAGE plpgsql;
