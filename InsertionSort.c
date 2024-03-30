#include <stdio.h>

void insertion_sort(int a[], int length);

int main()
{
  int a[] = {6, 5, 9, 0, 2, 7, 1, 8, 3, 4};
  insertion_sort(a, 10);
  for (int i = 0; i < 10; i++)
    printf("%d\n", a[i]);

  return 0;
}

void insertion_sort(int a[], int length)
{
  for (int i = 1; i < length; i++)
  {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
}
