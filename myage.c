#include <stdio.h>

int main() {
    // 1. Variable declaration (allocating space in memory)
    char nev[50];    // String for the name, max 50 characters
    int kor;         // Integer for the age
    int szaz_ev;     // Variable to store the calculated result

    printf("--- Welcome to my C program! ---\n\n");

    // 2. Getting user input
    printf("What is your name? ");
    scanf("%s", nev); // %s tells the program to expect a string

    printf("How old are you? ");
    scanf("%d", &kor); // %d expects an integer, & points to the memory address of the variable

    // 3. Logical calculation
    szaz_ev = 2026 + (100 - kor);

    // 4. Printing the result
    printf("\nDear %s! \n", nev);
    printf("You are %d years old.\n", kor);
    printf("Your 100th birthday will be in: %d.\n", szaz_ev);

    return 0;
}
