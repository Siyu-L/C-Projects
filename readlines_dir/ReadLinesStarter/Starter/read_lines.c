/*Program reads lines from a file into an array*/

#include <stdlib.h>
#include <stdio.h>

#include "read_lines.h"

/*reads a single line from fp into lines
@param fp: pointer to file being read
@param lines: array of strings for each line
@param i: index of which line is being read
@modifies: lines
*/

void read_line(FILE* fp, char*** lines, int i) {
    char letter;
    fscanf(fp, "%c", &letter);
    int j = 0;
    while (letter != '\n' && !feof(fp)) {
      (*lines)[i] = (char*)realloc((*lines)[i], (j+2) * sizeof(char));
      (*lines)[i][j] = letter;
      fscanf(fp, "%c", &letter);
      j++;
    }    
    (*lines)[i] = (char*)realloc((*lines)[i], (j+2) * sizeof(char));
    (*lines)[i][j] = '\n';
    (*lines)[i][j+1] = '\0';


  return;

}



void read_lines(FILE* fp, char*** lines, int* num_lines) {
  /*
      read all of the lines in fp into lines and set num_lines to be the total number of lines in the file.
      @fp: a file pointer opened in read mode
      @lines: a pointer indicating where the lines should be placed. If there are no lines in a fill, lines
              will be set to NULL
      @num_lines: a pointer to the number of lines. set to the number of lines contained within lines
      @modifies: lines, num_lines
  */

  char tempLet = '\0';
  *lines = NULL;
  *num_lines = 0;
  fscanf(fp, "%c", &tempLet);

//counts number of lines based on number of newlines
  while(!feof(fp)) {

    if(tempLet == '\n') {
      (*num_lines)++;
    }
    fscanf(fp, "%c", &tempLet);
  }

//if there are no newlines, check if there is only 1 line and file is not empty

  fseek(fp, 0, SEEK_SET);
  fscanf(fp, "%c", &tempLet);
  if (!feof(fp) && *num_lines == 0) {
    *num_lines = 1;
  }



  *lines = (char**)malloc((*num_lines) * sizeof(char*));


  fseek(fp, 0, SEEK_SET);


  for(int i = 0; i < *num_lines; i++) {
    read_line(fp, lines, i);
  }

  return;
}
