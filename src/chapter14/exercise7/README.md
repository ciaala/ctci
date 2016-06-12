#14.7 Design Grade Database
Imagine a simple database storing information for students' grades.
Design what is this database might look like and provide a SQL query to return a list of the honor roll students (top 10%), sorted by their grade point average.

Student (**ID**, firstname, surname)
Grade (**ID**, grade)

CREATE VIEW savg as SELECT studentId, avg(grade) as savg FROM exercise.grade group by studentId order by savg desc

select * from (select s.studentId, count(ss.savg) les from savg as s join savg as ss on s.savg >= ss.savg group by s.studentId
order by les desc ) as counted where les > ((SELECT count(distinct(studentid)) from grade )*.8)