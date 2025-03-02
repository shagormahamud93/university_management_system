#ifndef ATTENDANCE_MANAGER_H
#define ATTENDANCE_MANAGER_H

#include "attendance.h"

#define MAX_ATTENDANCE_RECORDS 100

typedef struct {
    Attendance records[MAX_ATTENDANCE_RECORDS];
    int recordCount;
} AttendanceManager;

void markAttendance(AttendanceManager* manager, int studentID, int courseID, const char* date, int status);
void showAttendance(AttendanceManager* manager, int studentID);
void showCourseAttendance(AttendanceManager* manager, int courseID);

#endif
