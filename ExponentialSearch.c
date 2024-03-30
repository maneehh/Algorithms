#include <stdio.h>

int binary_search(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


int exponential_search(int arr[], int length, int target) {
    if (arr[0] == target)
        return 0; 
    
    int i = 1;
    while (i < length && arr[i] <= target)
        i *= 2;


    return binary_search(arr, i / 2, (i < length ? i : length - 1), target);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int index = exponential_search(arr, length, target);

    if (index != -1)
        printf("%d found at index %d\n", target, index);
    else
        printf("%d not found\n", target);

    return 0;
}