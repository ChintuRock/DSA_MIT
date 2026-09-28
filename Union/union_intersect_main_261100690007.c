#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode_261100690007(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
void insertEnd_261100690007(struct Node **head, int data) {
    struct Node *newNode = createNode_261100690007(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Check if an element already exists
int exists_261100690007(struct Node *head, int data) {
    while (head != NULL) {
        if (head->data == data)
            return 1;

        head = head->next;
    }

    return 0;
}

// Find union of two linked lists
struct Node* findUnion_261100690007(struct Node *list1, struct Node *list2) {
    struct Node *unionList = NULL;

    while (list1 != NULL) {
        if (!exists_261100690007(unionList, list1->data))
            insertEnd_261100690007(&unionList, list1->data);

        list1 = list1->next;
    }

    while (list2 != NULL) {
        if (!exists_261100690007(unionList, list2->data))
            insertEnd_261100690007(&unionList, list2->data);

        list2 = list2->next;
    }

    return unionList;
}

// Display linked list
void display_261100690007(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *unionList;

    int n1, n2, data, i;

    // Input for first list
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);

    printf("Enter elements of List 1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &data);
        insertEnd_261100690007(&list1, data);
    }

    // Input for second list
    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);

    printf("Enter elements of List 2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &data);
        insertEnd_261100690007(&list2, data);
    }

    // Display lists
    printf("\nList 1: ");
    display_261100690007(list1);

    printf("List 2: ");
    display_261100690007(list2);

    // Find union
    unionList = findUnion_261100690007(list1, list2);

    printf("Union: ");
    display_261100690007(unionList);

    return 0;
}
