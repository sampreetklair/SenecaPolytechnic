-- Teams
CREATE TABLE Teams (
    TeamID NUMERIC(2) PRIMARY KEY,
    TeamName VARCHAR2(50) NOT NULL UNIQUE,
    TeamPrincipalName VARCHAR2(50),
    EngineSupplier VARCHAR2(50)
);

-- Drivers
CREATE TABLE Drivers (
    DriverID NUMERIC(3) PRIMARY KEY,
    FirstName VARCHAR2(50) NOT NULL,
    LastName VARCHAR2(50) NOT NULL,
    TeamID NUMERIC(2) NOT NULL,
    Nationality VARCHAR2(50) NOT NULL,
    DateOfBirth DATE,
    CONSTRAINT fk_driver_team FOREIGN KEY (TeamID) REFERENCES Teams(TeamID)    
);

-- Circuits
CREATE TABLE Circuits (
    CircuitID NUMERIC(2) PRIMARY KEY,
    CircuitName VARCHAR2(100) NOT NULL UNIQUE,
    Country VARCHAR2(50) NOT NULL
);

-- Races
CREATE TABLE Races (
    RaceID NUMERIC(2) PRIMARY KEY,
    RaceName VARCHAR2(100) NOT NULL UNIQUE,
    CircuitID NUMERIC(2) NOT NULL,
    RaceDate DATE,
    CONSTRAINT fk_race_circuit FOREIGN KEY (CircuitID) REFERENCES Circuits(CircuitID)
);

-- Results
CREATE TABLE Results (
    ResultID NUMERIC(2) PRIMARY KEY,
    RaceID NUMERIC(2) NOT NULL,
    DriverID NUMERIC(3) NOT NULL,
    DriverPosition NUMERIC(2),
    Points NUMERIC(2),
    CONSTRAINT fk_results_race FOREIGN KEY (RaceID) REFERENCES Races(RaceID),
    CONSTRAINT fk_results_driver FOREIGN KEY (DriverID) REFERENCES Drivers(DriverID)
);

-- DriverOfTheDay
CREATE TABLE DriverOfTheDay (
    RaceID NUMERIC(2) NOT NULL,
    DriverID NUMERIC(3) NOT NULL,
    PRIMARY KEY (RaceID, DriverID),
    CONSTRAINT fk_driver_of_the_day_race FOREIGN KEY (RaceID) REFERENCES Races(RaceID),
    CONSTRAINT fk_driver_of_the_day_driver FOREIGN KEY (DriverID) REFERENCES Drivers(DriverID)
);

-- FastestLap
CREATE TABLE FastestLap (
    LapTime TIMESTAMP(3),
    RaceID NUMERIC(2) NOT NULL,
    DriverID NUMERIC(3) NOT NULL,
    PRIMARY KEY (RaceID, DriverID),
    CONSTRAINT fk_fastest_lap_race FOREIGN KEY (RaceID) REFERENCES Races(RaceID),
    CONSTRAINT fk_fastest_lap_driver FOREIGN KEY (DriverID) REFERENCES Drivers(DriverID)
);

-- DNF (Did Not Finish)
CREATE TABLE DNF (
    RaceID NUMERIC(2) NOT NULL,
    DriverID NUMERIC(3) NOT NULL,
    Reason VARCHAR2(255),
    PRIMARY KEY (RaceID, DriverID),
    CONSTRAINT fk_dnf_race FOREIGN KEY (RaceID) REFERENCES Races(RaceID),
    CONSTRAINT fk_dnf_driver FOREIGN KEY (DriverID) REFERENCES Drivers(DriverID)
);

-- Qualifying
CREATE TABLE Qualifying (
    QualifyingID NUMERIC(2) PRIMARY KEY,
    QualifyingPosition NUMERIC(2) NOT NULL,
    LapTime TIMESTAMP(3),
    RaceID NUMERIC(2) NOT NULL,
    DriverID NUMERIC(3) NOT NULL,
    CONSTRAINT fk_qualifying_race FOREIGN KEY (RaceID) REFERENCES Races(RaceID),
    CONSTRAINT fk_qualifying_driver FOREIGN KEY (DriverID) REFERENCES Drivers(DriverID)
);