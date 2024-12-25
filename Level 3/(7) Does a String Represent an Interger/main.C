#include <stdio.h>  
#include <string.h>  
int isNumber (char c) {  
    return (c <= '9' && c >= '0') ? 1 : 0;  
}  
  
int isInterger (char string[]) {  
    int i = 0;  
    int numCount = 0;  
    for (i = 0; i < strlen(string); i++) {  
        if (string[i] != ' ') break;  
    }  
    if (string[i] == '+' || string[i] == '-') i++;  
      
    for (i=i; i < strlen(string) ; i++) {  
        if (!isNumber(string[i])) break;  
        numCount++;  
    }  
      
    for (i=i; i < strlen(string) ; i++) {  
        if (string[i] != ' ') return 0;  
    }  
      
    if (numCount == 0) {  
        return 0;  
    }  
    return 1;  
}  
  
int main()  
{  
    char string[100];  
    scanf("%[^\n]s",&string);  
    if (isInterger(string)) {  
        printf("That string represents an integer.\n");  
    } else {  
        printf("That string does not represent an integer.\n");  
    }  
    return 0;  
}  