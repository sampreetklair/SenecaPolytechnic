-- ***********************
-- Name: Sampreet Klair
-- ID: 145031225
-- Date: 16th February, 2024
-- Purpose: Lab 6 DBS311
-- ***********************

-- Question 1 – Write a stored procedure to determine if a number is even or odd.
-- Q1 SOLUTION –
CREATE OR REPLACE PROCEDURE check_even_odd(p_number IN NUMBER) AS
BEGIN
    IF MOD(p_number, 2) = 0 THEN
        DBMS_OUTPUT.PUT_LINE('The number is even.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('The number is odd.');
    END IF;
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error!');
END check_even_odd;
/

-- Question 2 – Write a stored procedure to find employee information by employee ID.
-- Q2 Solution –
CREATE OR REPLACE PROCEDURE find_employee(p_employee_id IN NUMBER) AS
    v_first_name employees.first_name%TYPE;
    v_last_name employees.last_name%TYPE;
    v_email employees.email%TYPE;
    v_phone employees.phone%TYPE;
    v_hire_date employees.hire_date%TYPE;
    v_job_title employees.job_title%TYPE;
BEGIN
    SELECT first_name, last_name, email, phone, hire_date, job_title
    INTO v_first_name, v_last_name, v_email, v_phone, v_hire_date, v_job_title
    FROM employees
    WHERE employee_id = p_employee_id;

    DBMS_OUTPUT.PUT_LINE('First name: ' || v_first_name);
    DBMS_OUTPUT.PUT_LINE('Last name: ' || v_last_name);
    DBMS_OUTPUT.PUT_LINE('Email: ' || v_email);
    DBMS_OUTPUT.PUT_LINE('Phone: ' || v_phone);
    DBMS_OUTPUT.PUT_LINE('Hire date: ' || TO_CHAR(v_hire_date, 'DD-MON-YY'));
    DBMS_OUTPUT.PUT_LINE('Job title: ' || v_job_title);
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Employee not found.');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error!');
END find_employee;
/

-- Question 3 – Write a stored procedure to update the price of all products in a given category.
-- Q3 Solution –
CREATE OR REPLACE PROCEDURE update_price_by_cat(p_category_id IN NUMBER, p_amount IN NUMBER) AS
    rows_updated NUMBER;
BEGIN
    UPDATE products
    SET list_price = list_price + p_amount
    WHERE category_id = p_category_id AND list_price > 0;

    rows_updated := SQL%ROWCOUNT;

    DBMS_OUTPUT.PUT_LINE('Number of updated rows: ' || rows_updated);
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error!');
END update_price_by_cat;
/

-- Question 4 – Write a stored procedure to update the price of products based on average price.
-- Q4 Solution –
CREATE OR REPLACE PROCEDURE update_price_under_avg AS
    avg_price NUMBER(9,2);
    rows_updated NUMBER;
BEGIN
    SELECT AVG(list_price)
    INTO avg_price
    FROM products;

    IF avg_price <= 1000 THEN
        UPDATE products
        SET list_price = list_price * 1.02
        WHERE list_price < avg_price;
    ELSE
        UPDATE products
        SET list_price = list_price * 1.01
        WHERE list_price < avg_price;
    END IF;

    rows_updated := SQL%ROWCOUNT;

    DBMS_OUTPUT.PUT_LINE('Number of updated rows: ' || rows_updated);
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error!');
END update_price_under_avg;
/

-- Question 5 – Write a stored procedure to generate a product price report.
-- Q5 Solution –
CREATE OR REPLACE PROCEDURE product_price_report AS
    avg_price NUMBER(9,2);
    min_price NUMBER(9,2);
    max_price NUMBER(9,2);
    cheap_count NUMBER := 0;
    fair_count NUMBER := 0;
    exp_count NUMBER := 0;
BEGIN
    SELECT AVG(list_price), MIN(list_price), MAX(list_price)
    INTO avg_price, min_price, max_price
    FROM products;

    FOR product_rec IN (SELECT list_price FROM products) LOOP
        IF product_rec.list_price < (avg_price - min_price) / 2 THEN
            cheap_count := cheap_count + 1;
        ELSIF product_rec.list_price > (max_price - avg_price) / 2 THEN
            exp_count := exp_count + 1;
        ELSE
            fair_count := fair_count + 1;
        END IF;
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('Cheap: ' || cheap_count);
    DBMS_OUTPUT.PUT_LINE('Fair: ' || fair_count);
    DBMS_OUTPUT.PUT_LINE('Expensive: ' || exp_count);
EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Error!');
END product_price_report;
/