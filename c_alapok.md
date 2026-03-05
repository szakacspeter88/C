# C Basics

## Must have

```C
#include <stdio.h>

int main(void)
{

  return 0;
}
```

## Hello World!

```C
#include <stdio.h>

int main(void)
{
  printf("Hello World!\n");
  return 0;
}
```

## Print a number

```C
#include <stdio.h>

int main(void)
{
  int var=15;

  printf("%d\n", var);
  return 0;
}
```

## Scan a Variable and print it


```C
#include <stdio.h>

int main(void)
{
  int var=0;

  printf("Enter a number: ");
  scanf("%d", &var);
  printf("The given number is %d\n", var);

  return 0;
}
```
## Scan a string and print it

```C
#include <stdio.h>

int main(void)
{
  char name[50];

  printf("Enter your name: ");
  scanf("%s", name);
  printf("Hello %s, its nice to have you aboard!\n", name);

  return 0;
}
```

## Request name and age of the user, and print them

```C
#include <stdio.h>

int main(void)
{
  char name[50];
  int age=0;

  printf("Hi It's a pleasure to see you around, what is your name?\n");
  scanf("%s", name);
  printf("Its nice to meet you %s, tell me please, how old are you excatly?\n", name);
  scanf("%d", &age);
  printf("So %s, it's good to know that you are %d years old\n", name, age);

  return 0;
}
```

## Read a number and print its memory address

```C
#include <stdio.h>

int main(void)
{
    int var=0;
    
    printf("I would like to have a number from" 
        "you which I can save for you, please give me a number: \n");
    scanf("%d", &var);
    printf("I saved the number you gave me into the adress, %p\n", &var);

    return 0;

}
```
