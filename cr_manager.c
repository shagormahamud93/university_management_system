
#include "cr_manager.h"
#include <stdio.h>
#include <string.h>

static CR crList[MAX_COURSES];
static int crCount = 0;

void initCRManager() {
    crCount = 0;
}

void assignCR(const char *courseName, int studentId) {
    Student* student = searchStudent(studentId);
    if (student == NULL) {
        printf("Student with ID %d not found.\n", studentId);
        return;
    }

    // Check if CR already assigned to the course
    for (int i = 0; i < crCount; i++) {
        if (strcmp(crList[i].courseName, courseName) == 0) {
            crList[i].studentId = studentId;
            printf("CR updated for course '%s'.\n", courseName);
            return;
        }
    }

    // Add new CR assignment
    if (crCount < MAX_COURSES) {
        strcpy(crList[crCount].courseName, courseName);
        crList[crCount].studentId = studentId;
        crCount++;
        printf("CR assigned successfully for course '%s'.\n", courseName);
    } else {
        printf("CR list is full.\n");
    }
}

void removeCR(const char *courseName) {
    for (int i = 0; i < crCount; i++) {
        if (strcmp(crList[i].courseName, courseName) == 0) {
            for (int j = i; j < crCount - 1; j++) {
                crList[j] = crList[j + 1];
            }
            crCount--;
            printf("CR removed from course '%s'.\n", courseName);
            return;
        }
    }
    printf("CR not found for course '%s'.\n", courseName);
}

void viewCR(const char *courseName) {
    for (int i = 0; i < crCount; i++) {
        if (strcmp(crList[i].courseName, courseName) == 0) {
            Student* student = searchStudent(crList[i].studentId);
            if (student != NULL) {
                printf("Course: %s\nCR: %s (ID: %d, Department: %s)\n",
                       courseName, student->name, student->id, student->department);
            } else {
                printf("CR student not found.\n");
            }
            return;
        }
    }
    printf("No CR assigned for course '%s'.\n", courseName);
}

void showAllCRs() {
    if (crCount == 0) {
        printf("No CRs assigned.\n");
        return;
    }

    printf("\n===== All CRs =====\n");
    for (int i = 0; i < crCount; i++) {
        Student* student = searchStudent(crList[i].studentId);
        if (student != NULL) {
            printf("Course: %s -> CR: %s (ID: %d, Dept: %s)\n",
                   crList[i].courseName, student->name, student->id, student->department);
        }
    }
}
