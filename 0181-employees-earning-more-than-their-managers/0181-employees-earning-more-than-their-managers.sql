# Write your MySQL query statement below
SELECT e2.name as Employee
FROM employee e1,employee e2 where e1.id = e2.managerID
and
e1.salary < e2.salary