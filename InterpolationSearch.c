#include <stdio.h>

int interpolation_search(int arr[], int length, int target) {
    int left = 0;
    int right = length - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) 
    {
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);

        if (arr[pos] == target)
            return pos; 

        if (arr[pos] < target)
            left = pos + 1; 
        else
            right = pos - 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int index = interpolation_search(arr, length, target);

    if (index != -1)
        printf("%d found at index %d\n", target, index);
    else
        printf("%d not found\n", target);

    return 0;
}
