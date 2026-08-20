#ifndef STUDENT_H
#define STUDENT_H

/* ---------------------------------------------------
   Structure for one student record.
   'next' is a POINTER to another struct Student.
   This is what makes it a "linked list" node.
   --------------------------------------------------- */
struct Student {
    int id;
    char name[50];
    int age;
    char course[30];
    float marks;
    struct Student *next;   /* pointer to the next student in the list */
   // struct Student *prev;   /* pointer to the previous node */
};

/* Function declarations (defined in main.c) */
void insert();
void deleteStudent();
void find();
void print();

#endif /* STUDENT_H */
