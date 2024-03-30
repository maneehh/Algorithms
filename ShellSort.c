#include <stdio.h>

int main() {
    int a[] = {6, 5, 9, 0, 2, 7, 1, 8, 3, 4};
    int length = 10;
    int gap, i, j, temp;
    
    for (gap = length / 2; gap > 0; gap /= 2) 
    {
        for (i = gap; i < length; i++) {
            temp = a[i];
            
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
    
    for (int i = 0; i < length; i++) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}

