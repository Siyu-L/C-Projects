#include <stdio.h>

char toLower(char a) {
    if (a >= 65 && a <= 90) {
        return a + 'a' - 'A';

    }
    else {
        return a;

    }
}

int main() {
    char a;
    printf("Letter please: ");
    scanf("%c", &a); 
    printf("%c\n", toLower(a));
    return 0;
}