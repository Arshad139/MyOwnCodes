https://leetcode.com/problems/biggest-single-number/?envType=study-plan-v2&envId=top-sql-50

/* Write your T-SQL query statement below */

  ISNULL can also be used here but coalesce was more quicker. Never knew that we can use a complete select statement including order by

SELECT COALESCE(
    (
        SELECT TOP 1 num
        FROM MyNumbers
        GROUP BY num
        HAVING COUNT(*) = 1
        ORDER BY num DESC
    )
, null) as num
