#code for project printer queue system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PrintJob {
    char jobName[100];
    struct PrintJob* next;
};

struct PrintJob* front = NULL;
struct PrintJob* rear = NULL;
void addJob() {
    char name[100];
    printf("\nEnter job name to print: ");
    scanf("%s", name);

    struct PrintJob* newJob = (struct PrintJob*)malloc(sizeof(struct PrintJob));
    strcpy(newJob->jobName, name);
    newJob->next = NULL;

    if (rear == NULL) {
        front = rear = newJob;  // first job
    } else {
        rear->next = newJob;
        rear = newJob;
    }
    printf("Job '%s' added to the queue.\n", name);
}

void printNext() {
    if (front == NULL) {
        printf("\nNo print jobs available.\n");
        return;
    }

    struct PrintJob* temp = front;
    printf("\nPrinting job: %s\n", front->jobName);

    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}
void viewQueue() {
    if (front == NULL) {
        printf("\nNo pending print jobs.\n");
        return;
    }

    printf("\nPending Print Jobs:\n");
    struct PrintJob* temp = front;
    while (temp != NULL) {
        printf("- %s\n", temp->jobName);
        temp = temp->next;
    }
}

int main() {
    int choice;

    printf("=== Simple Printer Queue System ===\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Print Job\n");
        printf("2. Print Next Job\n");
        printf("3. View Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addJob();
                break;

            case 2:
                printNext();
                break;

            case 3:
                viewQueue();
                break;

            case 4:
                printf("\nExiting Printer Queue System. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
