FROM debian:buster

EXPOSE 80 80
EXPOSE 443 443

#install utils
RUN apt-get -y update
RUN apt-get -y upgrade
RUN apt-get -y install nginx 
RUN apt-get -y install wget
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring
RUN apt-get -y install mariadb-server

#nginx config
COPY ./srcs/nginx.conf/ /etc/nginx/sites-available


#phpMyAdmin install and config 
WORKDIR /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin

#Wordpress install and config
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
COPY ./srcs/wp-config.php /var/www/html


#making SSL key
RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Moscow/L=Moscow/O=School21/CN=192.168.99.100" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

COPY ./srcs/start.sh ./
COPY ./srcs/autoindex_off.sh ./
COPY ./srcs/autoindex_on.sh ./
COPY ./srcs/nginx_autoindex.conf /etc/nginx/sites-available

CMD bash start.sh