;with cte as
( select emp_name,dep_name,dep_id,salary,RANK() over(partition by dep_name order by salary desc) as ranking,COUNT(*) over(partition by dep_name) as maxR from 
[emp]) 

select emp_name,dep_name,salary,ranking from cte where 
ranking=
CASE WHEN maxR>=3 THEN 3
WHEN maxR=2 THEN 2
else 1 end


----Another approach

;with cte as
( select emp_name,dep_name,dep_id,salary,RANK() over(partition by dep_name order by salary desc) as ranking,COUNT(*) over(partition by dep_name) as maxR from 
[emp]) 

select emp_name,dep_name,salary,ranking from cte where ranking=3 or (maxR<3 and ranking=maxR)
