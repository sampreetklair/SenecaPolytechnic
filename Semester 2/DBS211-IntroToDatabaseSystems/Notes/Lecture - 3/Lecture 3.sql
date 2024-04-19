/* Order of typing command
SELECT column_list 
FROM source_table_or_view
WHERE filter_condition
GROUP BY grouping_condition
HAVING grouping_filter_condition
ORDER BY sort_order
*/

/* Order of execution of commands
FROM
WHERE
GROUP BY
HAVING
SELECT
ORDER BY
*/

SELECT * 
FROM employee;

-- Sorting columns
SELECT first_name, last_name, phone_number
FROM employee
ORDER BY last_name;

SELECT first_name, last_name, phone_number
FROM employee
ORDER BY last_name ASC;

SELECT first_name, last_name, phone_number
FROM employee
ORDER BY last_name DESC;

SELECT first_name, last_name, phone_number
FROM employee
ORDER BY first_name ASC, last_name ASC;

SELECT first_name, last_name, phone_number
FROM employee
ORDER BY first_name ASC, last_name DESC;

-- Column name alias
SELECT first_name as "First", last_name "Last Name", phone_number "Phone"
FROM employee
ORDER BY first_name ASC, last_name ASC;

-- Concatenating 'only' two columns
SELECT CONCAT((CONCAT(first_name, ' '), last_name)) "Employee Name", phone_number "Phone"
FROM employee
ORDER BY first_name ASC, last_name ASC;

SELECT first_name ||  ' ' || last_name "Employee Name", phone_number "Phone"
FROM employee
ORDER BY first_name ASC, last_name ASC;

-- Removing duplicates
SELECT DISTINCT first_name
FROM employee
ORDER BY first_name ASC;

SELECT DISTINCT first_name, last_name
FROM employee
ORDER BY first_name ASC;

-- WHERE Statement
SELECT country_name, region_id
FROM country
WHERE region_id = 3;

SELECT country_name, region_id
FROM country
WHERE region_id = 3 OR region_id = 2;

SELECT country_name, region_id
FROM country
WHERE region_id = 3 OR region_id = 2
ORDER BY region_id;

SELECT country_name, region_id
FROM country
WHERE region_id = 3 AND region_id = 2
ORDER BY region_id;

-- using LIKE instead of =
SELECT country_name, region_id
FROM country
WHERE country_name LIKE 'A%'
ORDER BY region_id;

SELECT country_name, region_id
FROM country
WHERE country_name LIKE 'A%95\%' -- slashing % character
ORDER BY region_id;

SELECT country_name, region_id
FROM country
WHERE country_name LIKE 'A%'
ORDER BY region_id;

SELECT country_name, region_id
FROM country
WHERE country_name LIKE '%land'
ORDER BY region_id;

SELECT country_name, region_id
FROM country
WHERE country_name LIKE '%land%'
ORDER BY region_id;

SELECT country_name, region_id
FROM country
WHERE country_name LIKE '_a%'
ORDER BY region_id;

SELECT country_name, region_id
FROM country
WHERE country_name LIKE '_a%a' 
ORDER BY region_id;

SELECT country_name, region_id
FROM country
WHERE (country_name LIKE '%land%' OR country_name LIKE '%pore%') AND region_id = 3
ORDER BY region_id;

-- Built-in functions
SELECT UPPER(country_name), LOWER(region_id)
FROM country
WHERE (country_name LIKE '%land%' OR country_name LIKE '%pore%') AND region_id = 3
ORDER BY region_id;

-- Using alias and WHERE is not possible because SELECT is executed after WHERE
SELECT first_name ||  ' ' || last_name "Employee Name", job_id
FROM employee
WHERE "Employee Name" LIKE '%a%' -- this will show an error
ORDER BY first_name;