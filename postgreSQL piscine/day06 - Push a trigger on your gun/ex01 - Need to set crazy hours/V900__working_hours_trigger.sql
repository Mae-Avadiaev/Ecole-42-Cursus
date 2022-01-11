CREATE OR REPLACE FUNCTION fnc_trg_dictionary_check_working_hours()
	RETURNS TRIGGER
	AS
		$$
		BEGIN
			IF (current_time NOT BETWEEN '00:00:00'::time AND '23:59:00'::time) THEN
				IF (TG_OP = 'DELETE') THEN
					RETURN OLD;
				END IF;
				RETURN NEW;
			END IF;
			RAISE EXCEPTION 'Changing data is impossible! You have 1 second at midnight to make a change!';
			RETURN NULL;
		END;
		$$ LANGUAGE plpgsql;


CREATE TRIGGER trg_dictionary_check_working_hours
	BEFORE INSERT OR UPDATE OR DELETE
	ON dictionary
	FOR EACH ROW
	EXECUTE PROCEDURE
		fnc_trg_dictionary_check_working_hours();