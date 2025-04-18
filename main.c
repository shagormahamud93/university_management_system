
#include <stdio.h>
#include <string.h>
#include "student_manager.h"
#include "teacher_manager.h"
#include "course_manager.h"
#include "attendance_manager.h"
#include "department_manager.h"
#include "cr_manager.h"

void menu()
{
    printf("\n===== Department Management =====\n");
    printf(" 1. Add Department\n");
    printf(" 2. Show All Departments\n");
    printf(" 3. Delete Department\n");

    printf("\n===== Course Management =====\n");
    printf(" 4. Add Course\n");
    printf(" 5. Show All Courses\n");
    printf(" 6. Search Course by ID\n");
    printf(" 7. Update Course Info\n");
    printf(" 8. Delete Course\n");

    printf("\n===== Teacher Management =====\n");
    printf(" 9.  Add Teacher\n");
    printf("10. Show All Teachers\n");
    printf("11. Search Teacher by ID\n");
    printf("12. Update Teacher Info\n");
    printf("13. Delete Teacher\n");

    printf("\n===== Student Management =====\n");
    printf("14. Add Student\n");
    printf("15. Show All Students\n");
    printf("16. Search Student by ID\n");
    printf("17. Update Student Info\n");
    printf("18. Delete Student\n");

    printf("\n===== Enrollment =====\n");
    printf("19. Assign Student to Course\n");
    printf("20. Show Students in a Course\n");
    printf("21. Remove Student from Course\n");

    printf("\n===== Attendance Management =====\n");
    printf("22. Mark Attendance\n");
    printf("23. Show Attendance for Student\n");
    printf("24. Show Attendance for Course\n");

    printf("\n===== CR Management =====\n");
    printf("25. Conduct CR Vote\n");
    printf("26. Manually Assign CR\n");
    printf("27. Show All CRs\n");
    printf("28. Delete CR\n");

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
    char date[11];
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
        // Department Management
        case 1:
            printf("Enter Department ID: ");
            scanf("%d", &departmentID);
            getchar();
            printf("Enter Department Name: ");
            fgets(departmentName, sizeof(departmentName), stdin);
            departmentName[strcspn(departmentName, "\n")] = '\0';
            addDepartment(&manager, departmentID, departmentName);
            break;
        case 2:
            showAllDepartments(&manager);
            break;
        case 3:
            printf("Enter Department ID to delete: ");
            scanf("%d", &departmentID);
            deleteDepartment(&manager, departmentID);
            break;

        case 4:
            if (manager.departmentCount == 0)
            {
                printf("No departments found. Please add a department before adding a course.\n");
                break;
            }
            printf("Enter Course ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter Course Title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;
            printf("Enter Course Description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0;
            printf("Enter Duration (hours): ");
            scanf("%d", &duration);
            addCourse(id, title, description, duration);
            break;

        case 5:
            showAllCourses();
            break;
        case 6:
            printf("Enter Course ID to search: ");
            scanf("%d", &id);
            {
                Course *c = searchCourseByID(id);
                if (c)
                    printf("Course Found: ID: %d, Title: %s, Description: %s, Duration: %d\n",
                           c->id, c->title, c->description, c->duration);
                else
                    printf("Course with ID %d not found!\n", id);
            }
            break;
        case 7:
            printf("Enter Course ID to update: ");
            scanf("%d", &id);
            getchar();
            printf("Enter New Title: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;
            printf("Enter New Description: ");
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0;
            printf("Enter New Duration (hours): ");
            scanf("%d", &duration);
            updateCourseByID(id, title, description, duration);
            break;
        case 8:
            printf("Enter Course ID to delete: ");
            scanf("%d", &id);
            deleteCourse(id);
            break;

        // Teacher Management
        case 9:
            printf("Enter Teacher ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter Name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            printf("Enter Department: ");
            fgets(department, sizeof(department), stdin);
            department[strcspn(department, "\n")] = 0;
            addTeacher(id, name, department);
            break;
        case 10:
            showAllTeachers();
            break;
        case 11:
            printf("Enter Teacher ID to search: ");
            scanf("%d", &id);
            {
                Teacher *t = searchTeacherByID(id);
                if (t)
                    printf("Teacher Found: ID: %d, Name: %s, Department: %s\n",
                           t->id, t->name, t->department);
                else
                    printf("Teacher with ID %d not found!\n", id);
            }
            break;
        case 12:
            printf("Enter Teacher ID to update: ");
            scanf("%d", &id);
            getchar();
            printf("Enter New Name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            printf("Enter New Department: ");
            fgets(department, sizeof(department), stdin);
            department[strcspn(department, "\n")] = 0;
            updateTeacherByID(id, name, department);
            break;
        case 13:
            printf("Enter Teacher ID to delete: ");
            scanf("%d", &id);
            deleteTeacher(id);
            break;

        // Student Management
        case 14:
            printf("Enter ID: ");
            scanf("%d", &id);
            getchar();
            printf("Enter Name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter Department: ");
            fgets(department, sizeof(department), stdin);
            department[strcspn(department, "\n")] = '\0';
            addStudent(id, name, department);
            break;
        case 15:
            showAllStudents();
            break;
        case 16:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            {
                Student *s = searchStudent(id);
                if (s)
                    printf("ID: %d, Name: %s, Department: %s\n",
                           s->id, s->name, s->department);
                else
                    printf("Student not found.\n");
            }
            break;
        case 17:
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
        case 18:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteStudent(id);
            break;

        // Enrollment
        case 19:
            printf("Enter Student ID: ");
            scanf("%d", &studentId);
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            assignStudentToCourse(studentId, courseId);
            break;
        case 20:
            printf("Enter Course ID to show students: ");
            scanf("%d", &courseId);
            showStudentsInCourse(courseId);
            break;
        case 21:
            printf("Enter Student ID to remove: ");
            scanf("%d", &studentId);
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            removeStudentFromCourse(studentId, courseId);
            break;

        // Attendance Management
        case 22:
            printf("Enter Student ID: ");
            scanf("%d", &studentId);
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            printf("Enter Date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter Status (1=Present,0=Absent): ");
            scanf("%d", &status);
            markAttendance(&attendanceManager, studentId, courseId, date, status);
            break;
        case 23:
            printf("Enter Student ID: ");
            scanf("%d", &studentId);
            showAttendance(&attendanceManager, studentId);
            break;
        case 24:
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            showCourseAttendance(&attendanceManager, courseId);
            break;

        // CR Management
        case 25:
            // Conduct CR Vote
            {
                int total;
                printf("Enter Course ID for CR election: ");
                scanf("%d", &courseId);
                printf("How many students are enrolled in this course? ");
                scanf("%d", &total);
                if (total <= 0 || total > MAX_STUDENTS)
                {
                    printf("Invalid number of students.\n");
                    break;
                }
                int studentIds[total];
                for (int i = 0; i < total; i++)
                {
                    printf("Enter enrolled student #%d ID: ", i + 1);
                    scanf("%d", &studentIds[i]);
                }
                conductCRSelection(courseId, studentIds, total);
                break;
            }
        case 26:
            // Manual CR assign
            printf("Enter Student ID to make CR: ");
            scanf("%d", &studentId);
            printf("Enter Course ID: ");
            scanf("%d", &courseId);
            addCR(studentId, courseId);
            break;
        case 27:
            showAllCRs();
            break;
        case 28:
            printf("Enter Course ID to remove CR: ");
            scanf("%d", &courseId);
            deleteCR(courseId);
            break;

        case 0:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
