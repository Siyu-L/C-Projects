//Program calculates the output of foo, a function of n
#include <stdio.h>

/*
returns the values of foo
@param n: any positive number
@param n0: foo(0)
@param n1: foo(1)
@param n2: foo(2)
@param n3: foo(3)
@return: number based on n
*/
int _foo(int n, int n0, int n1, int n2, int n3) {
    if(n == 0) {
        return n0;
    }
    else if (n == 1) {
        return n1;
    }
    else if (n == 2) {
        return n2;
    }
    else if (n == 3) {
        return n3;
    }
    else {
        return _foo(n-1, n1, n2, n3, n3 + n2 + n1 - n0 + 1);
    }

}



/*
function runs _foo with initial values
@param n: any positive number
@return: number based on n
*/
int foo(int n) {
    return _foo(n, 3, 6, 2, 7);
}


int main() {
    int n;
    int out;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    out = foo(n);
    printf("Foo(%d) = %d", n, out);
    return 0;
}