https://leetcode.com/problems/immediate-food-delivery-ii/description/?envType=study-plan-v2&envId=top-sql-50
This was a good solve, again you were able to think like your project way. 

;with cte AS(
    SELECT *
    , ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) as rn
    , CASE WHEN DATEDIFF(DAY,order_date,customer_pref_delivery_date) = 0 THEN 1 ELSE 0 END AS immediates
    FROM Delivery
)

SELECT 
ROUND(SUM(immediates)*100.0 / COUNT(1), 2)  immediate_percentage
FROM cte WHERE rn = 1
