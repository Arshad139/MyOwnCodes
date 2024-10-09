--https://leetcode.com/problems/students-and-examinations/?envType=study-plan-v2&envId=top-sql-50
You broke down the problem well, the decision of using Cross JOIN & then using a case statement inside of COUNT() was the key.
There might be better appproaches than this.

SELECT 
A.student_id, A.student_name, A.subject_name, COUNT(CASE WHEN e.subject_name IS NOT NULL THEN 1 END) attended_exams
FROM 
(SELECT * FROM 
Students 
CROSS JOIN Subjects
)A LEFT JOIN Examinations e
ON A.subject_name = e.subject_name AND e.student_id = A.student_id
GROUP BY A.student_id, A.student_name, A.subject_name
ORDER BY A.student_id, A.subject_name
