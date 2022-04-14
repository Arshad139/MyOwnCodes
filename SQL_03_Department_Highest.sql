;with cte as
(
select departmentID,max(salary) as max_salary from employee group by departmentid
)


select d.name as Department,e.name as Employee,c.max_salary as salary

from employee e join cte c on 
e.departmentID=c.departmentID

join department d on d.ID=c.departmentID

where e.salary=c.max_salary 
