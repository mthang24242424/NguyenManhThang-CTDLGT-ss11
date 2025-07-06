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

Node* deleteAt(Node* head, int index) {
    int len = length(head);
    if (index < 0 || index >= len) {
        printf("vi tri ko hop le\n");
        return head;
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        return head;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current->next == NULL) {
        current->prev->next = NULL;
        free(current);
        return head;
    }

    Node* prevNode = current->prev;
    Node* nextNode = current->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    free(current);

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
    int index;

    printf("nhap vi tri muon xoa: ");
    scanf("%d",&index);
    head = deleteAt(head, index);
    display(head);
    
    return 0;
}