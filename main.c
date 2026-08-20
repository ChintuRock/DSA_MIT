
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/* 'head' always points to the FIRST node of the list.
   If the list is empty, head is NULL. */
struct Student *head = NULL;


/* ---------------------------------------------------
   insert()
   Creates a new node using a pointer returned by malloc,
   and links it to the end of the list.
   --------------------------------------------------- */
void insert() {
    struct Student *newNode, *temp;

    /* Create memory for one new student using a pointer */
    newNode = (struct Student *) malloc(sizeof(struct Student));

    /* Read ALL the details first, so we don't leave unread input
       behind if we later find out the ID is a duplicate. */
    printf("Enter Student ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf(" %[^\n]", newNode->name);   /* reads a full line including spaces */

    printf("Enter Age: ");
    scanf("%d", &newNode->age);

    printf("Enter Course: ");
    scanf(" %[^\n]", newNode->course);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;   /* this will be the last node, so next is NULL */

    /* Now check for a duplicate ID before adding the node to the list */
    temp = head;
    while (temp != NULL) {
        if (temp->id == newNode->id) {
            printf("Student with this ID already exists!\n");
            free(newNode);   /* release memory, we don't need it */
            return;
        }
        temp = temp->next;
    }

    /* If list is empty, new node becomes the head */
    if (head == NULL) {
        head = newNode;
    } else {
        /* Otherwise walk to the last node using a pointer 'temp' */
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;   /* link last node's pointer to new node */
    }

    printf("Student record inserted successfully!\n");
}

/* ---------------------------------------------------
   deleteStudent()
   Uses TWO pointers (curr and prev) to unlink a node
   from the list and free its memory.
   --------------------------------------------------- */
void deleteStudent() {
    int id;
    struct Student *curr, *prev;

    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    curr = head;
    prev = NULL;

    /* Move curr forward until we find the id, keeping prev one step behind */
    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        /* Deleting the very first node (the head) */
        head = curr->next;
    } else {
        /* Skip over curr by connecting prev directly to curr->next */
        prev->next = curr->next;
    }

    free(curr);   /* release the memory of the deleted node */
    printf("Student record deleted successfully!\n");
}


/* ---------------------------------------------------
   find()
   Walks through the list using a pointer until it
   finds a matching ID.
   --------------------------------------------------- */
void find() {
    int id;
    struct Student *temp;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n%-8s%-20s%-6s%-15s%-8s\n", "ID", "Name", "Age", "Course", "Marks");
            printf("--------------------------------------------------------\n");
            printf("%-8d%-20s%-6d%-15s%-8.2f\n",
                   temp->id, temp->name, temp->age, temp->course, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student with ID %d not found.\n", id);
}
/* ---------------------------------------------------
   print()
   Walks through the whole list from head to the end,
   moving the pointer one step at a time (temp = temp->next).
   --------------------------------------------------- */
void print() {
    struct Student *temp;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    temp = head;

    printf("\n%-8s%-20s%-6s%-15s%-8s\n", "ID", "Name", "Age", "Course", "Marks");
    printf("--------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-8d%-20s%-6d%-15s%-8.2f\n",
               temp->id, temp->name, temp->age, temp->course, temp->marks);
        temp = temp->next;   /* move pointer to next node */
    }
}


/* ---------------------------------------------------
   main()
   Simple menu-driven loop.
   --------------------------------------------------- */
int main() {
    int choice;

    do {
        printf("\n===== STUDENT DATABASE =====\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Find Student\n");
        printf("6. Print All Students\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: deleteStudent(); break;
            case 3: find(); break;
            case 6: print(); break;
            case 7: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}



