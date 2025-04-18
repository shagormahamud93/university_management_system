#include "student_manager.h"
#include "course_manager.h"   // courseExists
#include "cr_manager.h"
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



void conductCRSelection(int courseId, int studentIds[], int totalStudents) {
    if (!courseExists(courseId)) {
        printf("Course does not exist.\n");
        return;
    }

    CRVote votes[MAX_STUDENTS];

    // Initialize votes
    for (int i = 0; i < totalStudents; i++) {
        votes[i].studentId = studentIds[i];
        votes[i].votes = 0;
    }

    printf("\n=== CR Voting Process Started ===\n");

    // Every student will vote
    for (int i = 0; i < totalStudents; i++) {
        int voterId = studentIds[i];

        printf("\nStudent ID %d is voting:\n", voterId);
        printf("Enter the ID of the student you want to vote for: ");
        int voteFor;
        scanf("%d", &voteFor);

        // Check if voteFor is valid.
        int found = 0;
        for (int j = 0; j < totalStudents; j++) {
            if (votes[j].studentId == voteFor) {
                votes[j].votes++;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Invalid vote! Student ID %d not in candidate list.\n", voteFor);
        }
    }

    // The student with the highest number of votes is selected
    int selectedCRId = findCR(votes, totalStudents);
    printf("\nCR selected for course %d: Student ID %d\n", courseId, selectedCRId);

    // Assign CR
    assignCRToCourse(courseId, selectedCRId);
}