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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int length(Node* node) {
    int count = 0;
    Node* temp = node;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main(void) {
    Node* node1=createNode(1);
    Node* node2=createNode(2);
    Node* node3=createNode(3);
    Node* node4=createNode(4);
    Node* node5=createNode(5);
    node1->next=node2;
    node2->prev=node1;
    node2->next=node3;
    node3->prev=node2;
    node3->next=node4;
    node4->prev=node3;
    node4->next=node5;
    node5->prev=node4;
    printList(node1);
    printf("length: %d\n", length(node1));

    return 0;
}