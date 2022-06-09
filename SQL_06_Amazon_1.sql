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
---------------
CREATE TABLE [emp](
 [emp_id] [int] NULL,
 [emp_name] [varchar](50) NULL,
 [salary] [int] NULL,
 [manager_id] [int] NULL,
 [emp_age] [int] NULL,
 [dep_id] [int] NULL,
 [dep_name] [varchar](20) NULL,
 [gender] [varchar](10) NULL
) ;
insert into emp values(1,'Ankit',14300,4,39,100,'Analytics','Female')
insert into emp values(2,'Mohit',14000,5,48,200,'IT','Male')
insert into emp values(3,'Vikas',12100,4,37,100,'Analytics','Female')
insert into emp values(4,'Rohit',7260,2,16,100,'Analytics','Female')
insert into emp values(5,'Mudit',15000,6,55,200,'IT','Male')
insert into emp values(6,'Agam',15600,2,14,200,'IT','Male')
insert into emp values(7,'Sanjay',12000,2,13,200,'IT','Male')
insert into emp values(8,'Ashish',7200,2,12,200,'IT','Male')
insert into emp values(9,'Mukesh',7000,6,51,300,'HR','Male')
insert into emp values(10,'Rakesh',8000,6,50,300,'HR','Male')
insert into emp values(11,'Akhil',4000,1,31,500,'Ops','Male')
