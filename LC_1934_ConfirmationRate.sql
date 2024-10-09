--https://leetcode.com/problems/confirmation-rate/description/?envType=study-plan-v2&envId=top-sql-50
This was a great solve too, here you felt like you were defining the metrics in you Reporting pipelines, and that is how 
  you definied metrics separately based on the requirements for the ratio.


;with CTE AS(
SELECT user_id, CAST( COUNT(1) AS DECIMAL(4,2)) entries
, CAST(COUNT(CASE WHEN action = 'confirmed' THEN 1 END) AS DECIMAL(4,2)) success
FROM Confirmations C
GROUP BY user_id
)

SELECT s.user_id,
 CASE WHEN c.user_id IS NULL THEN ROUND(0,2)
 ELSE ROUND(ISNULL(success,0)/ISNULL(entries,0),2) END as confirmation_rate
FROM Signups s
LEFT JOIN CTE c
ON s.user_id = c.user_id
