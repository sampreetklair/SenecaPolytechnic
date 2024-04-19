-- Business Report

-- Report 1: Team Performance
CREATE VIEW vw_team_performance AS
SELECT
    t.TeamID,
    t.TeamName,
    COUNT(r.RaceID) AS TotalRaces,
    SUM(CASE WHEN res.Points IS NOT NULL THEN 1 ELSE 0 END) AS RacesWithPoints,
    COALESCE(SUM(res.Points), 0) AS TotalPoints
FROM
    Teams t
LEFT JOIN
    Drivers d ON t.TeamID = d.TeamID
LEFT JOIN
    Results res ON d.DriverID = res.DriverID
GROUP BY
    t.TeamID, t.TeamName
ORDER BY
    TotalPoints DESC;

/*
   This view provides an overview of each F1 team's performance.
   It includes the total number of races participated in, the number of races where the team earned points,
   and the total points accumulated by the team. This report helps the business assess team success and popularity.
*/

-- Report 2: Driver Statistics
CREATE VIEW vw_driver_statistics AS
SELECT
    d.DriverID,
    CONCAT(d.FirstName, ' ', d.LastName) AS DriverName,
    t.TeamName,
    COUNT(DISTINCT r.RaceID) AS TotalRaces,
    COUNT(DISTINCT fl.RaceID) AS RacesWithFastestLap,
    COUNT(DISTINCT dotd.RaceID) AS RacesWithDriverOfTheDay,
    COUNT(DISTINCT dnf.RaceID) AS RacesWithDNF
FROM
    Drivers d
JOIN
    Teams t ON d.TeamID = t.TeamID
LEFT JOIN
    Results r ON d.DriverID = r.DriverID
LEFT JOIN
    FastestLap fl ON d.DriverID = fl.DriverID
LEFT JOIN
    DriverOfTheDay dotd ON d.DriverID = dotd.DriverID
LEFT JOIN
    DNF dnf ON d.DriverID = dnf.DriverID
GROUP BY
    d.DriverID, DriverName, t.TeamName
ORDER BY
    TotalRaces DESC;

/*
   This view provides statistics for each F1 driver.
   It includes the total number of races participated in, the number of races with the fastest lap,
   the number of races where the driver was awarded "Driver of the Day," and the number of races with a "Did Not Finish" status.
   This report helps the business evaluate driver popularity and performance.
*/

-- Report 3: Circuit Insights
CREATE VIEW vw_circuit_insights AS
SELECT
    c.CircuitID,
    c.CircuitName,
    c.Country,
    COUNT(DISTINCT r.RaceID) AS TotalRaces,
    COUNT(DISTINCT fl.RaceID) AS RacesWithFastestLap,
    COUNT(DISTINCT res.RaceID) AS RacesWithPoints,
    COUNT(DISTINCT dnf.RaceID) AS RacesWithDNF
FROM
    Circuits c
LEFT JOIN
    Races r ON c.CircuitID = r.CircuitID
LEFT JOIN
    FastestLap fl ON r.RaceID = fl.RaceID
LEFT JOIN
    Results res ON r.RaceID = res.RaceID
LEFT JOIN
    DNF dnf ON r.RaceID = dnf.RaceID
GROUP BY
    c.CircuitID, c.CircuitName, c.Country
ORDER BY
    TotalRaces DESC;

/*
   This view provides insights into each F1 circuit's performance.
   It includes the total number of races held at the circuit, the number of races with the fastest lap,
   the number of races with drivers earning points, and the number of races with a "Did Not Finish" status.
   This report helps the business assess circuit popularity and performance.
*/

-- Report 4: Qualifying Overview
CREATE VIEW vw_qualifying_overview AS
SELECT
    q.RaceID,
    c.CircuitName,
    COUNT(q.QualifyingID) AS TotalQualifications,
    MAX(q.QualifyingPosition) AS BestQualifyingPosition,
    MIN(q.QualifyingPosition) AS WorstQualifyingPosition
FROM
    Qualifying q
JOIN
    Races r ON q.RaceID = r.RaceID
JOIN
    Circuits c ON r.CircuitID = c.CircuitID
GROUP BY
    q.RaceID, c.CircuitName
ORDER BY
    TotalQualifications DESC;

/*
   This view provides an overview of F1 qualifying sessions.
   It includes the total number of qualifications per race, the best qualifying position achieved, and the worst qualifying position.
   This report helps the business understand the competitiveness of each race.
*/
