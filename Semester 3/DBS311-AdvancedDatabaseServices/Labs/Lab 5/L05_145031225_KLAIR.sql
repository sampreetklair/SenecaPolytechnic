-- ***********************
-- Name: Sampreet Klair
-- ID: 145031225
-- Date: 9th February, 2024
-- Purpose: Lab 5 DBS311
-- ***********************

-- Question 1 – The question is asking to display a list of Department IDs for departments that do not contain the job ID of ST_CLERK. But we do not have job_id and department_id columns in the tables, so I have used job_title instead.
-- Q1 SOLUTION
SELECT DISTINCT job_title AS DEPARTMENT_ID
FROM employees
WHERE job_title IS NOT NULL AND job_title NOT IN ('ST_CLERK');

-- Question 2 – The question is asking to display cities where no warehouse is located.
-- Q2 Solution
SELECT city 
FROM locations
WHERE location_id NOT IN (SELECT location_id FROM warehouses);

-- Question 3 – The question is asking to display the category ID, category name, and the number of products in category 1, 2, and 5, in the order category 5, then category 1 and then category 2.
-- Q3 Solution
SELECT pc.category_id, pc.category_name, COUNT(p.product_id)
FROM product_categories pc 
LEFT JOIN products p ON pc.category_id = p.category_id
WHERE pc.category_id IN (5, 1, 2)
GROUP BY pc.category_id, pc.category_name
ORDER BY pc.category_id DESC;

-- Question 4 – The question is asking to display product ID for ordered products whose quantity in the inventory is greater than 5.
-- Q4 Solution
SELECT product_id
FROM order_items
WHERE product_id 
IN (SELECT product_id FROM inventories WHERE quantity > 5);

-- Question 5 – The question is asking to display all warehouses and the state that they are located in and all states regardless of whether they have warehouses in them or not.
-- Q5 Solution
SELECT l.location_id, w.warehouse_name, l.state
FROM locations l 
LEFT JOIN warehouses w ON l.location_id = w.location_id;