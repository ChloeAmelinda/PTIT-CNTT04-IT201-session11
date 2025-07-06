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
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
//do dai
int length(Node* node) {
    int count = 0;
    Node* temp = node;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
//xoa dau
Node* removeNode(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    Node* temp = node;
    node = node->next;
    if (node == NULL) {
        node->prev = NULL;
    }
    free(temp);
    return node;
}
//xoa cuoi
Node* removeEnd(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->next == NULL) {
        free(node);
        return NULL;
    }
    Node* current = node;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return node;

}
//xoa bat ki
Node* removeAt(Node* head ,int index) {
    if (index <0 || index > length(head)-1) {
        printf("Invalid index\n");
        return head;

    }
    if (index == 0) {
        return removeNode(head);
    }
    if (index == length(head) - 1) {
        return removeEnd(head);
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;

    }
    Node* prev = current->prev;
    Node* next = current->next;
    Node* temp = current;
    prev->next = next;
    next->prev = prev;
    free(temp);
    return head;

}
int main(void) {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    printList(head);
    head = removeAt(head,4);
    printList(head);
    return 0;
}