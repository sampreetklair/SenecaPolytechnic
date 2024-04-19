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