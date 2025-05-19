#include <stdio.h>

#define MAX_STUDENTS 50
#define SUBJECTS 5
//structure defining for students
struct student {
    char name[50];        
    int rollNo;          
    float marks[SUBJECTS]; 
};

int main() {
//setting the values to 0 to set up for initilization and defining the characters as integers
    struct student students[MAX_STUDENTS];
    float totalMarks[MAX_STUDENTS] = {0};
    float averageMarks[MAX_STUDENTS] = {0};
    int numStudents;
    float classAverage = 0.0;
    int topStudentIndex = 0;
    int lowStudentIndex = 0;

    printf("Enter the number of students in the class: ");
    scanf("%d", &numStudents);
//loops so it asks for number of students and based on the amount given, repeatly asks for name and roll number
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNo);
//loop to imput 5 grades for each subject assignment
        for (int j = 0; j < SUBJECTS; j++) {
            float grade;
            do {
                printf("Enter marks for Subject %d: ", j + 1);
                scanf("%f", &grade);
            } while (grade < 0 || grade > 100);

            students[i].marks[j] = grade;
            totalMarks[i] += grade;
        }
//operation to calculate grade given subject assignment
        averageMarks[i] = totalMarks[i] / SUBJECTS;

        if (averageMarks[i] > averageMarks[topStudentIndex]) {
            topStudentIndex = i;
        }
        if (averageMarks[i] < averageMarks[lowStudentIndex]) {
            lowStudentIndex = i;
        }

        classAverage += averageMarks[i];
    }

    classAverage /= numStudents;
//print for visualization of the marks and output
    printf("\n%-20s %-10s %-15s %-15s\n", "Name", "Roll No", "Total Marks", "Average");

    for (int i = 0; i < numStudents; i++) {
        printf("%-20s %-10d %-15.1f %-15.2f\n", students[i].name, students[i].rollNo, totalMarks[i], averageMarks[i]);
    }

    printf("\nClass Average: %.2f\n", classAverage);
    printf("\nHighest Grade: %s (Roll No: %d) - Average: %.2f\n",
           students[topStudentIndex].name,
           students[topStudentIndex].rollNo,
           averageMarks[topStudentIndex]);

    printf("Lowest Grade: %s (Roll No: %d) - Average: %.2f\n",
           students[lowStudentIndex].name,
           students[lowStudentIndex].rollNo,
           averageMarks[lowStudentIndex]);

    return 0;
}

