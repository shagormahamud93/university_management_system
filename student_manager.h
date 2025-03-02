#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[100];
    char department[100];
} Student;

void initStudentManager();
void addStudent(int id, const char *name, const char *department);
void showAllStudents();
Student* searchStudent(int id);
void deleteStudent(int id);
void updateStudent(int id, const char *name, const char *department);

#endif
