#include <stdio.h>
#include <string.h>
#include "course_manager.h"
#include "student_manager.h"

// Sample course list (You can define `MAX_COURSES` according to your requirements)
#define MAX_COURSES 100
#define MAX_STUDENTS 100

// Course list and count initialization
Course courses[MAX_COURSES];
int courseCount = 0;

int courseStudents[MAX_COURSES][MAX_STUDENTS]; // This will track students assigned to each course (1 for assigned, 0 for not)

// Add Course
void addCourse(int id, const char *title, const char *description, int duration) {
    if (courseCount >= MAX_COURSES) {
        printf("Course list is full!\n");
        return;
    }

    courses[courseCount].id = id;
    strcpy(courses[courseCount].title, title);
    strcpy(courses[courseCount].description, description);
    courses[courseCount].duration = duration;

    courseCount++;
    printf("Course added successfully.\n");
}

// Show All Courses
void showAllCourses() {
    if (courseCount == 0) {
        printf("No courses available.\n");
        return;
    }

    printf("\n===== List of Courses =====\n");
    for (int i = 0; i < courseCount; i++) {
        printf("ID: %d, Title: %s, Description: %s, Duration: %d hours\n", 
               courses[i].id, 
               courses[i].title, 
               courses[i].description, 
               courses[i].duration);
    }
}

// Delete Course by ID
void deleteCourse(int id) {
    int found = 0;
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == id) {
            found = 1;
            // Shift the array elements
            for (int j = i; j < courseCount - 1; j++) {
                courses[j] = courses[j + 1];
            }
            courseCount--;
            printf("Course with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Course with ID %d not found!\n", id);
    }
}

// Search Course by ID
Course* searchCourseByID(int id) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == id) {
            return &courses[i];  // Return pointer to course
        }
    }
    return NULL;  // Return NULL if not found
}

// Update Course Info by ID
void updateCourseByID(int id, const char *newTitle, const char *newDescription, int newDuration) {
    Course *course = searchCourseByID(id);
    if (course != NULL) {
        strcpy(course->title, newTitle);
        strcpy(course->description, newDescription);
        course->duration = newDuration;
        printf("Course information updated successfully.\n");
    } else {
        printf("Course with ID %d not found.\n", id);
    }
}

void assignStudentToCourse(int studentId, int courseId) {
    // Check if the courseId exists in the courses list
    int courseIndex = -1;
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == courseId) {
            courseIndex = i;
            break;
        }
    }

    if (courseIndex == -1) {
        printf("Invalid Course ID!\n");
        return;  // If the course ID is invalid, exit the function
    }

    // Check if the student is already assigned to the course
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (courseStudents[courseIndex][i] == studentId) {
            printf("Student is already assigned to this course.\n");
            return;  // Student is already assigned, no need to add again
        }
    }

    // Assign student to the course (mark as assigned)
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (courseStudents[courseIndex][i] == 0) {  // Find an empty slot
            courseStudents[courseIndex][i] = studentId;
            printf("Student assigned to the course successfully.\n");
            return;
        }
    }

    printf("Course is full, cannot assign more students.\n");
}


void showStudentsInCourse(int courseId) {
    int courseIndex = -1;
    // Find the course
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == courseId) {
            courseIndex = i;
            break;
        }
    }

    if (courseIndex == -1) {
        printf("Invalid Course ID!\n");
        return;
    }

    printf("Students in course %s (ID: %d):\n", courses[courseIndex].title, courseId);

    // Check the student list for this course
    int found = 0;
    for (int j = 0; j < MAX_STUDENTS; j++) {
        if (courseStudents[courseIndex][j] != 0) { // Check for non-zero (assigned) student ID
            Student *student = searchStudent(courseStudents[courseIndex][j]); // Get the student by ID
            if (student) {
                printf("ID: %d, Name: %s, Department: %s\n", student->id, student->name, student->department);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No students assigned to this course.\n");
    }
}

void removeStudentFromCourse(int studentId, int courseId) {
    int courseIndex = -1;
    // Find the course
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == courseId) {
            courseIndex = i;
            break;
        }
    }

    if (courseIndex == -1) {
        printf("Invalid Course ID!\n");
        return;
    }

    // Remove student from the course
    if (courseStudents[courseIndex][studentId] == 1) {
        courseStudents[courseIndex][studentId] = 0;  // Mark as not assigned
        printf("Student ID %d removed from course ID %d.\n", studentId, courseId);
    } else {
        printf("Student ID %d is not assigned to this course.\n", studentId);
    }
}

// Initialize course manager (e.g., clear or set default values)
void initCourseManager() {
    // Initialize the courses array or any global variables
    for (int i = 0; i < MAX_COURSES; i++) {
        // Set default values for courses if needed
        courses[i].id = -1;
    }
    printf("University Management System.\n");
}

int courseExists(int courseId) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == courseId) {  // Use 'courses' instead of 'courseList'
            return 1;  // Course exists
        }
    }
    return 0;  // Course does not exist
}