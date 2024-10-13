--https://leetcode.com/problems/average-selling-price/?envType=study-plan-v2&envId=top-sql-50
Your idea of using the join condition was accurate by using the between condition, you think bringing rows that are necessary at the first step.
Breaking down the problem statements is always good. You also thought of the case when no units are sold for a given product and you handled it
well enough by using a SELECT DISTINCT in the Sub Query. Using join at the last step after aggregation has helped well than the other way around.
Also attaching the best solved method from other user.  

/* Write your T-SQL query statement below */
;with cte1 AS (
SELECT u.*, price*units as purchase
FROM UnitsSold u 
JOIN Prices p 
ON p.product_id = u.product_id
AND u.purchase_date BETWEEN p.start_date AND p.end_date
)


-- SELECT B.product_id, ISNULL(average_price,0) average_price
--  FROM (
--     SELECT product_id
--     ,CAST(SUM(purchase*1.0)/SUM(units) AS DECIMAL(6,2)) average_price
--     FROM cte1 
--     GROUP BY product_id
-- ) A
-- RIGHT OUTER JOIN 
-- (
--     SELECT DISTINCT product_id FROM Prices
-- ) B
-- ON A.product_id = B.product_id

  -- this did not work better
SELECT B.product_id
,CAST(SUM(ISNULL(purchase,0)*1.0)/SUM(ISNULL(units,1)) AS DECIMAL(6,2)) average_price
FROM cte1 A
RIGHT OUTER JOIN 
    (
       SELECT DISTINCT product_id FROM Prices
    ) B
ON A.product_id = B.product_id
GROUP BY B.product_id


  --Other user's solution # Write your MySQL query statement below
SELECT p.product_id, ISNULL(round(SUM(p.price*u.units)/sum(u.units),2),0) as average_price
FROM Prices p 
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id AND 
u.purchase_date BETWEEN p.Start_date and p.end_date
GROUP BY p.product_id
