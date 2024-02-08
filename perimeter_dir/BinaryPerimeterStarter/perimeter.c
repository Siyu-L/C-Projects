/*
Function reads vertices from a binary file and finds the perimeter
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vertex_struct {
    int xPos;
    int yPos;

} Vertex;

/*
reads points from fp to vertex array
@param file: file to read from
@param num_points: number of points
@return vertices: list of vertices
*/
Vertex* create_vertex_list(FILE* fp, int num_points) {
    Vertex* vertices = (Vertex*)malloc(num_points * sizeof(Vertex));
    for(int i = 0; i < num_points; i++) {
        fread(&vertices[i].xPos, sizeof(int), 1, fp);
        fread(&vertices[i].yPos, sizeof(int), 1, fp);
    }
    return vertices;
}

/*
gets the distance between two points
@param point1: the first point
@param point2: the second point
*/
double getDistance(Vertex point1, Vertex point2){
    double distance = sqrt(((point1.xPos - point2.xPos) *(point1.xPos - point2.xPos)) +((point1.yPos - point2.yPos) *(point1.yPos - point2.yPos)));
    return distance;

}


int main(int argc, char** argv) {
    FILE* fp = fopen(argv[1], "rb");
    int num_points;
    double totalDist = 0;

    if(fp == NULL){
        printf("Couldn't open file %s\n", argv[1]);
        return -1;
    }
    fread(&num_points, sizeof(int), 1, fp);

    Vertex* verList = create_vertex_list(fp, num_points);

    for(int i = 0; i < num_points-1; i++) {
        totalDist += getDistance(verList[i], verList[i+1]);
    }
    totalDist += getDistance(verList[0], verList[num_points-1]);

    printf("The perimeter is %.2lf", totalDist);
    fclose(fp);
    free(verList);
    verList = NULL;

    return 0;
    

}