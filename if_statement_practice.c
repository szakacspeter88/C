#include <stdio.h>

int main() {
  
  int age;

  printf("\nEnter your age: ");
  scanf("%d",) &age;

  if(age >= 0){
    printf("You are signed up!");
  }
  else if(age < 0){
      printf("You haven't been born yet!"); 
  }
  else {
      printf("You are too joung to sign up!");  
  }
  
  return 0;
}
