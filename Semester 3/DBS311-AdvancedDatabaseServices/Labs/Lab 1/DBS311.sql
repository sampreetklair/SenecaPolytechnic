    SELECT 
        first_name,
        last_name,
        TO_CHAR(hire_date,'Mon dd, yyyy') AS HireDate
    FROM employees
    ORDER BY HireDate;  -- should be hire_date
    
    SELECT 
        first_name,
        last_name,
        hire_date
    FROM employees
    WHERE hire_date BETWEEN to_date('03/01/19', 'mm/dd/yy') AND to_date('02/29/20', 'mm/dd/yy')
    ORDER BY hire_date, last_name, first_name;
    
-- 1.
    SELECT
        first_name,
        last_name
    FROM employees
    WHERE last_name LIKE 'A%'   -- this is incorrect
    ORDER BY 
        last_name, 
        first_name;

-- 2.
    SELECT
        first_name,
        last_name
    FROM employees
    WHERE upper(last_name) LIKE 'A%'
    ORDER BY 
        last_name, 
        first_name;

    -- OR

    SELECT
        first_name,
        last_name
    FROM employees
    WHERE lower(last_name) LIKE 'a%'
    ORDER BY 
        last_name, 
        first_name;
        
        
    SELECT
        first_name,
        last_name
    FROM employees
    WHERE upper(last_name) LIKE upper('&userEnteredLetter') || '%'
    ORDER BY 
        last_name, 
        first_name;
        
    select * from employees;
    
    select add_months(SYSDATE, 60) from dual;
    