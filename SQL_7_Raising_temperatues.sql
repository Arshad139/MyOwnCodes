--https://leetcode.com/problems/rising-temperature/description/?envType=study-plan-v2&envId=top-sql-50
--The first approach would not work because LAG(col,1) will just be able to fetch the previous record but not the row that has the previous date.
--For this, we would need to self join and the condition for the join is that we need the info of the previous recordDate.

/* Write your T-SQL query statement below */
-- ;with CTE AS (
--     SELECT *, LAG(temperature, 1) OVER (
--   ORDER BY recordDate) AS prev_temperature
--     FROM Weather
-- )

-- SELECT id FROM CTE WHERE temperature > prev_temperature
SELECT w1.id as Id
FROM Weather w1
JOIN Weather w2
ON w1.recordDate = DATEADD(DAY,1,w2.recordDate)
WHERE w1.temperature > w2.temperature
