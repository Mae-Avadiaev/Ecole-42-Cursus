ln -s /etc/nginx/sites-available/nginx_autoindex.conf /etc/nginx/sites-enabled/
rm /etc/nginx/sites-enabled/nginx.conf

service nginx restart