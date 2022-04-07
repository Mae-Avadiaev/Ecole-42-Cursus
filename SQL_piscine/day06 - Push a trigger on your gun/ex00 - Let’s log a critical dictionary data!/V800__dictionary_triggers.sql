CREATE TABLE dictionary_history
	(id	SERIAL,
	time_modified TIMESTAMP NOT NULL DEFAULT current_timestamp,
	action_type	CHAR(1) NOT NULL,
	user_modified VARCHAR(50) NOT NULL,
	row_id BIGINT NOT NULL,
	dic_name VARCHAR NOT NULL,
	value VARCHAR NOT NULL,
	order_num INTEGER NOT NULL,
	time_start TIMESTAMP NOT NULL,
	time_end TIMESTAMP NOT NULL,

	CONSTRAINT pk_dictionary_history_id PRIMARY KEY (id),
	CONSTRAINT ch_dictionary_history_action_type CHECK (action_type IN ('I', 'U', 'D'))
	);

CREATE OR REPLACE FUNCTION change_dictionary()
	RETURNS TRIGGER
	AS
		$$
		BEGIN
			IF (TG_OP = 'DELETE') THEN
	            INSERT INTO dictionary_history 
	            	(time_modified, action_type, user_modified, row_id, 
	            	dic_name, value, order_num, time_start, time_end)
	            	SELECT
	            		now(),
	            		'D', 
	            		user, 
	            		OLD.id,
	            		OLD.dic_name,
	            		OLD.value,
	            		OLD.order_num,
	            		OLD.time_start,
	            		OLD.time_end;
	        ELSIF (TG_OP = 'UPDATE') THEN
	            INSERT INTO dictionary_history 
	            	(time_modified, action_type, user_modified, row_id, 
	            	dic_name, value, order_num, time_start, time_end)
	            	SELECT
	            		now(),
	            		'U', 
	            		user, 
	            		NEW.id,
	            		NEW.dic_name,
	            		NEW.value,
	            		NEW.order_num,
	            		NEW.time_start,
	            		NEW.time_end;
	        ELSIF (TG_OP = 'INSERT') THEN
	            INSERT INTO dictionary_history
	            	(time_modified, action_type, user_modified, row_id, 
	            	dic_name, value, order_num, time_start, time_end)
	            	SELECT
	            		now(),
	            		'I', 
	            		user, 
	            		NEW.id,
	            		NEW.dic_name,
	            		NEW.value,
	            		NEW.order_num,
	            		NEW.time_start,
	            		NEW.time_end;
	        END IF;
	        RETURN NULL;
		END;
		$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_change_dictionary 
	AFTER INSERT OR UPDATE OR DELETE
	ON dictionary
	FOR EACH ROW
	EXECUTE PROCEDURE
		change_dictionary();

