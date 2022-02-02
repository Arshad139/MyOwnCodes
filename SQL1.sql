/* 
-- Using CTE It took 2267 ms
;with CTE_Sal(Employee,ESalary,MSalary) as(
select e.name,e.salary,m.salary from Employee e
left join Employee m
on e.managerId=m.id
)
select Employee from CTE_Sal where ESalary>MSalary*/

2. Using Join was the fastest. It took 1760 ms
/*
select e.name as [Employee] from Employee e
join Employee m
on e.managerId=m.id
and e.salary>m.salary
*/

3. Using Sub query . Second fastest with 1762 ms
select name as Employee from Employee e 
where salary>(
select salary from Employee m where m.id=e.managerId
)
