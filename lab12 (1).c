#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBJECTS 5

struct student {
    char name[50];
    int rollNo;
    float marks[SUBJECTS];
    float totalMarks;
    float averageMarks;
    struct student* next;
};

struct student* createStudent() {
    struct student* newStudent = (struct student*)malloc(sizeof(struct student));
    
    if (newStudent == NULL) {
        exit(1);
    }

    printf("Enter student name: ");
    fgets(newStudent->name, 50, stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = 0;
    
    printf("Enter roll number: ");
    scanf("%d", &newStudent->rollNo);
    
    printf("Enter marks (0-100):\n");
    newStudent->totalMarks = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        while (1) {
            printf("Subject %d: ", i + 1);
            scanf("%f", &newStudent->marks[i]);
            if (newStudent->marks[i] >= 0 && newStudent->marks[i] <= 100) {
                break;
            } else {
                printf("Invalid input! Marks should be between 0 and 100. Please enter again.\n");
            }
        }
        newStudent->totalMarks += newStudent->marks[i];
    }
    
    newStudent->averageMarks = newStudent->totalMarks / SUBJECTS;
    newStudent->next = NULL;
    return newStudent;
}

void displayStudent(struct student* s) {
    printf("| %-20s | %-8d | ", s->name, s->rollNo);
    for (int i = 0; i < SUBJECTS; i++) {
        printf("%-6.2f ", s->marks[i]);
    }
    printf("| %-11.2f | %-13.2f |\n", s->totalMarks, s->averageMarks);
}

void calculateClassStatistics(struct student* head) {
    int count = 0;
    float totalAvg = 0;
    float highestAvg = -1;
    float lowestAvg = 101;
    struct student* highestStudent = NULL;
    struct student* lowestStudent = NULL;

    struct student* temp = head;
    while (temp != NULL) {
        count++;
        totalAvg += temp->averageMarks;

        if (temp->averageMarks > highestAvg) {
            highestAvg = temp->averageMarks;
            highestStudent = temp;
        }

        if (temp->averageMarks < lowestAvg) {
            lowestAvg = temp->averageMarks;
            lowestStudent = temp;
        }

        temp = temp->next;
    }

    printf("\nClass Statistics:\n");
    printf("Total Students: %d\n", count);
    printf("Class Average Marks: %.2f\n", totalAvg / count);

    if (highestStudent != NULL) {
        printf("Highest Average Marks: %.2f (Student: %s, Roll No: %d)\n", highestAvg, highestStudent->name, highestStudent->rollNo);
    }

    if (lowestStudent != NULL) {
        printf("Lowest Average Marks: %.2f (Student: %s, Roll No: %d)\n", lowestAvg, lowestStudent->name, lowestStudent->rollNo);
    }
}

void freeList(struct student* head) {
    struct student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct student* head = NULL;
    struct student* tail = NULL;
    int choice;
    while (1) {
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Class Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                struct student* newStudent = createStudent();
                if (head == NULL) {
                    head = newStudent;
                    tail = newStudent;
                } else {
                    tail->next = newStudent;
                    tail = newStudent;
                }
                break;
            }
            case 2: {
                struct student* temp = head;
                if (temp == NULL) {
                    printf("No students in the class!\n");
                } else {
                    printf("\n| Student Name        | Roll No  | Marks      | Total Marks | Average Marks |\n");
                    while (temp != NULL) {
                        displayStudent(temp);
                        temp = temp->next;
                    }
                }
                break;
            }
            case 3:
                calculateClassStatistics(head);
                break;
            case 4:
                freeList(head);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}

