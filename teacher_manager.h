#ifndef TEACHER_MANAGER_H
#define TEACHER_MANAGER_H

#define MAX_TEACHERS 100

typedef struct {
    int id;
    char name[100];
    char department[100];
} Teacher;

// Teacher List & Count
extern Teacher teachers[MAX_TEACHERS];
extern int teacherCount;

// Function Declarations
void addTeacher(int id, const char *name, const char *department);
void showAllTeachers();
void deleteTeacher(int id);
Teacher* searchTeacherByID(int id);
void updateTeacherByID(int id, const char *newName, const char *newDepartment);

#endif
