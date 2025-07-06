#include <stdio.h>
#include <stdlib.h>

//cau truc
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
    Node* current = node;
    printf("NULL<-->");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");


}
Node* search(Node* node, int key) {
    Node* current = node;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
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
    int searchkey ;
    printf("Enter the element you want to search: ");
    scanf("%d", &searchkey);

    Node* node = search(node1, searchkey);
    if (node == NULL) {
        printf("False");
    }else {
        printf("True");
    }
    return 0;
}