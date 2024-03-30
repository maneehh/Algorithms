#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** bucket, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *bucket;
    *bucket = newNode;
}

void sortBucket(struct Node** bucket) {
    struct Node* current = *bucket;
    struct Node* nextNode;
    int temp;
    if (current == NULL || current->next == NULL) {
        return;
    }
    do {
        nextNode = current->next;
        while (nextNode != NULL) {
            if (current->data > nextNode->data) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    } while (current->next != NULL);
}

void concatenateBuckets(struct Node** buckets, int arr[], int length) {
    int index = 0;
    for (int i = 0; i < length; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }
}

void bucketSort(int arr[], int length) {
    int numBuckets = length;
    struct Node* buckets[numBuckets];

    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < length; i++) {
        int bucketIndex = arr[i] * numBuckets / (100 + 1);
        insertNode(&buckets[bucketIndex], arr[i]);
    }

    for (int i = 0; i < numBuckets; i++) {
        sortBucket(&buckets[i]);
    }
    concatenateBuckets(buckets, arr, length);
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int arr[] = {6, 5, 9, 0, 2, 7, 1, 8, 3, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, length);

    printArray(arr, length);

    return 0;
}