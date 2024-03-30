#include <stdio.h>

void heap(int arr[], int length, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }


    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;


        heap(arr, length, largest);
    }
}


void heap_sort(int arr[], int length) {
    
    for (int i = length / 2 - 1; i >= 0; i--) {
        heap(arr, length, i);
    }


    for (int i = length - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;


        heap(arr, i, 0);
    }
}


void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int arr[] = {6, 5, 9, 0, 2, 7, 1, 8, 3, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, length);

    printArray(arr, length);

    return 0;
}
