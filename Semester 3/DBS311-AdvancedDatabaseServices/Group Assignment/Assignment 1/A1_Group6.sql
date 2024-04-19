-- ***********************
-- Student1 Name: Harsahbaj Singh ID: 146457221
-- Student2 Name: Arshdeep Kaur ID: 139566228
-- Student3 Name: Sampreet Klair ID: 145031225
-- Student4 Name: Ritish Sharma ID: 146407226
-- Student5 Name: Viralika ID: 145387221
-- Date: 29 March 2024
-- Purpose: Assignment 1 - DBS311 Group 6
-- ***********************

--Question1 Show the employee ID, complete name, job role, and hiring date of all staff recruited in September, starting with the most recently hired employees
--Q1 SOLUTION
SELECT employee_id AS "Employee Number",
last_name || ', ' || first_name AS "Full Name",
job_title AS "Job title",
TO_CHAR(hire_date, '[fmMonth ddth "of" yyyy]') AS "Start Date"
FROM employees
WHERE EXTRACT(MONTH FROM hire_date) IN (9)
ORDER BY hire_date DESC;

--Question2 The company wishes to view the total sales amount per salesperson for all orders, considering that online orders do not have any sales representative.
--For online orders, where there's no salesman ID, 
-- it's assumed as 0. Show the salesman ID along with the total sale amount for each employee, sorted by employee number.
--Q2 SOLUTION
SELECT
   NVL(o.salesman_id, 0)AS "Employee Number",
  TO_CHAR( SUM(i.unit_price*i.quantity), '$99,999,999.99') AS "Total Sale" 
FROM
   orders o JOIN order_items i 
ON
   o.order_id = i.order_id 
GROUP BY
   nvl(o.salesman_id, 0) 
ORDER BY
   nvl(o.salesman_id, 0);


--QUESTION3 Show the customer ID, customer name, and total number of orders for customers whose customer ID 
--falls within the range of 35 to 45. Include customers with no orders if their customer ID falls within the specified range. 
--Sort the result by the total number of orders.
--Q3 SOLUTION
SELECT
   c.customer_id AS "Customer ID",
   c.name AS "Name",
   COUNT(o.order_id) AS "Total Orders" 
FROM
   customers c LEFT JOIN orders o 
ON c.customer_id = o.customer_id 
WHERE
   c.customer_id BETWEEN 35 AND 45 
GROUP BY
   c.customer_id,
   c.name 
ORDER BY
   COUNT(o.order_id);


--QUESTION4 Display the customer ID, customer name, order ID, and order date for all orders made by customers with the ID 44.
--a. Additionally, show the total quantity and total amount of each customer's order.
--b. Sort the result by the total order amount, arranging from highest to lowest.
--Q4 SOLUTION
SELECT
   c.customer_id AS "Customer Id",
   c.name AS "Name",
   o.order_id AS "Order Id",
   o.order_date AS "Order Date",
   SUM(i.quantity) AS "Total Items",
   TO_CHAR(SUM(i.quantity * i.unit_price), '$9,999,999.99') AS "Total Amount" 
FROM
   customers c 
   JOIN
      orders o 
      ON c.customer_id = o.customer_id 
   JOIN
      order_items i 
      ON o.order_id = i.order_id 
WHERE
   c.customer_id = 44 
GROUP BY
   c.customer_id,
   c.name,
   o.order_id,
   o.order_date 
ORDER BY
   SUM(i.quantity * i.unit_price) DESC;

--QUESTION 5 Show the customer ID, name, total number of orders, total number of items ordered, and total order amount for customers who have more than 30 orders. 
--Sort the result based on the total number of orders.
--Q5 SOLUTION
SELECT c.customer_id AS "Customer Id",
   c.name AS "Name",
  COUNT(o.order_id)AS "Total Number of Orders",
   SUM(i.quantity) AS "Total Items",
   TO_CHAR(SUM(i.quantity * i.unit_price),'$9,999,999.99') AS "Total Amount" 
FROM
   customers c 
   JOIN
      orders o 
      ON c.customer_id = o.customer_id 
   JOIN
      order_items i 
      ON o.order_id = i.order_id 
HAVING COUNT(o.order_id)>30
GROUP BY
   c.customer_id,
   c.name
ORDER BY
  COUNT(o.order_id);
  
--QUESTION6 Show the Warehouse ID, warehouse name, product category ID, product category name, and the lowest product standard cost for each combination. 
--Include rows where the lowest standard cost is less than $200 or more than $500. Sort the output by Warehouse ID, warehouse name, product category ID, and product category name.
--Q6 SOLUTION
SELECT
   w.warehouse_id AS "Warehouse ID",
   w.warehouse_name AS "Warehouse Name",
   p.category_id AS "Category ID",
   pc.category_name AS "Category Name",
  TO_CHAR(MIN(p.standard_cost), '$999,999.99') AS "Lowest Cost" 
FROM
   inventories i 
   JOIN
      warehouses w 
      ON i.warehouse_id = w.warehouse_id 
   JOIN
      products p 
      ON i.product_id = p.product_id 
   JOIN
      product_categories pc 
      ON p.category_id = pc.category_id 
GROUP BY
   w.warehouse_id,
   w.warehouse_name,
   p.category_id,
   pc.category_name 
HAVING
   MIN(standard_cost) < 200 
   OR MIN(standard_cost) > 500 
ORDER BY
   w.warehouse_id,
   w.warehouse_name,
   p.category_id,
   pc.category_name;

--QUESTION7 Show the total number of orders per month, sorting the result from January to December.
--Q7 SOLUTION
SELECT
   TO_CHAR(TO_DATE(MONTH, 'MM'), 'Month') AS "Month",
   TOTAL_ORDERS AS "Number of Orders" 
FROM
   (
      SELECT
         EXTRACT(MONTH FROM order_date) AS "MONTH",
         COUNT(*) AS "TOTAL_ORDERS" 
      FROM
         orders 
      GROUP BY
         EXTRACT(MONTH FROM order_date) 
   )
   sales 
ORDER BY
   MONTH;
   
--QUESTION8 Show the product ID and product name for products whose list price is higher than the highest standard cost per warehouse outside the Americas regions. 
--First, find the highest standard cost for each warehouse located outside the Americas. 
--Then return all products with a list price higher than any highest standard cost of those warehouses. Sort the result according to list price from highest value to the lowest.
--Q8 SOLUTION
SELECT
   product_id AS "Product ID",
   product_name AS "Product Name",
   TO_CHAR(list_price, '$999,999.99') AS "Price" 
FROM
   products 
WHERE
   list_price > ANY ( 
   SELECT
      MAX(p.standard_cost) 
   FROM
      locations l 
      JOIN countries c 
         ON l.country_id = c.country_id 
      JOIN regions r 
         ON r.region_id = c.region_id 
      JOIN warehouses w 
         ON w.location_id = l.location_id 
      JOIN inventories i 
         ON i.warehouse_id = w.warehouse_id 
      JOIN  products p 
         ON p.product_id = i.product_id 
   WHERE r.region_name NOT LIKE 'Americas' 
   GROUP BY w.warehouse_id) 
   ORDER BY  list_price DESC;
   
--QUESTION 9 Provide a SQL query to show the product ID, product name, and list price of the most expensive and cheapest products.
--Q9 SOLUTION
SELECT
   product_id AS "Product ID",
   product_name AS "Product Name",
   TO_CHAR(list_price, '$999,999.99') AS "Price" 
FROM
   products 
WHERE
   list_price = 
   (
      SELECT
         MAX(list_price) 
      FROM
         products
   )
   OR list_price = 
   (
      SELECT
         MIN(list_price) 
      FROM
         products
   );
   
--QUESTION 10 Create a SQL query to present the count of customers with total order amounts exceeding the average order amount, 
--the count of customers with total order amounts below the average order amount, the count of customers with no orders, and the total count of customers.
--Q10 SOLUTION
SELECT 'Number of customers with total purchase amount over average: ' || COUNT(*) AS "Customer  Report" 
FROM
   ( SELECT  c.customer_id,
         SUM(i.quantity*i.unit_price) AS total_amount 
      FROM customers c 
         INNER JOIN orders o 
            ON c.customer_id = o.customer_id 
         INNER JOIN order_items i 
            ON i.order_id = o.order_id 
      GROUP BY c.customer_id )
WHERE
   total_amount > (SELECT AVG(quantity*unit_price) 
   FROM order_items) 
   UNION ALL
   SELECT 'Number of customers with total purchase amount below average: ' || COUNT(*) 
   FROM
      (  SELECT c.customer_id,
          SUM(i.quantity*i.unit_price) AS total_amount 
         FROM  customers c 
            INNER JOIN orders o 
               ON c.customer_id = o.customer_id 
            INNER JOIN order_items i 
               ON i.order_id = o.order_id 
         GROUP BY c.customer_id  )
   WHERE total_amount < ( SELECT AVG(quantity*unit_price) 
      FROM order_items) 
      UNION ALL
      SELECT 'Number of customers with no orders: ' || COUNT(*) 
      FROM
         ( SELECT customer_id 
            FROM customers minus 
               SELECT customer_id 
               FROM orders )
      UNION ALL
      SELECT 'Total number of customers: ' || COUNT(*) 
      FROM
         (SELECT  customer_id 
            FROM  customers 
            UNION
            SELECT  customer_id 
            FROM orders);   