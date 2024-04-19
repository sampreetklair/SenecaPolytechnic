-- Inner join in sql (while comparing two columns in a table every value should be same in both data columns)
SELECT first_name, last_name, job_title, job.job_id "Job Table", employee.job_id "Employee Table"
FROM employee INNER JOIN job
ON employee.job_id = job.job_id
ORDER BY job.job_id ASC;

-- Outer join in sql
-- Right outer join
SELECT *
FROM employee RIGHT OUTER JOIN job
ON employee.job_id = job.job_id
ORDER BY job.job_id ASC
WHERE employee.job_id IS NULL;

-- Prefer to use left outer join
-- Left outer join
SELECT first_name, last_name, job_title, job.job_id "Job Table", employee.job_id "Employee Table"
FROM job LEFT OUTER JOIN employee
ON employee.job_id = job.job_id
ORDER BY job.job_id ASC
WHERE employee.job_id IS NULL;

-- Using inner join with three tables
SELECT first_name, last_name, job_title, job.job_id "Job Table", employee.job_id "Employee Table", department_name
FROM job INNER JOIN employee 
ON employee.job_id = job.job_id
INNER JOIN department
ON department.department_id = employee.department_id
ORDER BY job.job_id ASC;

-- using table alias
SELECT first_name, last_name, job_title, job.job_id "Job Table", employee.job_id "Employee Table", department_name
FROM job t1 INNER JOIN employee t2
ON employee.job_id = job.job_id
INNER JOIN department t3
ON t3.department_id = t2.department_id
ORDER BY t1.job_id ASC;