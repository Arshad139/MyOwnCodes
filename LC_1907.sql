--https://leetcode.com/problems/count-salary-categories/description/?envType=study-plan-v2&envId=top-sql-50
Was good thinking, here from you, the intital thought was to use a cte that has a case statement and then you would aggregate on top of that, but that would miss the default 
  value in the case statement, so you used the exhaustive list as one table of a join. It worked well. There was another un professional solution lol, but that one too had 
  a very less run time. 


/* Write your T-SQL query statement below */
; with cte as (
    select * , case when income < 20000 then 'Low Salary'
                    when income between 20000 and 50000 then 'Average Salary'
                    else 'High Salary'
                end as category
    from Accounts                    
)

Select a.category , SUM(CASe when c.category is null then 0 else 1 end) accounts_count
 from (
    select 'Low Salary' AS category
    union all
    select 'Average Salary' AS category
    union all
    select 'High Salary' AS category
) A left join cte c on a.category = c.category
group by a.category


/* Write your T-SQL query statement below */
select 'High Salary' as category, (select count(*) from Accounts where income > 50000) as accounts_count
union all
select 'Average Salary' as category, (select count(*) from Accounts where income >= 20000 and income <= 50000) as accounts_count
union all
select 'Low Salary' as category, (select count(*) from Accounts where income < 20000) as accounts_count
