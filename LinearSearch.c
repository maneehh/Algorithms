#include <stdio.h>

int linear_search(int arr[], int length, int num) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {66, 5, 87, 45, 9, 115};
    int length = sizeof(arr) / sizeof(arr[0]);
    int num = 9;

    int result = linear_search(arr, length, num);

    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found");
    }

    return 0;
}
