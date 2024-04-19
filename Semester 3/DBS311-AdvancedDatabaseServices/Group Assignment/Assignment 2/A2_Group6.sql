-- ***********************
-- Student1 Name: Harsahbaj Singh ID: 146457221
-- Student2 Name: Arshdeep Kaur ID: 139566228
-- Student3 Name: Sampreet Klair ID: 145031225
-- Student4 Name: Ritish Sharma ID: 146407226
-- Student5 Name: Viralika ID: 145387221
-- Date: 10 April 2024
-- Purpose: Assignment 2 - DBS311
-- ***********************

SET SERVEROUTPUT ON;

-- finding customers using customerID
CREATE OR REPLACE PROCEDURE find_customer(customerID IN NUMBER, found OUT NUMBER) AS
BEGIN
    SELECT COUNT(*)
    INTO found
    FROM customers
    WHERE CUSTOMER_ID = customerID;
    
EXCEPTION
    WHEN NO_DATA_FOUND THEN
        found := 0;
END;
/
-- finding products using productID
CREATE OR REPLACE PROCEDURE find_product(productID IN NUMBER, price OUT products.list_price%TYPE) AS
BEGIN
    SELECT  list_price
    INTO    price
    FROM    products
    WHERE   product_id = productID;
    
    EXCEPTION
    WHEN NO_DATA_FOUND THEN
        price := 0;
END;
/
-- adding a new order using customerID
CREATE OR REPLACE PROCEDURE add_order(customerID IN NUMBER, new_order_id OUT NUMBER) AS
BEGIN
    SELECT  MAX(order_id)
    INTO    new_order_id
    FROM    orders;   
    new_order_id := new_order_id + 1;  
    INSERT INTO orders
    (ORDER_ID, CUSTOMER_ID, STATUS, SALESMAN_ID, ORDER_DATE)
    VALUES
    (new_order_id, customerID, 'Shipped', 56, SYSDATE);
END;
/
-- adding an order item to order item list
CREATE OR REPLACE PROCEDURE add_order_item(orderId IN order_items.order_id%type, itemId IN order_items.item_id%type, productId IN order_items.product_id%type, inQuantity IN order_items.quantity%type, price IN order_items.unit_price%type) AS
BEGIN
    INSERT INTO order_items
    (order_id, item_id, product_id, quantity, unit_price)
    VALUES
    (orderId, itemId, productId, inQuantity, price);
    
END;
/