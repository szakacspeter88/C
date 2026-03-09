# Birthsday


```C
#include <stdio.h>

int main(void)
{
  
  char name[50];
  int age = 0;
  printf("Hello and welcome.\n");

  printf("I would like to know your name: \n");
  scanf("%s", name);
  printf("Its nece to meet you %s, tell me please how old are you?: \n", name);
  scanf("%d", &age);
  printf("Okay %s, its nice to know that you are %d years old, you have a nice age!\n",name ,age);

  return 0;
}
```
