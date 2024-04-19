CREATE TABLE student
(
    studentID NUMERIC(38) PRIMARY KEY,
    studentFname VARCHAR2(35),
    studentLname VARCHAR2(35),
    studentNumber CHAR(9) NOT NULL,
    CONSTRAINT ck_positivePK CHECK (studentID > 0)
);


CREATE TABLE course
(
    courseID NUMERIC(38) PRIMARY KEY,
    courseCode CHAR(6) NOT NULL,
    CourseDESC VARCHAR2(35) NOT NULL
);

CREATE TABLE courseDetail
(
    studentID NUMERIC(38),
    courseID NUMERIC(38),
    semesterDate DATE,
    studentGrade NUMERIC(5,2),
    PRIMARY KEY (studentID, courseID, semesterDate),
    CONSTRAINT fk_studentID FOREIGN KEY (studentID) REFERENCES student(studentID),
    CONSTRAINT fk_courseID FOREIGN KEY (courseID) REFERENCES course(courseID),
    CONSTRAINT pkfk_studentID CHECK (studentID > 0),
    CONSTRAINT ck_grade CHECK (studentGrade >= 0 AND studentGrade <= 100)
);

ALTER TABLE course ADD courseMaxStudent NUMERIC(2);
ALTER TABLE course ADD CONSTRAINT ck_maxStudent CHECK (courseMaxstudent >= 0 AND courseMaxstudent <=40);

INSERT INTO student
(studentID,
 studentFname,
 studentLname,
 studentNumber
 )
VALUES
(1, 
 'Bob', 
 'Smith', 
 '012345678'
);
 
 -- only ' ' - single quotes must enclose varchar2 and char data, not double quotes.
 
INSERT INTO student
VALUES
(2, 
 'Jane', 
 'Johnson', 
 '987654321'
);
 
INSERT INTO student
(studentID,
 studentLname,
 studentFname,
 studentNumber
)
VALUES
(4, 
 'Doe', 
 'Jane', 
 '912345678'
);
 
INSERT INTO student
(studentID,
 studentFname,
 studentLname,
 studentNumber
)
VALUES
 (5, 
  NULL, 
  'Murray', 
  '872345678'
);
 
 -- inserting multiple values with same insert command
INSERT ALL 
INTO student (studentID, studentFname, studentLname, studentNumber) VALUES (7, 'Mark', 'Williamson', 394553454)
INTO student (studentID, studentFname, studentLname, studentNumber) VALUES (8, 'Markson', 'William', 394555454)
SELECT * FROM DUAL;
SELECT * FROM student;

-- updating the data in the table
UPDATE student
SET studentLname = 'Carlson'
WHERE studentID = 1;

UPDATE student
SET 
studentLname = 'Smith',
studentFname = 'Bill'
WHERE studentID = 2;

UPDATE student
SET 
studentLname = 'Smith',
studentFname = 'Bill'
WHERE studentID = 2 OR studentID = 4;

SELECT * FROM student;

 
