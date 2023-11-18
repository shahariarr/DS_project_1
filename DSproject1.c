#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for student information
struct Student {
    char id[10];
    char name[50];
    char section[5];
    float cgpa;
    char semester[15];
    struct Student *next; // Pointer to the next student in the linked list
};

// Function to add a student to the linked list
struct Student* addStudent(struct Student *head) {
    struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Student ID: ");
    scanf("%s", newStudent->id);

    printf("Enter Student Name: ");
    scanf("%s", newStudent->name);

    printf("Enter Section: ");
    scanf("%s", newStudent->section);

    printf("Enter CGPA: ");
    scanf("%f", &newStudent->cgpa);

    printf("Enter Semester: ");
    scanf("%s", newStudent->semester);

    newStudent->next = head; // Insert at the beginning of the list
    return newStudent;
}

// Function to display the list of students
void displayStudents(struct Student *head) {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    printf("| %-9s | %-20s | %-7s | %-4s | %-11s |\n", "ID", "Name", "Section", "CGPA", "Semester");
    printf("|-----------|----------------------|---------|------|-------------|\n");

    struct Student *current = head;
    while (current != NULL) {
        printf("| %-9s | %-20s | %-7s | %-4.2f | %-11s |\n", current->id, current->name, current->section, current->cgpa, current->semester);
        current = current->next;
    }
}

// Function to search for a student by ID
void searchStudent(struct Student *head, char targetId[10]) {
    struct Student *current = head;
    while (current != NULL) {
        if (strcmp(current->id, targetId) == 0) {
            printf("Student found:\n");
              printf("| %-9s | %-20s | %-7s | %-4s | %-11s |\n", "ID", "Name", "Section", "CGPA", "Semester");
    printf("|-----------|----------------------|---------|------|-------------|\n");
            printf("| %-9s | %-20s | %-7s | %-4.2f | %-11s |\n", current->id, current->name, current->section, current->cgpa, current->semester);
            return;
        }
        current = current->next;
    }

    printf("Student with ID %s not found.\n", targetId);
}

// Function to free the memory allocated for the linked list
void freeList(struct Student *head) {
    struct Student *current = head;
    while (current != NULL) {
        struct Student *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Student *head = NULL;
    int choice;
    char targetId[10];

    do {
        printf("\nStudent Management System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addStudent(head);
                break;
            case 2:
                displayStudents(head);
                break;
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%s", targetId);
                searchStudent(head, targetId);
                break;
            case 4:
                // Free the memory before exiting
                freeList(head);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
