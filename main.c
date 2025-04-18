#include <stdio.h>
#include "student_manager.h"
#include "teacher_manager.h"
#include "course_manager.h"
#include "attendance_manager.h"
#include "department_manager.h"
#include "cr_manager.h"
#include <string.h>

void menu()
{
    printf("\n====== Student Management =====\n");
    printf("1. Add Student\n");
    printf("2. Show All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Delete Student\n");
    printf("5. Update Student Info\n");

    printf("\n===== Add Teacher Management =====\n");
    printf("6. Add Teacher\n");
    printf("7. Show All Teachers\n");
    printf("8. Delete Teacher\n");
    printf("9. Search Teacher by ID\n");
    printf("10. Update Teacher Info\n");

    printf("\n===== Course Management =====\n");
    printf("11. Add Course\n");
    printf("12. Show All Courses\n");
    printf("13. Delete Course\n");
    printf("14. Search Course by ID\n");
    printf("15. Update Course Info\n");

    printf("\n===== Assign Student For Course =====\n");
    printf("16. Assign Student to Course\n");
    printf("17. Show Students in a Course\n");
    printf("18. Remove Student from Course\n");

    printf("\n===== Attendance Management For Student =====\n");
    printf("19. Mark Attendance\n");
    printf("20. Show Attendance for Student\n");
    printf("21. Show Attendance for Course\n");

    printf("\n===== Department Management =====\n");
    printf("22. Add Department\n");
    printf("23. Show All Departments\n");
    printf("24. Delete Department\n");

    printf("\n===== CR Management =====\n");
    printf("25. Add CR\n");
    printf("26. Show All CRs\n");
    printf("27. Delete CR\n");

    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main()
{
    initStudentManager();
    initCourseManager();
    initCRManager();
    AttendanceManager attendanceManager = {0};
    DepartmentManager manager = {0};
    int choice;
    int id, courseId, studentId, departmentID, duration, status;
    char date[11]; // Date format: YYYY-MM-DD
    char name[100], department[100];
    char title[100], description[200];
    char departmentName[100];

    while (1)
    {
        menu();
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice)
        {
            // Add new student
        case 1:
            printf("Enter ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter Name: ");
            fgets(name, sizeof(name), stdin); // read student name
            name[strcspn(name, "\n")] = '\0';
            printf("Enter Department: ");
            fgets(department, sizeof(department), stdin); // read department
            department[strcspn(department, "\n")] = '\0'; // remove newline character
            addStudent(id, name, department);             // call function to add student
            break;
            // Show all students
        case 2:
            showAllStudents();
            break;
            // Search for student by ID
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            Student *s = searchStudent(id);
            if (s != NULL)
            {
                printf("ID: %d, Name: %s, Department: %s\n", s->id, s->name, s->department);
            }
            else
            {
                printf("Student not found.\n");
            }
            break;
            // Delete student by ID
        case 4:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteStudent(id);
            break;
            // Update student information
        case 5:
            printf("Enter ID to update: ");
            scanf("%d", &id);
            getchar();
            printf("Enter New Name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter New Department: ");
            fgets(department, sizeof(department), stdin);
            department[strcspn(department, "\n")] = '\0';
            updateStudent(id, name, department);
            break;

            // Add teacher functionality
        case 6:
            printf("Enter Teacher ID: ");
            scanf("%d", &id);
            getchar(); // consume newline
            printf("Enter Name: ");
            fgets(name, sizeof(name), stdin); // input teacher name
            name[strcspn(name, "\n")] = 0;    // remove newline character
            printf("Enter Department: ");
            fgets(department, sizeof(department), stdin); // input teacher department
            department[strcspn(department, "\n")] = 0;    // remove newline character

            addTeacher(id, name, department); // call function to add teacher
            break;
            // Show all teachers
        case 7:
            showAllTeachers();
            break;
            // Delete teacher by ID
        case 8:
            printf("Enter Teacher ID to delete: ");
            scanf("%d", &id);
            deleteTeacher(id);
            break;

        case 9: // Search Teacher by ID
            printf("Enter Teacher ID to search: ");
            scanf("%d", &id);
            Teacher *t = searchTeacherByID(id);
            if (t)
            {
                printf("Teacher Found: ID: %d, Name: %s, Department: %s\n",
                       t->id, t->name, t->department);
            }
            else
            {
                printf("Teacher with ID %d not found!\n", id);
            }
            break;

        case 10: // Update Teacher Info
            printf("Enter Teacher ID to update: ");
            scanf("%d", &id);
            getchar(); // consume newline
            printf("Enter New Name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // remove newline
            printf("Enter New Department: ");
            fgets(department, sizeof(department), stdin);
            department[strcspn(department, "\n")] = 0; // remove newline

            updateTeacherByID(id, name, department);
            break;

        case 11: // Add Course
            printf("Enter Course ID: ");
            scanf("%d", &id);
            getchar(); // consume newline
            printf("Enter Course Title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // remove newline
            printf("Enter Course Description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0; // remove newline
            printf("Enter Duration (hours): ");
            scanf("%d", &duration);

            addCourse(id, title, description, duration); // Add the course
            break;

        case 12:              // Show All Courses
            showAllCourses(); // Show all courses
            break;

        case 13: // Delete Course
            printf("Enter Course ID to delete: ");
            scanf("%d", &id);
            deleteCourse(id); // Delete the course
            break;

        case 14: // Search Course by ID
            printf("Enter Course ID to search: ");
            scanf("%d", &id);
            Course *c = searchCourseByID(id);
            if (c)
            {
                printf("Course Found: ID: %d, Title: %s, Description: %s, Duration: %d hours\n",
                       c->id, c->title, c->description, c->duration);
            }
            else
            {
                printf("Course with ID %d not found!\n", id);
            }
            break;

        case 15: // Update Course Info
            printf("Enter Course ID to update: ");
            scanf("%d", &id);
            getchar(); // consume newline
            printf("Enter New Title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // remove newline
            printf("Enter New Description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0; // remove newline
            printf("Enter New Duration (hours): ");
            scanf("%d", &duration);

            updateCourseByID(id, title, description, duration); // Update course info
            break;
            // Assign student to course
        case 16:
            printf("Enter Student ID: ");
            scanf("%d", &studentId);
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            assignStudentToCourse(studentId, courseId); // Add function for assigning student to a course
            break;

            // Show all students in a course
        case 17:
            printf("Enter Course ID to show students: ");
            scanf("%d", &courseId);
            showStudentsInCourse(courseId); // Add function to show students in a course
            break;

            // Remove student from course
        case 18:
            printf("Enter Student ID to remove: ");
            scanf("%d", &studentId);
            printf("Enter Course ID to remove student from: ");
            scanf("%d", &courseId);
            removeStudentFromCourse(studentId, courseId); // Add function to remove student from a course
            break;

            // student attendane
        case 19:
            printf("Enter Student ID: ");
            scanf("%d", &studentId);
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            printf("Enter Date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter Status (1 for Present, 0 for Absent): ");
            scanf("%d", &status);
            markAttendance(&attendanceManager, studentId, courseId, date, status);
            break;
        // View attendance
        case 20:
            printf("Enter Student ID: ");
            scanf("%d", &studentId);
            showAttendance(&attendanceManager, studentId);
            break;
            // Course ID to view attendance
        case 21:
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            showCourseAttendance(&attendanceManager, courseId);
            break;
            // Deparment management
        case 22: // Add Department
            printf("Enter Department ID: ");
            scanf("%d", &departmentID);
            getchar(); // To consume newline character after scanf
            printf("Enter Department Name: ");
            fgets(departmentName, sizeof(departmentName), stdin);
            departmentName[strcspn(departmentName, "\n")] = '\0'; // Remove trailing newline
            addDepartment(&manager, departmentID, departmentName);
            break;

        case 23: // Show All Departments
            showAllDepartments(&manager);
            break;

        case 24: // Delete Department
            printf("Enter Department ID to delete: ");
            scanf("%d", &departmentID);
            deleteDepartment(&manager, departmentID);
            break;

        case 25: // Add CR
            printf("Enter Student ID to make CR: ");
            scanf("%d", &studentId);
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            addCR(studentId, courseId);
            break;

        case 26: // Show All CRs
            showAllCRs();
            break;

        case 27: // Delete CR
            printf("Enter Course ID to remove CR: ");
            scanf("%d", &courseId);
            deleteCR(courseId);
            break;

        case 0: // Exit
            printf("Exiting program...\n");
            return 0;
            // Handle invalid menu options
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
