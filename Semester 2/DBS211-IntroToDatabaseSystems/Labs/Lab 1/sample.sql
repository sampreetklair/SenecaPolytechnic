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
    StudentLname VARCHAR(20) NOT NULL,
    CONSTRAINT StudentID_gr_than_0 CHECK (StudentID > 0)
);

-- Creating a table called tblInstructor containing columns InstructorID, InstructorNumber, InstructorFname and InstructorLname.
CREATE TABLE tblInstructor
(
    InstructorID NUMERIC(38) PRIMARY KEY,
    InstructorNumber VARCHAR2(15) UNIQUE NOT NULL,
    InstructorFname VARCHAR2(25),
    InstructorLname VARCHAR(25) NOT NULL,
    CONSTRAINT InstructorID_gr_than_0 CHECK (InstructorID > 0)
);

-- Creating a table called CourseDetail containing columns CourseID, StudentID, SemesterID, InstructorID, CourseGrade and CourseFinalGrade.
CREATE TABLE CourseDetail
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
    CONSTRAINT InstructorID_fk FOREIGN KEY (InstructorID) REFERENCES tblStudent(InstructorID),
    CONSTRAINT grade_alpha CHECK (CourseGrade = 'F' OR CourseGrade = 'D' OR CourseGrade = 'D+' OR CourseGrade = 'C' OR CourseGrade = 'C+' OR CourseGrade = 'B' OR CourseGrade = 'B+' OR CourseGrade = 'A' OR CourseGrade = 'A+')
    CONSTRAINT finalgrade_0to100 CHECK (CourseFinalGrade >= 0 AND CourseFinalGrade <=100)
);

-- Updating/Altering the table tblCourse by adding a column CourseDesc.
ALTER TABLE tblCourse ADD CourseDesc VARCHAR2(35) NOT NULL;