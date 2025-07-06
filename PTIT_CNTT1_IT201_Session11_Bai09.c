#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <--> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node* reverse(Node* head) {
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

int main() {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);

    head->next = node1;
    node1->prev = head;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;
    printf("danh sach ban dau: \n");
    display(head);
    head = reverse(head);
    printf("danh sach dao nguoc: \n");
    display(head);
    return 0;
}