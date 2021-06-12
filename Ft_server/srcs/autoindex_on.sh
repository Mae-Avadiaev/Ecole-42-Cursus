ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/
rm /etc/nginx/sites-enabled/nginx_autoindex.conf

service nginx restart