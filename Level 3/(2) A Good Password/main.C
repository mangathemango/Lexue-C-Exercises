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
    char password[30];  
    fgets(password,30,stdin);  
    password[strlen(password) - 1] = '\0';  
    if (isGoodPassword(password)) {printf("Good password!\n");}  
    else {printf("Bad password!\n");}  
      
    return 0;  
}  