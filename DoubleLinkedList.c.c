#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* last;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->last = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->last = current;
    return head;
}

Node* search(Node* head, int key) {
    Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    return current;
}

Node* delete(Node* head, int key) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->last = NULL;
        }
        free(temp);
        return head;
    }
    Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Not found.\n");
        return head;
    }
    current->last->next = current->next;
    if (current->next != NULL) {
        current->next->last = current->last;
    }
    free(current);
    return head;
}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);

    printf("List: ");
    display(head);

    int key = 30;
    Node* result = search(head, key);
    if (result != NULL) {
        printf("%d is found in the list.\n", key);
    } else {
        printf("%d is not found.\n", key);
    }

    key = 20;
    head = delete(head, key);
    printf("List after deleting %d: ", key);
    display(head);

    return 0;
}
