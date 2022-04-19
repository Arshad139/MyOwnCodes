--https://leetcode.com/problems/capital-gainloss/

;with cte1 as
(
select stock_name, operation, sum(price) as price_sum from Stocks
    group by stock_name,operation
)
select stock_name, 
sum(CASE WHEN operation = 'Buy' THEN -price_sum ELSE price_sum END)
as capital_gain_loss from cte1
group by stock_name

Other approaches->
1. 
SELECT stock_name, 
	SUM(CASE WHEN operation = 'Buy' THEN -price ELSE price END) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name

2. 
select stock_name, sum(iif(operation = 'sell', price, -price)) as capital_gain_loss
from Stocks
group by stock_name
