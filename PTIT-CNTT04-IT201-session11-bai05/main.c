#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation error");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void printList(Node* node) {
    Node* temp = node;
    printf("NULL<-->");
    while (temp != NULL) {
        printf("%d <-->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node* insertNode(Node* node, int data) {
    Node* newNode = createNode(data);
    newNode->next = node;
    if (node != NULL) {
        node->prev = newNode;
    }
    return newNode;
}
int main(void) {
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);
    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    printList(head);

    int add;
    printf("Enter number to add:");
    scanf("%d", &add);
     head = insertNode(head, add);
    printList(head);

    return 0;
}