#include <stdio.h>

int main() {
    int a[] = {6, 5, 9, 0, 2, 7, 1, 8, 3, 4};
    int length = 10;
    
    int left = 0;
    int right = length - 1;
    int swapped = 1;
    
    while (left < right && swapped) {
        swapped = 0;
        
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) 
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapped = 1;
            }
        }
        right--;
        
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) 
            {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                swapped = 1;
            }
        }
        left++;
    }
    
    for (int i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}
