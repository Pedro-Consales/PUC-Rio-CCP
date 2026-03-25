#include <stdio.h>
#define LIM 1

int filtro(int x, int lim);

int nums[5] = {3,-5,7,8,-2};

int main() {
  int i;
  i = 0;
  int *p; 
  p = nums;
  while(i < 5) {
    int temp = filtro(*p,LIM);
    printf("%d\n", temp);
    p++;
    i++;
  }
  return 0;
}