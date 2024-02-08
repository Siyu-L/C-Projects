#include <stdio.h>

//string function taken from class drive

/* returns the length of a given string
@param str: a string
@return len: length of the string
*/
int my_strlen(char str[]){
  int len;
	for(len = 0; str[len] != '\0'; ++len){}

	return len;
}

/* copies string from src to dest
@param dest: string to copy into
@param src: string to copy from
*/
void my_strcpy(char dest[], char src[]){
	int i;
	for(i = 0; src[i] != '\0'; ++i){
		dest[i] = src[i];
	}
	dest[i] = src[i]; //dest[i] = '\0';
}

/* outputs all possible binary strings where X's can be replaced with either 0 or 1
@param act_str: actual string being modified and printed out
@param tempString: copy of initial actual string to examine letters
@param cur_len: current length of tempString
@param cur_letter: letter to examine
@param index: index in the actual string
*/

void binary_strings(char* act_str, char* tempString, int cur_len, char cur_letter, int index) {
    if(cur_len == 0) {
        printf("%s\n", act_str);
        return;
    }
    else if (cur_letter == '0' || cur_letter == '1') {  
        act_str[index] = cur_letter;
        cur_letter = tempString[index + 1];
        binary_strings(act_str, tempString, cur_len -1, cur_letter, index + 1);

    }
    else{
        binary_strings(act_str, tempString, cur_len, '0', index);
        binary_strings(act_str, tempString, cur_len, '1', index);        


    }

}

int main(int argc, char** argv) {
    int length = my_strlen(argv[1]);
    char tempString[length];
    my_strcpy(tempString, argv[1]);
    binary_strings(argv[1], tempString, length, argv[1][0], 0);



}