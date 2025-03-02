#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <stdio.h>
#include <string.h>

typedef struct {
    int studentID;
    int courseID;
    char date[11];  // Format: YYYY-MM-DD
    int isPresent;  // 1 = Present, 0 = Absent
} Attendance;

void displayAttendance(const Attendance* attendance);

#endif
