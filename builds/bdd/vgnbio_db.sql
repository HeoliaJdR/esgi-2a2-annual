CREATE DATABASE vgnbio_db char set UTF-8;

CREATE TABLE restaurant(
  restaurant_id int auto_increment,
  restaurant_address varchar(255),
  restaurant_city varchar(65),
  restaurant_postal varchar(11),
  restaurant_phone varchar(12)
);

CREATE TABLE salaries (
  salaries_id int auto_increment,
  salaries_email varchar(255),
  salaries_password char(60),
  salaries_firstname varchar(50),
  salaries_lastname varchar(50),
  salaries_phone varchar(12), /*ex : +33 6 66 66 66 66*/
  salaries_address varchar(255),
  salaries_city varchar(65),
  salaries_postal varchar(11),
  salaries_recrutement_date date,
  salaries_fire_date date,
  salaries_active boolean, # 0 if enable, 1 if disable
  salaries_location_id int REFERENCES restaurant(restaurant_id);
  PRIMARY KEY(salaries_id, salaries_email)
);
