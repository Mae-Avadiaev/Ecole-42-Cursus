CREATE MATERIALIZED VIEW mv_country_indicator_infected_humans_covid AS
	SELECT *
	FROM 
		v_country_indicator_infected_humans_covid
	WITH NO DATA;
