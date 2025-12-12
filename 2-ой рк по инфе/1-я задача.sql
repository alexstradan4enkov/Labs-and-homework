CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name TEXT NOT NULL,
    group_number TEXT NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name TEXT NOT NULL
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    subject_id INTEGER REFERENCES subjects(subject_id),
    grade INTEGER NOT NULL
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    date_attended DATE NOT NULL,
    status TEXT NOT NULL
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    note_text TEXT NOT NULL
);


INSERT INTO students (full_name, group_number) VALUES
('СУХОВ Иван Алексеевич', 'ПИНБ-1-21'),
('Петров Петр Петрович', 'ПИНБ-1-21'),
('Сидоров Сидор Сидорович', 'ПИНБ-1-21'),
('Кузнецова Анна Сергеевна', 'ПИНБ-1-21'),
('Смирнова Елена Владимировна', 'ПИНБ-1-21'),
('Николаев Максим Алексеевич', 'ПИНБ-1-21');

INSERT INTO subjects (subject_name) VALUES
('Математический анализ'),
('Аналитическая геометрия'),
('Информатика');

INSERT INTO grades (student_id, subject_id, grade) VALUES
(1, 1, 5), (1, 2, 4), (1, 3, 5),
(2, 1, 4), (2, 2, 3), (2, 3, 4),
(3, 1, 3), (3, 2, 3), (3, 3, 3),
(4, 1, 5), (4, 2, 4), (4, 3, 5),
(5, 1, 4), (5, 2, 5), (5, 3, 4),
(6, 1, 3), (6, 2, 3), (6, 3, 3);

INSERT INTO attendance (student_id, date_attended, status) VALUES
(1, '2024-03-01', 'Присутствовал'), (1, '2024-03-02', 'Присутствовал'),
(2, '2024-03-01', 'Присутствовал'), (2, '2024-03-02', 'Отсутствовал'),
(3, '2024-03-01', 'Отсутствовал'), (3, '2024-03-02', 'Присутствовал'),
(4, '2024-03-01', 'Присутствовал'), (4, '2024-03-02', 'Присутствовал'),
(5, '2024-03-01', 'Опоздал'), (5, '2024-03-02', 'Присутствовал'),
(6, '2024-03-01', 'Присутствовал'), (6, '2024-03-02', 'Отсутствовал');

INSERT INTO notes (student_id, note_text) VALUES
(1, 'Отличник по всем предметам'),
(2, 'Хорошо работает в команде'),
(3, 'Редко посещает занятия по информатике'),
(4, 'Любит информатику'),
(5, 'Нужна помощь по информатике'),
(6, 'Прогресс по информатике');


CREATE INDEX idx_students_group ON students(group_number);

CREATE INDEX idx_grades_student ON grades(student_id);

CREATE INDEX idx_notes_text ON notes(note_text);


CREATE VIEW student_avg_grades AS
SELECT 
    s.student_id,
    s.full_name,
    AVG(g.grade) AS average_grade
FROM students s
JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name;


-- добавление нового студента с оценками
BEGIN;
INSERT INTO students (full_name, group_number) VALUES ('Новый студент', 'ПИНБ-1-21');
INSERT INTO grades (student_id, subject_id, grade) VALUES (7, 1, 4), (7, 2, 4), (7, 3, 5);
COMMIT;

-- запросы

SELECT * FROM students 
WHERE group_number = 'ПИНБ-1-21' 
AND student_id BETWEEN 2 AND 6;

SELECT * FROM student_avg_grades 
WHERE full_name ILIKE '%Иванов%';

SELECT AVG(grade) AS Средний_балл_по_информатике
FROM grades g
JOIN subjects s ON g.subject_id = s.subject_id
WHERE s.subject_name = 'Информатика';

SELECT * FROM notes 
WHERE note_text LIKE '%Информатика%';

BEGIN;
UPDATE attendance 
SET status = 'Присутствовал' 
WHERE student_id = 3 
AND date_attended = '2024-03-01';
COMMIT;