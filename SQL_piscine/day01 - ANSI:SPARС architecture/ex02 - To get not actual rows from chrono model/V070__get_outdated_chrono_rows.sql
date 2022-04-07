CREATE VIEW v_outdated_indicator AS
	SELECT 
        id, 
        name, 
        time_start, 
        time_end 
    FROM 
        indicator i 
    WHERE current_timestamp NOT BETWEEN i.time_start and i.time_end 
    ORDER BY i.id DESC;


CREATE VIEW v_outdated_country AS
	SELECT 
        id, 
        name, 
        time_start, 
        time_end 
    FROM 
        country c 
    WHERE current_timestamp NOT BETWEEN c.time_start and c.time_end 
    ORDER BY c.id DESC;


CREATE VIEW v_outdated_dictionary AS
	SELECT 
        id, 
        dic_name, 
        value, 
        time_start, 
        time_end 
    FROM 
        dictionary d 
    WHERE current_timestamp NOT BETWEEN d.time_start and d.time_end 
    ORDER BY d.id DESC;


INSERT INTO country_indicator 
    (c_id, i_id, value, actual_date)
	SELECT 
        c.id, 
        i.id, 
        cast(random() * 1000000 + 10000 AS integer), 
        '2020-05-01'::date
    FROM 
        country c, 
        indicator i 
    WHERE c.object_type_id = (SELECT id FROM dictionary d WHERE d.value = 'country') 
    AND i.name = 'Area of the land';


DROP VIEW IF EXISTS v_average_humans_per_country;
CREATE VIEW v_average_humans_per_country AS
    SELECT 
        t1.name, 
        round( (t1.population / t1.area), 3) AS value 
    FROM 
        (SELECT 
            name,
                (SELECT value 
                 FROM country_indicator ci 
                 WHERE ci.c_id = c.id 
                 AND ci.actual_date='2020-05-01'::date 
                 AND ci.i_id = (SELECT id from indicator WHERE name = 'Area of the land')) 
            AS area,  
                (SELECT value 
                 FROM country_indicator ci 
                 WHERE ci.c_id = c.id 
                 AND ci.actual_date='2019-05-01'::date 
                 AND ci.i_id = (SELECT id from indicator WHERE name = 'Population of country')) 
            AS population  
        FROM country c
        WHERE c.par_id is not null) AS t1 
    ORDER BY 1;