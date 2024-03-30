#include <stdio.h>

int main()
{
  int a[] = {6, 5, 9, 0, 2, 7, 1, 8, 3, 4};
  int length = 10;
  
  for (int i = 0; i < length; i++)
  {
    int min = i;
    for (int j = i + 1; j < length; j++)
      if (a[j] > a[min]) min = j;
    
    if (min != i)
    {
      int temp = a[i];
      a[i] = a[min];
      a[min] = temp;
    }
  }

  for (int i = 0; i < length; i++)
    printf("%d\n", a[i]);
  
  return 0;
}
