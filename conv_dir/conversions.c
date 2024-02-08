#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isValidFormat(const int numArgsNeeded, const int numArgsRead, bool isLastElement);

int getValidInt(const bool isLastElementOnLine);
char getValidChar(const bool isLastElementOnLine);
double getValidDouble(const bool isLastElementOnLine);

/*
Input validation code and documentation copied from class source code. 
*/

/**
 *
 * @param numArgsNeeded: the number of format placeholders that needed to have been read in the last scanf
 * @param numArgsRead: the actual number of placeholders that were read from scanf, ie its return value
 * @param isLastElementOnLine: true if this is the last value that should be on this line of input
 * @return: true if the input is correctly formatted and false otherwise
 */
 bool isValidFormat(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line){
	 bool format_is_correct = num_args_read == num_args_needed;
	 if(should_be_last_value_on_line){
		char should_be_newline = '?';
		scanf("%c", &should_be_newline);
		format_is_correct = format_is_correct && should_be_newline == '\n';
	 }
	 return format_is_correct;
 }

/**
 * Get an integer from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return a valid integer
 */
int getValidInt(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  int num;

  numArgsRead = scanf(" %d", &num);
  if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
    return num;
  } else {
    printf("Format Error\n");
    exit(0);
  }
}

/**
 * Get a character  from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return a valid character
 */
char getValidChar(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  char theCharacter;

  numArgsRead = scanf(" %c", &theCharacter);
  if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
    return theCharacter;
  } else {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  }
}


/**
 * Get a double from the user but close the program if one is not entered
 * @param isLastElementOnLine : true if this is the last value that should be on this line of input
 * @return a valid double
 */
double getValidDouble(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  double num;

  numArgsRead = scanf(" %lf", &num);
  if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
    return num;
  } else {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  }
}

/**
 * Get a char and returns the lower case
 * @param a : any character
 * @return lower case of upper case letters, the character if its not in upper case
 */
char toLower(char a) {
    if (a >= 65 && a <= 90) {
        return a + 'a' - 'A';

    }
    else {
        return a;

    }
}
/**
 * Get a char and returns the upper case
 * @param a : any character
 * @return upper case of lower case letters, the character if its not in lower case
 */
char toUpper(char a) {
    if (a >= 97 && a <= 122) {
        return a - ('a' - 'A');

    }
    else {
        return a;

    }
}

/**
 * Get a char, returns true if its a valid temperature unit, exits program otherwise
 * @param unit: any character
 * @return true if valid temperature unit
 */
bool isValidTempUnit(char unit) {
    if(toLower(unit) != 'f' && toLower(unit) != 'c'&& toLower(unit) != 'k') {
        printf("%c is not a valid temperature type. Ending program.", toUpper(unit));
        exit(0);
        }
    else {
      return true;

    }

}
/**
 * Get a char, returns true if its a valid distance unit, exits program otherwise
 * @param unit: any character
 * @return true if valid distance unit
 */
bool isValidDistUnit(char unit) {
    if(toLower(unit) != 'i' && toLower(unit) != 'f' && toLower(unit) != 'y' && toLower(unit) != 'm') {
      printf("%c is not a valid distance type. Ending program.", toUpper(unit));
      exit(0);
    }
    else {
      return true;

    }
        
}

/**
 * Get double and unit to convert, performs calculations and returns double
 * @param num: a valid double of Celsius unit
 * @param unit: either 'c', 'f', or 'k'
 * @return a double of the new unit
 */
double CConv(double num, char unit) {
  switch(unit) {
    case 'c': 
      return num;
    case 'f':
      return (9.0/5) * num + 32;
    case 'k':
      return num + 273.15;
    default:
      return num;
  }

/**
 * Get double and unit to convert, performs calculations and returns double
 * @param num: a valid double of Fahrenheit unit
 * @param unit: either 'c', 'f', or 'k'
 * @return a double of the new unit
 */
}
double FConv(double num, char unit) {
  switch(unit) {
    case 'f':
      return num;
    case 'c':
      return (num-32) * (5.0/9);
    case 'k':
      return (num-32) * (5.0/9) + 273.15;
    default:
      return num;
  }

/**
 * Get double and unit to convert, performs calculations and returns double
 * @param num: a valid double of Kelvin unit
 * @param unit: either 'c', 'f', or 'k'
 * @return a double of the new unit
 */
}

double KConv(double num, char unit) {
  switch(unit) {
    case 'k':
      return num;
    case 'f':
      return (num - 273.15) * (9.0/5) + 32;
    case 'c':
      return num - 273.15;
    default:
      return num;
  }

}

/**
 * Get double and unit to convert, performs calculations and returns double
 * @param num: a valid double of Inches unit
 * @param unit: either 'i', 'f', 'y', or 'm'
 * @return a double of the new unit
 */
double IConv(double num, char unit) {
  switch(unit) {
    case 'i':
      return num;
    case 'f':
      return num / 12;
    case 'y':
      return num / 36;
    case 'm':
      return num / 63360;
    default:
      return num;
  }
  
}
/**
 * Get double and unit to convert, performs calculations and returns double
 * @param num: a valid double of Feet unit
 * @param unit: either 'i', 'f', 'y', or 'm'
 * @return a double of the new unit
 */
double FtConv(double num, char unit) {
  switch(unit) {
    case 'i':
      return num *12;
    case 'f':
      return num;
    case 'y':
      return num / 3;
    case 'm':
      return num / 5280;
    default:
      return num;    
  }

}
/**
 * Get double and unit to convert, performs calculations and returns double
 * @param num: a valid double of Yard unit
 * @param unit: either 'i', 'f', 'y', or 'm'
 * @return a double of the new unit
 */
double YConv(double num, char unit) {
  switch(unit) {
    case 'i':
      return num * 36;
    case 'f':
      return num * 3;
    case 'y':
      return num;
    case 'm':
      return num / 1760;
    default:
      return num;        
  }

}
/**
 * Get double and unit to convert, performs calculations and returns double
 * @param num: a valid double of Miles unit
 * @param unit: either 'i', 'f', 'y', or 'm'
 * @return a double of the new unit
 */
double MConv(double num, char unit) {
  switch(unit) {
    case 'i': 
      return num * 63360;
    case 'f':
      return num * 5280;
    case 'y':
      return num * 1760;
    case 'm':
      return num;
    default:
      return num;          
  }

}

int main() {
    char convType;
    double initMeas;
    char initUnit;
    bool isValidUnit;
    char newUnit;
    

    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    convType = getValidChar(true);

    if(toLower(convType) != 't' && toLower(convType) != 'd') {
        printf("Unknown conversion type %c chosen. Ending program.\n", toUpper(convType));
        exit(0);
    }
    else if (toLower(convType) == 't') {
        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        initMeas = getValidDouble(false);
        initUnit = getValidChar(true);

        isValidUnit = isValidTempUnit(initUnit);
        if(isValidUnit) {
            printf("Enter the new unit type (F, C, or K): ");
            newUnit = getValidChar(true);
        }
        
        isValidUnit = isValidTempUnit(newUnit);
        if(isValidUnit) {

        if(toLower(initUnit) == 'f') {
          printf("%.2lfF is %.2lf%c\n", initMeas, FConv(initMeas, toLower(newUnit)), toUpper(newUnit));

        }
        else if(toLower(initUnit) == 'c') {
          printf("%.2lfC is %.2lf%c\n", initMeas, CConv(initMeas, toLower(newUnit)), toUpper(newUnit));
        }
        else {
          printf("%.2lfK is %.2lf%c\n", initMeas, KConv(initMeas, toLower(newUnit)), toUpper(newUnit));
        }

        }


    }
    else {
        printf("Enter the distance followed by its suffix (I,F,Y,M): ");        
        initMeas = getValidDouble(false);
        initUnit = getValidChar(true);

        isValidUnit = isValidDistUnit(initUnit);
        if(isValidUnit) {
            printf("Enter the new unit type (I,F,Y,M): ");
            newUnit = getValidChar(true);
        }
        
        isValidUnit = isValidDistUnit(newUnit);
        if(isValidUnit) {        

        if (toLower(initUnit) == 'i') {
          printf("%.2lfI is %.2lf%c\n", initMeas, IConv(initMeas, toLower(newUnit)), toUpper(newUnit));    

        }
        else if (toLower(initUnit) == 'f') {
          printf("%.2lfF is %.2lf%c\n", initMeas, FtConv(initMeas, toLower(newUnit)), toUpper(newUnit));
          
        }
        else if (toLower(initUnit) == 'y') {
          printf("%.2lfY is %.2lf%c\n", initMeas, YConv(initMeas, toLower(newUnit)), toUpper(newUnit));

        }
        else {
          printf("%.2lfM is %.2lf%c\n", initMeas, MConv(initMeas, toLower(newUnit)), toUpper(newUnit));
          
        }

        }        
    }

    return 0;

}