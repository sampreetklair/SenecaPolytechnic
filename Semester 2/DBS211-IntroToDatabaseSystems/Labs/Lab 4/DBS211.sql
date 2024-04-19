-- Question 1
SELECT employeenumber,firstname,lastname,city,phone,postalcode FROM employees INNER JOIN offices
ON employees.officecode = offices.officecode WHERE offices.country = 'France';

-- Question 2
SELECT payments.customernumber, customers.customername, TO_CHAR(paymentdate, 'Month DD, YYYY'), amount FROM payments INNER JOIN customers
ON payments.customernumber = customers.customernumber WHERE customers.country = 'Canada'
ORDER BY payments.customernumber;

-- Question 3
SELECT customers.customernumber, customers.customername FROM customers LEFT OUTER JOIN payments
ON customers.customernumber = payments.customernumber WHERE customers.country = 'USA' AND payments.customernumber IS NULL
ORDER BY customers.customernumber ASC;

-- Question 4
CREATE VIEW vwCustomerOrder AS
SELECT customers.customernumber, orders.ordernumber, orders.orderdate, products.productname, orderdetails.quantityordered, orderdetails.priceeach FROM customers INNER JOIN orders 
ON customers.customernumber = orders.customernumber INNER JOIN orderdetails 
ON orders.ordernumber = orderdetails.ordernumber INNER JOIN products 
ON orderdetails.productcode = products.productcode;

-- Question 5
SELECT * FROM vwCustomerOrder;

-- Question 6
SELECT customernumber, ordernumber, ROW_NUMBER() OVER (PARTITION BY ordernumber ORDER BY ordernumber) AS orderlinenumber
FROM vwCustomerOrder
WHERE customernumber = 124
ORDER BY ordernumber, orderlinenumber;

-- Question 7
SELECT customers.customernumber, customers.contactfirstname, customers.contactlastname, customers.phone, customers.creditlimit FROM customers LEFT OUTER JOIN orders
ON customers.customernumber = orders.customernumber WHERE orders.ordernumber IS NULL;

-- Question 8
CREATE VIEW vwEmployeeManager AS
SELECT e.employeenumber, e.firstname, e.lastname, e.jobtitle, e.email, m.firstname AS manager_first_name, m.lastname AS manager_last_name
FROM employees e LEFT OUTER JOIN employees m 
ON e.reportsto = m.employeenumber;

-- Question 9
ALTER VIEW vwEmployeeManager ADD CONSTRAINT ck_reportsto CHECK (e.reportsto IS NOT NULL);

-- Question 10
DROP VIEW vwCustomerOrder;
DROP VIEW vwEmployeeManager;
