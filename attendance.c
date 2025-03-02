#include "attendance.h"

void displayAttendance(const Attendance* attendance) {
    printf("Date: %s | Student ID: %d | Course ID: %d | Status: %s\n", 
           attendance->date, attendance->studentID, attendance->courseID, 
           attendance->isPresent ? "Present" : "Absent");
}
