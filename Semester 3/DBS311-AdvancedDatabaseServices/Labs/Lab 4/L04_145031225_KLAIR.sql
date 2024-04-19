-- ***********************
-- Name: Sampreet Klair
-- ID: 145031225
-- Date: 2nd February, 2024
-- Purpose: Lab 04 DBS311
-- ***********************

-- Q1 Solution --
SELECT last_name, TO_CHAR(hire_date,'DD-MON-YY') as HIRE_DATE
FROM employees
WHERE hire_date < (SELECT hire_date FROM employees WHERE employee_id = 107)
AND hire_date > TO_DATE('2016-03-31', 'YYYY-MM-DD')
ORDER BY hire_date, employee_id;

-- Q2 Solution --
SELECT name, credit_limit
FROM customers
WHERE credit_limit = (SELECT MIN(credit_limit) FROM customers)
ORDER BY customer_id;

-- Q3 Solution --
SELECT category_id, product_id, product_name, list_price
FROM products
WHERE (category_id, list_price) IN (SELECT category_id, MAX(list_price)
FROM products
GROUP BY category_id)
ORDER BY category_id, product_id;

-- Q4 Solution --
SELECT category_id, category_name
FROM product_categories
WHERE category_id = (SELECT category_id FROM products WHERE list_price = (SELECT MAX(list_price) 
FROM products));

-- Q5 Solution --
SELECT product_name, list_price
FROM products
WHERE category_id = 1
AND list_price < (SELECT MIN(list_price) FROM products)
ORDER BY list_price DESC, product_id;

-- Q6 Solution --
SELECT MAX(list_price)
FROM products
WHERE category_id = (SELECT category_id
FROM products
WHERE list_price = (SELECT MIN(list_price) FROM products));

-- Q1 Solution --
SELECT last_name, TO_CHAR(hire_date,'DD-MON-YY') as HIRE_DATE
FROM employees
WHERE hire_date < (SELECT hire_date FROM employees WHERE employee_id = 107)
AND hire_date > TO_DATE('2016-03-31', 'YYYY-MM-DD')
ORDER BY hire_date, employee_id;

-- Q2 Solution --
SELECT name, credit_limit
FROM customers
WHERE credit_limit = (SELECT MIN(credit_limit) FROM customers)
ORDER BY customer_id;

-- Q3 Solution --
SELECT category_id, product_id, product_name, list_price
FROM products
WHERE (category_id, list_price) IN (SELECT category_id, MAX(list_price)
FROM products
GROUP BY category_id)
ORDER BY category_id, product_id;

-- Q4 Solution --
SELECT category_id, category_name
FROM product_categories
WHERE category_id = (SELECT category_id FROM products WHERE list_price = (SELECT MAX(list_price) 
FROM products));

-- Q5 Solution --
SELECT product_name, list_price
FROM products
WHERE category_id = 1
AND list_price < (SELECT MIN(list_price) FROM products)
ORDER BY list_price DESC, product_id;

-- Q6 Solution --
SELECT MAX(list_price)
FROM products
WHERE category_id = (SELECT category_id
FROM products
WHERE list_price = (SELECT MIN(list_price) FROM products));