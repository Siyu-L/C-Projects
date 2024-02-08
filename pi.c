/*
Program estimates pi using the probability of a point being inside a circle
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

//rand_double function from assignment description

double rand_double(double low, double high) {
/*
generate a random double between low and high inclusive
@low: the lowest possible double that can be generated
@high: the highest possible double that can be generated
@returns: a random number between low and high
*/
  return low + ((double) rand()) / (((double) RAND_MAX / (high - low)));
}


/*
determines whether a coordinate is in the circle
@param x: x coordinate
@param y: y coordinate
@return: true if the point is in the circle, false otherwise
*/
bool inCircle(double x, double y) {
    return (sqrt(x*x + y*y) <= 1);
}

/*
counts the number of times a point is in the circle
@param iterations: the number of random coordinates to be generated
@return: number of points in the circle
*/
int numInside(int iterations) {
    int count = 0;
    for(int i = 0; i<iterations; i++) {
        double x = rand_double(-1, 1);
        double y = rand_double(-1, 1);
        if(inCircle(x, y)) {
            count++;
        }
    }    
    return count;
}

int main() {
    int seed;
    int iterations;
    int insideCircle;
    double probability;
    printf("Enter the seed for the random number generator: ");
    scanf("%d", &seed);
    srand(seed);
    
    printf("Enter the number of iterations to run: ");
    scanf("%d", &iterations);
    
    insideCircle = numInside(iterations);
    probability = (double)(insideCircle) / iterations;

    printf("The value of pi is %.2lf.\n", probability * 4);
    return 0;
}