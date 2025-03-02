// department_manager.h

#ifndef DEPARTMENT_MANAGER_H
#define DEPARTMENT_MANAGER_H

#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 100

// Department structure
typedef struct {
    int departmentID;
    char name[100];
} Department;

// DepartmentManager structure
typedef struct {
    Department departments[MAX_DEPARTMENTS];
    int departmentCount;
} DepartmentManager;

// Function prototypes
void addDepartment(DepartmentManager* manager, int departmentID, const char* name);
void showAllDepartments(DepartmentManager* manager);
void deleteDepartment(DepartmentManager* manager, int departmentID);

#endif
