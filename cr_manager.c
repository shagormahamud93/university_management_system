
#include <stdio.h>
#include "cr_manager.h"
#include "course_manager.h"  // Make sure this has courseExists()

#define MAX_CRS 100

CR crList[MAX_CRS];
int crCount = 0;

void initCRManager() {
    crCount = 0;
}

void voteForCR(CRVote votes[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Enter student ID for student %d: ", i + 1);
        scanf("%d", &votes[i].studentId);
        printf("Enter number of votes received: ");
        scanf("%d", &votes[i].votes);
    }
}

int findCR(CRVote votes[], int numStudents) {
    int maxVotes = -1;
    int crId = -1;
    for (int i = 0; i < numStudents; i++) {
        if (votes[i].votes > maxVotes) {
            maxVotes = votes[i].votes;
            crId = votes[i].studentId;
        }
    }
    return crId;
}

void assignCRToCourse(int courseId, int crStudentId) {
    addCR(crStudentId, courseId);
}

void addCR(int studentId, int courseId) {
    if (!courseExists(courseId)) {
        printf("Error: Course ID %d does not exist. Please create the course first.\n", courseId);
        return;
    }

    if (crCount < MAX_CRS) {
        crList[crCount].studentId = studentId;
        crList[crCount].courseId = courseId;
        crCount++;
        printf("CR added successfully.\n");
    } else {
        printf("CR list is full.\n");
    }
}

void showAllCRs() {
    if (crCount == 0) {
        printf("No CRs assigned yet.\n");
        return;
    }

    printf("\nAll Course CRs:\n");
    for (int i = 0; i < crCount; i++) {
        printf("Course ID: %d | Student ID (CR): %d\n", crList[i].courseId, crList[i].studentId);
    }
}

void deleteCR(int courseId) {
    int found = 0;
    for (int i = 0; i < crCount; i++) {
        if (crList[i].courseId == courseId) {
            for (int j = i; j < crCount - 1; j++) {
                crList[j] = crList[j + 1];
            }
            crCount--;
            found = 1;
            printf("CR for course %d deleted.\n", courseId);
            break;
        }
    }
    if (!found) {
        printf("No CR found for course %d.\n", courseId);
    }
}

