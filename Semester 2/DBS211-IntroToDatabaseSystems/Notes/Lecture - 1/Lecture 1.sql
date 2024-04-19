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