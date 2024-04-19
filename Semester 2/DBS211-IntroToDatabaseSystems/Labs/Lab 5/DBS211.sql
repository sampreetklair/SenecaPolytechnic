-- Prep work for lab:
CREATE TABLE newEmployees AS SELECT * FROM employees; 
--Now execute the following command. 
SET AUTOCOMMIT OFF; 

-- Question 1
INSERT ALL
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', 1, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', 4, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', 2, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', 3, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;

-- Question 2
SELECT * FROM newEmployees;
-- Number of Rows selected: 28

-- Question 3
ROLLBACK;
SELECT * FROM employees;
-- Number of Rows selected: 23

-- Question 4
INSERT ALL
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (100, 'Patel', 'Ralph', '22333', 'rpatel@mail.com', 1, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (101, 'Denis', 'Betty', '33444', 'bdenis@mail.com', 4, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (102, 'Biri', 'Ben', '44555', 'bbirir@mail.com', 2, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (103, 'Newman', 'Chad', '66777', 'cnewman@mail.com', 3, NULL, 'Sales Rep')
INTO newEmployees (employeeNumber, lastname, firstname, extension, email, OfficeCode, reportsTo, jobTitle) VALUES (104, 'Ropeburn', 'Audrey', '77888', 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;
COMMIT;
SELECT * FROM newEmployees;

-- Question 5
ROLLBACK;
SELECT * FROM newEmployees;

-- Question 6
UPDATE newEmployees SET jobTitle='unknown';
COMMIT;

-- Question 7
ROLLBACK;
SELECT * FROM newEmployees;