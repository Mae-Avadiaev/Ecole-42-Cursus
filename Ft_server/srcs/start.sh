ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/
rm /etc/nginx/sites-enabled/default

chown -R www-data /var/www/*
chmod -R 755 /var/www/*

service nginx start
service mysql start
service php7.3-fpm start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

bash