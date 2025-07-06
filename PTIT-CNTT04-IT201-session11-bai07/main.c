#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* createNode( int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation error");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void print(Node* head) {
    Node* temp = head;
    printf("NULL<-->");
    while (temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
//do dai
int length(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
//them bat ki
Node* insertAtEnd(Node* head, int data,int index) {
    if (index < 0 || index > length(head)) {
        printf("Index is out of range");
        return head;
    }
    //insert dau
    if (index == 0) {
        Node* temp = createNode(data);
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        return temp;
    }
    //insert cuoi
    if (index == length(head) ) {
        Node* node = createNode(data);
        if (head == NULL) {
            return node;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;

        }
        current->next = node;
        node->prev = current;
        return head;
    }
    //insert bat ki
    Node* current = head;
    for (int i=0; i<index ; i++) {
        current = current->next;

    }
    Node* newNode = createNode(data);
    Node* prev = current->prev;
    newNode->next = current;
    current->prev = newNode;
    prev->next = newNode;
    newNode->prev = prev;
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
    print(head);

    head = insertAtEnd(head, 5, 5);
    print(head);


    return 0;
}