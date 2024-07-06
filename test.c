#include <stdio.h>
#include <string.h>

int compare_characters(char string1[50], char string2[50]) {
    if (strlen(string1) != strlen(string2)) {
        return 0;
    }
	for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] != string2[i]) {
            return 0;
        }
    }
    return 1;
}


int main(void) {
    char hello1[] = "Hello World";
    char hello2[] = "Hello World";
    printf("%d, identical hello worlds\n", compare_characters(hello1, hello2));

    char last_char[] = "Hello world";
    char last_char1[] = "Hello worlx";
    printf("%d, last character different\n", compare_characters(last_char, last_char1));

    char random_spaces[] = "h e  llo wor l d";
    char random_spaces1[] = "h e  llo wor l d";
    printf("%d, identical strings lots of spaces\n", compare_characters(random_spaces, random_spaces1));

    char just_space[] = " ";
    char just_space1[] = " ";
    printf("%d, only space, identical\n", compare_characters(just_space, just_space1));
 
    char user_input[20];
    fgets(&user_input[0], 20, stdin);
    printf("%19s", &user_input[0]);
    // char input[20];
    // char test1[] = "ONE SPACE";
    // char test2[] = "TWO SPACES HERE";
    // char test3[] = "ANOTHER SPACE";
    // scanf("%19s", &input[0]);
    // int result1 = strcmp(input, test1);
    // int result2 = strcmp(input, test2);
    // int result3 = strcmp(input, test3);
    // printf("%d, %d, %d", result1, result2, result3);
    // return 0;
}