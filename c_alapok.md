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

## Scan a Variable


```C
#include <stdio.h>

int main(void)
{
  int var=0;

  printf("Enter a number: ")
  scanf("%d", &var);
  printf("The given number is %d", var);

  return 0;
}
```
