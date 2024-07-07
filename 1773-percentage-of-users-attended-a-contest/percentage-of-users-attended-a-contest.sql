# Write your MySQL query statement below



SELECT contest_id, ROUND(COUNT(DISTINCT r.user_id)/COUNT(DISTINCT u.user_id) * 100,2) AS percentage
FROM Users u
CROSS JOIN Register r
GROUP BY contest_id
ORDER BY percentage DESC,contest_id