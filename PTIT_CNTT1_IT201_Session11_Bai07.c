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
    newNode->next = NULL;
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
int length(Node* head) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}
Node* add(Node* head, int data, int index) {
    if (index < 0 || index > length(head)) {
        printf("vi tri ko hop le\n");
        return head;
    }
    Node* newNode = createNode(data);
    if (index == 0) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        return newNode;
    }

    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    if (current->next == NULL) {
        current->next = newNode;
        newNode->prev = current;
        return head;
    }

    Node* nextNode = current->next;
    current->next = newNode;
    newNode->prev = current;

    newNode->next = nextNode;
    nextNode->prev = newNode;

    return head;
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
    int index, data;
    printf("nhap gia tri muon them: ");
    scanf("%d",&data);
    printf("nhap vi tri muon them: ");
    scanf("%d",&index);
    head = add(head, data, index);
    display(head);
    
    return 0;
}