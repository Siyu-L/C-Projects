//Program counts the number of words in a given file

#include <stdio.h>
#include <ctype.h>


/*
counts the number of words based on whitespaces
@param inFile: file to read words from
@param letter: current letter being read
@param count: number of words
*/
void count_words(FILE* inFile, char* letter, int* count) {
        if(isspace(*letter)) {
          (*count)++;
          fscanf(inFile, " %c", letter);
        }
        else {
        fscanf(inFile, "%c", letter);
        }
}

/*
ends the count and prints out the result
@param letter: last letter read from file
@param count: number of words
*/
void end_count(char letter, int* count) {
    if(!isspace(letter) && letter != '\0') {
      (*count)++;
    }

    printf("There are %d word(s).\n", *count);

}

int main(int argc, char** argv) {
    FILE* inFile = NULL;
    char fileLet = '\0';
    int count = 0;

    inFile = fopen(argv[1], "r");
    if (inFile == NULL) {
      printf("Could not open file.\n");
      return -1;
    }

    fscanf(inFile, " %c", &fileLet);

    while(!feof(inFile)) {
        count_words(inFile, &fileLet, &count);
    }

    end_count(fileLet, &count);

    fclose(inFile);
    

    return 0;
}