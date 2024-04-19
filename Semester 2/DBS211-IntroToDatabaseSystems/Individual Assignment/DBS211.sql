-- Question 1
SELECT t1.airplanetypename AS "Plane Type", t1.airplanetypemaxseats AS "Maximum Seats", t2.airplaneseats AS "Modified Seating", (t1.airplanetypemaxseats - t2.airplaneseats) AS Difference
FROM a1_airplanetype t1 INNER JOIN a1_airplane t2 
ON t1.airplanetypeid = t2.airplanetypeid
WHERE t1.airplanetypemaxseats != t2.airplaneseats
ORDER BY difference DESC;

-- Question 2
SELECT t1.airplanecompanyname, t2.airplanetypename
FROM a1_airplanecompany t1 INNER JOIN  a1_airplanetype t2
ON t1.airplanecompanyid = t2.airplanecompanyid
ORDER BY t1.airplanecompanyname ASC, t2.airplanetypename ASC;

-- Question 3
SELECT t1.airportcode AS Code, t1.airportname AS Name
FROM a1_airport t1 LEFT OUTER JOIN a1_flightleg  t2
ON t1.airportid = t2.airportid_departure
WHERE t2.airportid_departure IS NULL
ORDER BY Code DESC;

-- Question 4
SELECT t1.airplanetypename AS "Type of Plane"
FROM a1_airplanetype t1 LEFT OUTER JOIN a1_canland t2
ON t1.airplanetypeid = t2.airplanetypeid
WHERE t2.airplanetypeid IS NULL;

-- Question 5
SELECT DISTINCT t3.airlinename AS "Airline", t2.airplaneseats AS "Modified Seating", t1.airplanetypeid AS "Plane Type", t1.airplanetypemaxseats AS "Maximum Seats"
FROM a1_airplanetype t1 INNER JOIN a1_airplane t2 
ON t1.airplanetypeid = t2.airplanetypeid
INNER JOIN a1_airline t3
ON t1.airplanecompanyid = t3.airlineid
WHERE t1.airplanetypemaxseats != t2.airplaneseats
ORDER BY "Airline" ASC;

-- Question 6
SELECT t1.airlinename AS "Airline", t2.flightnumber AS "Flight Number", t3.leginstancedate AS "Date"
FROM a1_airline t1 INNER JOIN a1_flight t2
ON t1.airlineid = t2.airlineid
INNER JOIN a1_leginstance t3
ON t2.flightid = t3.flightid
WHERE t3.leginstancedate >= '2018-02-01' AND t3.leginstancedate <= '2018-02-28'
ORDER BY t3.leginstancedate ASC, t1.airlinename ASC;

