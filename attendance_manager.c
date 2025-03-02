#include "attendance_manager.h"
#include <stdio.h>
#include <string.h>

void markAttendance(AttendanceManager* manager, int studentID, int courseID, const char* date, int status) {
    if (manager->recordCount < MAX_ATTENDANCE_RECORDS) {
        Attendance* record = &manager->records[manager->recordCount++];
        record->studentID = studentID;
        record->courseID = courseID;
        strncpy(record->date, date, 10);  // Copy the date
        record->date[10] = '\0';  // Ensure null-termination
        record->isPresent = status;
        printf("Attendance recorded for Student ID: %d on %s\n", studentID, date);
    } else {
        printf("Attendance record list is full.\n");
    }
}

void showAttendance(AttendanceManager* manager, int studentID) {
    printf("\n===== Attendance for Student ID: %d =====\n", studentID);
    printf("----------------------------------------\n");

    int found = 0;
    for (int i = 0; i < manager->recordCount; i++) {
        if (manager->records[i].studentID == studentID) {
            displayAttendance(&manager->records[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No attendance records found for Student ID: %d\n", studentID);
    }
}

void showCourseAttendance(AttendanceManager* manager, int courseID) {
    printf("\n===== Attendance for Course ID: %d =====\n", courseID);
    printf("----------------------------------------\n");

    int found = 0;
    for (int i = 0; i < manager->recordCount; i++) {
        if (manager->records[i].courseID == courseID) {
            displayAttendance(&manager->records[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No attendance records found for Course ID: %d\n", courseID);
    }
}
