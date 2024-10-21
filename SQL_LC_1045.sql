https://leetcode.com/problems/customers-who-bought-all-products/?envType=study-plan-v2&envId=top-sql-50

  This was a good solve, you were first trying to use the LEFT JOIN & NULL Check approach, but it doesnt really fit in here, its not always the solution.
  When you realised this, you straight up left this approach started thinking in other direction(s). Then you thought of using the count approach. 

  
DECLARE @total_products INT
SELECT @total_products = COUNT(1) FROM Product

SELECT customer_id
    FROM Customer
    GROUP BY customer_id
    HAVING COUNT(DISTINCT product_key) = @total_products
