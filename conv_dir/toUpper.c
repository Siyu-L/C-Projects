#include <stdio.h>

char toUpper(char a) {
    if (a >= 97 && a <= 122) {
        return a - ('a' - 'A');

    }
    else {
        return a;

    }
}

int main() {
    char a;
    printf("Letter please: ");
    scanf("%c", &a); 
    printf("%c\n", toUpper(a));
    return 0;
}