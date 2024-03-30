#include <stdio.h>

int binary_search(int a[], int num, int left, int right);

int main()
{
  int array[] =   {1,2,3,4,5,6,7,8,9,10,11,12,13};
  
  int index = binary_search(array, 12, 0, 12);
  printf("index of 12: %d\n", index);
  
  return 0;
}


int binary_search(int a[], int num, int left, int right)
{
  int mid = left + (right - left) / 2;
  
  if (left > right) return -1;
  
  if (a[mid] == num)
    return mid;
  else if (a[mid] > num)
    return binary_search(a, num, left, mid - 1);
  else
    return binary_search(a, num, mid + 1, right);
  
}