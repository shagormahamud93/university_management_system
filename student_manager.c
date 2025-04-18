#include "student_manager.h"
#include <stdio.h>
#include <string.h>

static Student students[MAX_STUDENTS];
static int studentCount = 0;

void initStudentManager() {
    studentCount = 0;
}

void addStudent(int id, const char *name, const char *department) {
    if (studentCount < MAX_STUDENTS) {
        students[studentCount].id = id;
        strcpy(students[studentCount].name, name);
        strcpy(students[studentCount].department, department);
        studentCount++;
        printf("Student added successfully.\n");  // Success message
    } else {
        printf("Student list is full.\n");
    }
}

void showAllStudents() {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }

     // Show the "Student List" header
     printf("\n===== Student List =====\n");

    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Department: %s\n", students[i].id, students[i].name, students[i].department);
    }
}


Student* searchStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return &students[i];
        }
    }
    return NULL;
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void updateStudent(int id, const char *name, const char *department) {
    Student* student = searchStudent(id);
    if (student != NULL) {
        strcpy(student->name, name);
        strcpy(student->department, department);
        printf("Student updated successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}

int studentExists(int studentId) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            return 1; // exists
        }
    }
    return 0; // not found
}