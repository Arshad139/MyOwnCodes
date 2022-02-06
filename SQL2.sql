
--Write an SQL query to report the second highest salary from the Employee table. If there is no second highest salary, the query should report null.

/* Write your T-SQL query statement below */

select max(salary) as SecondHighestSalary from Employee e where
e.salary not in 
(select top 1 e1.salary from Employee e1 order by e1.salary desc)

--You can also use OFFSET
