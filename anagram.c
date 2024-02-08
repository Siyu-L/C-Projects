#include <stdio.h>
#include <stdbool.h>

//my_strlen function from class drive
/*
returns the length of a given string
@param str: any string
@return len: length of string
*/
int my_strlen(char str[]){
  int len;
	for(len = 0; str[len] != '\0'; ++len){}

	return len;
}

//my_strcpy function from class drive
/*
copies one string to another
@param dest: string being copied into
@param src: string to be copied
*/
void my_strcpy(char dest[], char src[]){
	int i;
	for(i = 0; src[i] != '\0'; ++i){
		dest[i] = src[i];
	}
	dest[i] = src[i]; //dest[i] = '\0';
}

/*
compares length of two strings and determines if they're equal
@param str1: first string
@param str2: second string
@return: true if lengths are same, false otherwise
*/
bool isSameLength(char str1[], char str2[]) {
    return (my_strlen(str1) == my_strlen(str2));
}

/*
returns the lower case of a given character
@param a: any character
@return: lower case of character
*/
char toLowerChar(char a) {
    if (a >= 65 && a <= 90) {
        return a + 'a' - 'A';
    }
    else {
        return a;
    }
}
/*
converts each letter of a string to lower case
@param str: string to convert
@param length: length of the string
*/
void toLowerStr(char str[], int length) {
    for(int i = 0; i < length; i++) {
        str[i] = toLowerChar(str[i]);

    }
}
/*
determine whether two strings are anagrams
@param str1: first string
@param str2: second string
@return: true if anagrams, false otherwise
*/
bool isAnagram(char str1[], char str2[]) {
    if(!isSameLength(str1, str2)) {
        return false;
    }
    char temp1[20];
    char temp2[20];

    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    my_strcpy(temp1, str1);
    my_strcpy(temp2, str2);

    toLowerStr(temp1, len1);
    toLowerStr(temp2, len2);

    for(int i = 0; i < len1; i++) {
        char c = temp1[i];
        
        for(int j = 0; j < len2; j++) {
            if(c == temp2[j]) {
                temp2[j] = temp2[len2-1];
                temp2[len2-1] = '\0';
                len2--;
                break;
            }
            else {
                if(j < (len2 - 1)) {
                    continue;
                }
                else {
                    return false;
                }

            }

        }

    }
    return true;

}

int main() {
    char word1[20];
    char word2[20];

    printf("Please enter the first word: ");
    scanf("%s", word1);
    printf("Please enter the second word: ");
    scanf("%s", word2);

    if(isAnagram(word1, word2)) {
        printf("%s is an anagram of %s\n", word1, word2);
    } 
    else {
        printf("%s is NOT an anagram of %s\n", word1, word2);
    }


}