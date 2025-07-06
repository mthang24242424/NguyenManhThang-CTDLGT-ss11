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
Node* search(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            printf("True");
            return;
        }
        current = current->next;
    }
    printf("False");
    return;
}
int main(void) {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);
    Node* node5 = createNode(6);

    head->next = node1;
    node1->next = node2;
    node1->prev = head;

    node2->next = node3;
    node2->prev = node1;

    node3->next = node4;
    node3->prev = node2;

    node4->next = node5;
    node4->prev = node3;

    node5->next = NULL;
    node5->prev = node4;

    int number;
    printf("nhap so nguyen duong bat ki");
    scanf("%d",&number);
    if (number <= 0) {
        printf("so ko hop le");
        return 1;
    }
    search(head, number);
    return 0;
}
