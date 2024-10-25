https://leetcode.com/problems/primary-department-for-each-employee/?envType=study-plan-v2&envId=top-sql-50

Your intution was good here, thought of getting the counts first & then using them to join on the actual table to decide on which rows to pick
  There was also another good solution based on usage of Union. 
  
/* Write your T-SQL query statement below */

; with cte as (
    select employee_id, count(*) cnt
    FROM Employee
    GROUP BY employee_id
)

SELECT e.employee_id , department_id FROM 
Employee e 
JOIN cte c
ON e.employee_id = c.employee_id
WHERE cnt = 1  OR primary_flag = 'Y'
