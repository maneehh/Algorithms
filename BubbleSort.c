#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int a[], int length);

int main(void)
{
  int a[] = {6, 5, 9, 0, 2, 7, 1, 8, 3, 4};
  int length = 10;

  bubble_sort(a, length);
  
  for (int i = 0; i < length; i++)
    printf("%d\n", a[i]);

  return 0;
}

void bubble_sort(int a[], int length)
{
  bool swapped = false;
  int i = 0;
  
  do 
  {
    swapped = false;

    for (int j = 0; j < (length - 1 - i); j++)
    {
      if (a[j] < a[j + 1])
      {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
      } 
    }
    i++;
  } while (swapped);
}
