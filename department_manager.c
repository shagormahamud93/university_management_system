// department_manager.c

#include "department_manager.h"
#include <stdio.h>
#include <string.h>

void addDepartment(DepartmentManager* manager, int departmentID, const char* name) {
    if (manager->departmentCount < MAX_DEPARTMENTS) {
        Department* department = &manager->departments[manager->departmentCount++];
        department->departmentID = departmentID;
        strncpy(department->name, name, sizeof(department->name) - 1);
        department->name[sizeof(department->name) - 1] = '\0';  // Ensure null-termination
        printf("Department '%s' added successfully.\n", name);
    } else {
        printf("Cannot add more departments. List is full.\n");
    }
}

void showAllDepartments(DepartmentManager* manager) {
    if (manager->departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }

    printf("\n===== All Departments =====\n");
    for (int i = 0; i < manager->departmentCount; i++) {
        printf("Department ID: %d, Name: %s\n", manager->departments[i].departmentID, manager->departments[i].name);
    }
}

void deleteDepartment(DepartmentManager* manager, int departmentID) {
    int found = 0;
    for (int i = 0; i < manager->departmentCount; i++) {
        if (manager->departments[i].departmentID == departmentID) {
            // Shift remaining departments left to fill the gap
            for (int j = i; j < manager->departmentCount - 1; j++) {
                manager->departments[j] = manager->departments[j + 1];
            }
            manager->departmentCount--;
            printf("Department with ID %d deleted successfully.\n", departmentID);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Department with ID %d not found.\n", departmentID);
    }
}
