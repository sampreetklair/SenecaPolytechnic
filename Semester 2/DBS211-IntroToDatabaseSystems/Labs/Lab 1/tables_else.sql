Question 1:
CREATE TABLE tblSemester
(
    SemesterID NUMERIC(38) PRIMARY KEY,
    SemesterCode VARCHAR2(11) UNIQUE NOT NULL,
    SemesterYear NUMERIC(4) DEFAULT EXTRACT (YEAR FROM CURRENT_DATE) NOT NULL UNIQUE,
    SemesterSeason VARCHAR2(6) NOT NULL,
    CONSTRAINT constraint1 CHECK (SemesterID > 0)
    CONSTRAINT constraint2 CHECK (SemesterYear > 2000),
    CONSTRAINT constraint3 CHECK (SemesterSeason = 'Fall' OR SemesterSeason = 'Summer' OR SemesterSeason = 'Winter')
);
 
 
SELECT constraint_name,
       constraint_type,
       search_condition
FROM USER_CONSTRAINTS
WHERE table_name = 'TBLSEMESTER';
 
 
INSERT INTO tblSemester
(SemesterID, SemesterCode,SemesterSeason)
VALUES
(1,'F12345','Fall')
;
COMMIT;
 
 
SELECT * FROM tblSemester;
 
 
INSERT INTO tblSemester
(SemesterID, SemesterCode,SemesterSeason)
VALUES
(2,'F98765','Spring')
;
COMMIT;
 
 
INSERT INTO tblSemester
(SemesterID, SemesterCode,SemesterSeason)
VALUES
(1,'G12345','Winter')
;
COMMIT;

Question 2:
CREATE TABLE tblCourse
(
    CourseID NUMERIC(38) PRIMARY KEY,
    CourseCode VARCHAR2(6) UNIQUE NOT NULL,
    CONSTRAINT constraint4 CHECK (CourseID > 0)
);

CREATE TABLE tblStudent
(
    StudentID NUMERIC(38) PRIMARY KEY,
    StudentNumber VARCHAR2(6) UNIQUE NOT NULL,
    StudentFname VARCHAR2(20),
    StudentLname VARCHAR(20) NOT NULL,
    CONSTRAINT constraint5 CHECK (StudentID > 0)
);

CREATE TABLE tblInstructor
(
    InstructorID NUMERIC(38) PRIMARY KEY,
    InstructorNumber VARCHAR2(15) UNIQUE NOT NULL,
    InstructorFname VARCHAR2(25),
    InstructorLname VARCHAR(25) NOT NULL,
    CONSTRAINT constraint6 CHECK (InstructorID > 0)
);

CREATE TABLE tblCourseDetail
(
    CourseID NUMERIC(38),
    StudentID NUMERIC(38),
    SemesterID NUMERIC(38),
    InstructorID NUMERIC(38),
    CourseGrade VARCHAR2(2),
    CourseFinalGrade NUMERIC(5,2),
    PRIMARY KEY (CourseID, StudentID, SemesterID),
    CONSTRAINT constraint7 FOREIGN KEY (CourseID) REFERENCES tblCourse(CourseID),
    CONSTRAINT constraint8 FOREIGN KEY (StudentID) REFERENCES tblStudent(StudentID),
    CONSTRAINT constraint9 FOREIGN KEY (SemesterID) REFERENCES tblSemester(SemesterID),
    CONSTRAINT constraint10 FOREIGN KEY (InstructorID) REFERENCES tblInstructor(InstructorID),
    CONSTRAINT constraint11 CHECK (CourseGrade = 'F' OR CourseGrade = 'D' OR CourseGrade = 'D+' OR CourseGrade = 'C' OR CourseGrade = 'C+' OR CourseGrade = 'B' OR CourseGrade = 'B+' OR CourseGrade = 'A' OR CourseGrade = 'A+'),
    CONSTRAINT constraint12 CHECK (CourseFinalGrade >= 0 AND CourseFinalGrade <=100)
);

Question 3:
ALTER TABLE tblCourse ADD CourseDesc VARCHAR2(35) NOT NULL;

Question 4:
ALTER TABLE tblSemester DROP UNIQUE (SemesterYear);

Question 5:
ALTER TABLE tblCourseDetail RENAME COLUMN CourseGrade TO CourseLetterGrade;

Question 6:
ALTER TABLE tblStudent MODIFY (StudentFname VARCHAR2(25), StudentLname VARCHAR2(25));