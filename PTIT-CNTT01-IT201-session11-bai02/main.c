#include <stdio.h>
#include <stdlib.h>

//cau truc node
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
//ham khoi tao va lien ket
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed for Node.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//in
void printList(Node* newNode) {
    Node* current = newNode;
    printf("NULL<-->");
    while (current != NULL) {
        printf("%d<-->", current->data);
        current = current->next;
    }
    printf("<-->NULL\n");
}
int main(void) {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    printList(node1);
    return 0;
}