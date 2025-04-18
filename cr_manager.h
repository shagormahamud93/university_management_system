#ifndef CR_MANAGER_H
#define CR_MANAGER_H

typedef struct {
    int studentId;
    int courseId;
} CR;

typedef struct {
    int studentId;
    int votes;
} CRVote;

void initCRManager();
void voteForCR(CRVote votes[], int numStudents);
int findCR(CRVote votes[], int numStudents);
void assignCRToCourse(int courseId, int crStudentId);
void addCR(int studentId, int courseId);
void showAllCRs();
void deleteCR(int courseId);

#endif
