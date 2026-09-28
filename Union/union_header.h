#ifndef UNION_HEADER_H_INCLUDED
#define UNION_HEADER_H_INCLUDED

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode_261100690007(int data);
void insertEnd_261100690007(struct Node **head, int data);
int exists_261100690007(struct Node *head, int data);
struct Node* findUnion_261100690007(struct Node *list1, struct Node *list2);
void display_261100690007(struct Node *head);

#endif // UNION_HEADER_H_INCLUDED
