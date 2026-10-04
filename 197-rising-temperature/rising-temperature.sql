# Write your MySQL query statement below
-- SELECT Id 
-- FROM (SELECT id, recordDate, temperature,
-- LAG(temperature, 1) OVER (ORDER BY recordDate) AS prev_temp 
-- FROM Weather) prev_table 
-- WHERE temperature > prev_temp;

SELECT w1.id 
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 
AND w1.temperature > w2.temperature;