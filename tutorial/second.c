#include <stdio.h>

int main(void)
{
  int age = 0;
  
  printf("What is your age: ");
  scanf("%i", &age);
  printf("Happy birthday! You are %i years old!\n", age);
  
  return 0;
}
