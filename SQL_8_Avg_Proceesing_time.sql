-- https://leetcode.com/problems/average-time-of-process-per-machine/?envType=study-plan-v2&envId=top-sql-50
Against a machine id, process_id, you needed to calculate the processing time first, you can do that by using activity_type column and use a case 
condition in aggregate function of SUM(), this can always be useful when you find the difference in a aggregate operation. 
Once you have this aggregated result (one layer) in your cte, where you have one row per machine_id & process_id & now you can aggregate on machine_id alone to get the result.
  There were other approaches as well, where a join was performed to fetch the activuty_type = end row details by using timestamp (less-than condition). 

/* Write your T-SQL query statement below */
;with cte as (
    select machine_id, process_id, 
    round(SUM(CASE WHEN activity_type = 'start'
        THEN timestamp*-1 ELSE timestamp 
        END),3) diff
    FROM Activity
    GROUP BY machine_id, process_id
)

SELECT machine_id, round(AVG(diff),3) processing_time
FROM cte GROUP BY machine_id order by machine_id
