#include <stdio.h>  
#include <string.h>  
int isNumber(char character) {  
    if (character >= '0' && character <= '9') return 1;  
    return 0;  
}  
  
int isUppercaseLetter(char character) {  
    if (character >= 'A' && character <= 'Z') return 1;  
    return 0;  
}  
  
int isLowercaseLetter(char character) {  
    if (character >= 'a' && character <= 'z') return 1;  
    return 0;  
}  
  
int isGoodPassword (char password[]) {  
    if (strlen(password) < 8) return 0;  
    int hasLowercase = 0;  
    int hasUppercase = 0;  
    int hasNumber = 0;  
      
    for (int i = 0; i < strlen(password); i++) {  
        char character = password[i];  
        if (isNumber(character)) hasNumber = 1;  
        if (isUppercaseLetter(character)) hasUppercase = 1;  
        if (isLowercaseLetter(character)) hasLowercase = 1;  
    }  
      
    if (hasUppercase && hasLowercase && hasNumber) {  
        return 1;  
    } else {  
        return 0;  
    }  
}  
  
  
int main()  
{  
    int digitCount[10] = {0};  
    char number[30];  
    fgets(number, 30, stdin);  
    for (int i = 0; i < strlen(number); i++) {  
        int num = number[i] - '0';  
        digitCount[num] ++;  
    }  
    for (int i = 9; i >= 0; i--) {  
        for (int j = 0; j < digitCount[i]; j++) {  
            printf("%d",i);  
        }  
    }  
    printf("\n");  
    return 0;  
}  