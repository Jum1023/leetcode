# Write your MySQL query statement below
select D1.Name as Department,E1.Name as Employee, E1.Salary as Salary
from Employee E1 inner join Department D1 on E1.DepartmentId=D1.Id
where (Select count(distinct Salary) From Employee where DepartmentId=D1.Id and Salary>E1.Salary)<3 