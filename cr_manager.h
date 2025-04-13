
#ifndef CR_MANAGER_H
#define CR_MANAGER_H

#include "student_manager.h"

#define MAX_COURSES 100

typedef struct {
    char courseName[100];
    int studentId; // Stores CR's student ID
} CR;

void initCRManager();
void assignCR(const char *courseName, int studentId);
void removeCR(const char *courseName);
void viewCR(const char *courseName);
void showAllCRs();

#endif
