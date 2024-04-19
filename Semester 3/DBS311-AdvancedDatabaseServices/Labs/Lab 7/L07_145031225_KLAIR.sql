-- ***********************
-- Name: Sampreet Klair
-- ID: 145031225
-- Date: 8th March, 2024
-- Purpose: Lab 7 DBS311
-- ***********************

-- Question 1:
CREATE OR REPLACE PROCEDURE calculate_factorial(n IN NUMBER, result OUT NUMBER) AS
    fact NUMBER := 1;
BEGIN
    IF n = 0 THEN
        result := 1;
    ELSE
        FOR i IN 1..n LOOP
            fact := fact * i;
        END LOOP;
        result := fact;
    END IF;
EXCEPTION
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Error: Too many rows found.');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Error: No data found.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error...');
END calculate_factorial;

-- Question 2:
CREATE OR REPLACE PROCEDURE calculate_salary(employee_id IN NUMBER) AS
    base_salary NUMBER := 10000;
    years_worked NUMBER;
    current_salary NUMBER;
BEGIN
    SELECT FLOOR(MONTHS_BETWEEN(SYSDATE, hire_date) / 12) INTO years_worked FROM employees WHERE employee_id = employee_id;

    current_salary := base_salary * POWER(1.05, years_worked);

    DBMS_OUTPUT.PUT_LINE('Employee ID: ' || employee_id);
    DBMS_OUTPUT.PUT_LINE('Years Worked: ' || years_worked);
    DBMS_OUTPUT.PUT_LINE('Current Salary: $' || TO_CHAR(current_salary, '99999.99'));
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Employee not found.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error...');
END calculate_salary;

-- Question 3:
CREATE OR REPLACE PROCEDURE warehouses_report IS
BEGIN
    FOR i IN 1..9 LOOP
        DBMS_OUTPUT.PUT_LINE('Warehouse ID: ' || i);
        
        SELECT warehouse_name, city, NVL(state, 'no state') 
        INTO warehouse_name, city, state 
        FROM warehouses 
        WHERE warehouse_id = i;

        DBMS_OUTPUT.PUT_LINE('Warehouse Name: ' || warehouse_name);
        DBMS_OUTPUT.PUT_LINE('City: ' || city);
        DBMS_OUTPUT.PUT_LINE('State: ' || state);
        
    END LOOP;
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Warehouse not found.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error...');
END warehouses_report;