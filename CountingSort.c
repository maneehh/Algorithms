#include <stdio.h>

void counting_sort(int a[], int length) {
    int max = 0;
    
    for (int i = 0; i < length; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    int output[length];
    for (int i = length - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < length; i++) {
        a[i] = output[i];
    }
}

int main() {
    int a[] = {6, 5, 9, 0, 2, 7, 1, 8, 3, 4};
    int length = 10;

    counting_sort(a, length);
    for (int i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}

