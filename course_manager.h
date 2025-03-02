#ifndef COURSE_MANAGER_H
#define COURSE_MANAGER_H

typedef struct {
    int id;
    char title[100];
    char description[200];
    int duration;  // in hours
} Course;
void initCourseManager();
void addCourse(int id, const char* title, const char* description, int duration);
void showAllCourses();
void deleteCourse(int id);
Course* searchCourseByID(int id);
void updateCourseByID(int id, const char* title, const char* description, int duration);

void assignStudentToCourse(int studentId, int courseId);
void showStudentsInCourse(int courseId);
void removeStudentFromCourse(int studentId, int courseId);

#endif // COURSE_MANAGER_H
