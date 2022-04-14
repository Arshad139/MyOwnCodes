create table #temp
(
N int NULL,P int NULL)
insert into #temp
values(5,6),(4,6),(6,NULL),(3,5),(2,5),(1,4)

select a.N as aN,a.P as aP,b.N as bN,b.P as bP into #B
from #temp a
left join #temp b on a.N=b.P

select distinct aN as Node,
case when aP is NULL then 'Root'
when bN is NuLL then 'Leaf'
else 'Inner' end as Type from #B order by node desc

--Simplified in below approach without using a join
Select N as Node,
Type = case when P is null then 'Root' 
when n in (Select Distinct p from #temp) then 'Inner' else 'Leaf' end

 from #temp order by Node desc
