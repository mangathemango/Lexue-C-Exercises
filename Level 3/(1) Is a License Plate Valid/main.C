#include <stdio.h>  
#include <string.h>  
int isNumber(char character) {  
    if (character >= '0' && character <= '9') return 1;  
    return 0;  
}  
  
int isLetter(char character) {  
    if (character >= 'A' && character <= 'Z') return 1;  
    return 0;  
}  
  
int isOlderStyle (char string[]) {  
    if (strlen(string) != 6) return 0;  
    for (int i = 0; i < 3; i++) {  
        if (!isLetter(string[i])) {  
            return 0;  
        }  
    }  
    for (int i = 3; i < 6; i++) {  
        if (!isNumber(string[i])) {  
            return 0;  
        }  
    }  
    return 1;  
}  
  
int isNewerStyle (char string[]) {  
    if (strlen(string) != 7) return 0;  
    for (int i = 0; i < 4; i++) {  
        if (!isNumber(string[i])) {  
            return 0;  
        }  
    }  
    for (int i = 4; i < 5; i++) {  
        if (!isLetter(string[i])) {  
            return 0;  
        }  
    }  
    return 1;  
}  
  
int main()  
{  
    char plate[] = "";  
    scanf("%s",&plate);  
    if (isOlderStyle(plate)) {  
        printf("The plate is a valid older style plate.\n");  
    } else if (isNewerStyle(plate)) {  
        printf("The plate is a valid newer style plate.\n");  
    } else {  
        printf("The plate is not valid.\n");  
    }  
      
    return 0;  
}  