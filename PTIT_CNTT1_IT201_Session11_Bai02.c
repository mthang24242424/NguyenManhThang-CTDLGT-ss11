#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct  Node* prev;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next == NULL;
    newNode->prev = NULL;
    return newNode;
}
void display(Node *head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <--> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main(void) {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);

    head->prev = NULL;
    head->next = node1;
    node1->next = node2;
    node1->prev = head;

    node2->next = node3;
    node2->prev = node1;

    node3->next = NULL;
    node3->prev = node2;

    display(head);
    
    return 0;
}