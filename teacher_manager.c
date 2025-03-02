#include <stdio.h>
#include <string.h>
#include "teacher_manager.h"

// Teacher list and count initialization
Teacher teachers[MAX_TEACHERS];
int teacherCount = 0;

// Add Teacher
void addTeacher(int id, const char *name, const char *department) {
    if (teacherCount >= MAX_TEACHERS) {
        printf("Teacher list is full!\n");
        return;
    }

    teachers[teacherCount].id = id;
    strcpy(teachers[teacherCount].name, name);
    strcpy(teachers[teacherCount].department, department);

    teacherCount++;
    printf("Teacher added successfully.\n");
}

// Show All Teachers
void showAllTeachers() {
    if (teacherCount == 0) {
        printf("No teachers available.\n");
        return;
    }

    printf("\n===== List of Teachers =====\n");
    for (int i = 0; i < teacherCount; i++) {
        printf("ID: %d, Name: %s, Department: %s\n", 
               teachers[i].id, 
               teachers[i].name, 
               teachers[i].department);
    }
}

// Delete Teacher by ID
void deleteTeacher(int id) {
    int found = 0;
    for (int i = 0; i < teacherCount; i++) {
        if (teachers[i].id == id) {
            found = 1;
            // Shift the array elements
            for (int j = i; j < teacherCount - 1; j++) {
                teachers[j] = teachers[j + 1];
            }
            teacherCount--;
            printf("Teacher with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Teacher with ID %d not found!\n", id);
    }
}

// Search Teacher by ID
Teacher* searchTeacherByID(int id) {
    for (int i = 0; i < teacherCount; i++) {
        if (teachers[i].id == id) {
            return &teachers[i];  // Return pointer to teacher
        }
    }
    return NULL;  // Return NULL if not found
}

// Update Teacher Info by ID
void updateTeacherByID(int id, const char *newName, const char *newDepartment) {
    Teacher *teacher = searchTeacherByID(id);
    if (teacher != NULL) {
        strcpy(teacher->name, newName);
        strcpy(teacher->department, newDepartment);
        printf("Teacher information updated successfully.\n");
    } else {
        printf("Teacher with ID %d not found.\n", id);
    }
}
