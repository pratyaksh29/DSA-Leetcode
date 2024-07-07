# Write your MySQL query statement below


SELECT project_id, ROUND(SUM(e.experience_years)/COUNT(e.name),2) AS average_years
FROM Project p
LEFT JOIN Employee e
ON p.employee_id = e.employee_id
GROUP BY p.project_id
