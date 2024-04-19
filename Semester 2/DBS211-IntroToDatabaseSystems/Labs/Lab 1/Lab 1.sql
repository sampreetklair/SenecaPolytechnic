-- Creating a table called tblSemester containing columns SemesterID, SemesterID, SemesterYear and SemesterSeason.
CREATE TABLE tblSemester
(
    SemesterID NUMERIC(38) PRIMARY KEY,
    SemesterCode VARCHAR2(11) UNIQUE NOT NULL,
    SemesterYear NUMERIC(4) DEFAULT EXTRACT (YEAR FROM CURRENT_DATE) NOT NULL UNIQUE,
    SemesterSeason VARCHAR2(6) NOT NULL,
    CONSTRAINT semID_gr_than_0 CHECK (SemesterID > 0)
    CONSTRAINT yr_gr_than_2000 CHECK (SemesterYear > 2000),
    CONSTRAINT season_fsw CHECK (SemesterSeason = 'Fall' OR SemesterSeason = 'Summer' OR SemesterSeason = 'Winter')
);
 
 
-- Using the select command to display all the constraints.
SELECT constraint_name,
       constraint_type,
       search_condition
FROM USER_CONSTRAINTS
WHERE table_name = 'TBLSEMESTER';
 
 
-- Inserting and commiting values into table tblSemester.
INSERT INTO tblSemester
(SemesterID, SemesterCode,SemesterSeason)
VALUES
(1,'F12345','Fall')
;
COMMIT;
 
 
-- Using select command to display all the data in table tblSemester.
SELECT * FROM tblSemester;
 
 
-- Inserting and commiting values into table tblSemester and recieved an error because input violated constraint season_fsw.
INSERT INTO tblSemester
(SemesterID, SemesterCode,SemesterSeason)
VALUES
(2,'F98765','Spring')
;
COMMIT;
 
 
-- Inserting and commiting values into table tblSemester and recieved an error because input violated constraint yr_gr_than_2000.
INSERT INTO tblSemester
(SemesterID, SemesterCode,SemesterSeason)
VALUES
(1,'G12345','Winter')
;
COMMIT;

-- Creating a table called tblCourse containing columns CourseID and CourseCode.
CREATE TABLE tblCourse
(
    CourseID NUMERIC(38) PRIMARY KEY,
    CourseCode VARCHAR2(6) UNIQUE NOT NULL,
    CONSTRAINT courseID_gr_than_0 CHECK (CourseID > 0)
);

-- Creating a table called tblStudent containing columns StudentID, StudentNumber, StudentFname and StudentLname.
CREATE TABLE tblStudent
(
    StudentID NUMERIC(38) PRIMARY KEY,
    StudentNumber VARCHAR2(6) UNIQUE NOT NULL,
    StudentFname VARCHAR2(20),
    StudentLname VARCHAR2(20) NOT NULL,
    CONSTRAINT StudentID_gr_than_0 CHECK (StudentID > 0)
);

-- Creating a table called tblInstructor containing columns InstructorID, InstructorNumber, InstructorFname and InstructorLname.
CREATE TABLE tblInstructor
(
    InstructorID NUMERIC(38) PRIMARY KEY,
    InstructorNumber VARCHAR2(15) UNIQUE NOT NULL,
    InstructorFname VARCHAR2(25),
    InstructorLname VARCHAR2(25) NOT NULL,
    CONSTRAINT InstructorID_gr_than_0 CHECK (InstructorID > 0)
);

-- Creating a table called tblCourseDetail containing columns CourseID, StudentID, SemesterID, InstructorID, CourseGrade and CourseFinalGrade.
CREATE TABLE tblCourseDetail
(
    CourseID NUMERIC(38),
    StudentID NUMERIC(38),
    SemesterID NUMERIC(38),
    InstructorID NUMERIC(38),
    CourseGrade VARCHAR2(2),
    CourseFinalGrade NUMERIC(5,2),
    PRIMARY KEY (CourseID, StudentID, SemesterID),
    CONSTRAINT CourseID_fk FOREIGN KEY (CourseID) REFERENCES tblCourse(CourseID),
    CONSTRAINT StudentID_fk FOREIGN KEY (StudentID) REFERENCES tblStudent(StudentID),
    CONSTRAINT SemesterID_fk FOREIGN KEY (SemesterID) REFERENCES tblSemester(SemesterID),
    CONSTRAINT InstructorID_fk FOREIGN KEY (InstructorID) REFERENCES tblInstructor(InstructorID),
    CONSTRAINT grade_alpha CHECK (CourseGrade = 'F' OR CourseGrade = 'D' OR CourseGrade = 'D+' OR CourseGrade = 'C' OR CourseGrade = 'C+' OR CourseGrade = 'B' OR CourseGrade = 'B+' OR CourseGrade = 'A' OR CourseGrade = 'A+'),
    CONSTRAINT finalgrade_0to100 CHECK (CourseFinalGrade >= 0 AND CourseFinalGrade <=100)
);

-- Altering the table tblCourse by adding a column CourseDesc.
ALTER TABLE tblCourse ADD CourseDesc VARCHAR2(35) NOT NULL;

-- Altering the table tblSemester by removing UNIQUE Constraint on column SemesterYear.
ALTER TABLE tblSemester DROP UNIQUE (SemesterYear);

-- Altering the table tblCourseDetail by changing name of column CourseGrade to CourseLetterGrade.
ALTER TABLE tblCourseDetail RENAME COLUMN CourseGrade TO CourseLetterGrade;

-- Altering the table tblStudent by changing the length of maximum characters of column StudentFname to StudentLname to 25.
ALTER TABLE tblStudent MODIFY (StudentFname VARCHAR2(25), StudentLname VARCHAR2(25));