#include <stdio.h>

int getMax(int a[], int length) {
    int max = a[0];
    for (int i = 1; i < length; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}


void counting_sort(int a[], int length, int exp) {
    int output[length]; 
    int count[10] = {0};
    
    for (int i = 0; i < length; i++) {
        count[(a[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = length - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < length; i++) {
        a[i] = output[i];
    }
}

void radix_sort(int a[], int length) {
    int max = getMax(a, length);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort(a, length, exp);
    }
}

int main() {
    int a[] = {65, 34, 89, 17, 5, 11, 90};
    int length = sizeof(a) / sizeof(a[0]);
    radix_sort(a, length);

    for (int i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
