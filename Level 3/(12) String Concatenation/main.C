#include <stdio.h>  
#include <ctype.h>  
#include <string.h>  
void printConcat (char string[], char lastPrinted) {  
    char nextPrinted = 127;  
    for (int i = 0; i < strlen(string); i++) {  
        if (isspace(string[i])) continue;  
        if (!isdigit(string[i]) && !isalpha(string[i])) {  
            printf("Wrong Input!\n");  
            return;  
        }  
        if (string[i] > lastPrinted && string[i] < nextPrinted) {  
            nextPrinted = string[i];  
        }  
    }  
    if (nextPrinted == 127) {  
        printf("\n");  
        return;  
    }  
    printf("%c",nextPrinted);  
    printConcat(string,nextPrinted);  
}  
int main () {    
    char input[100];  
    fgets(input,100,stdin);  
    printConcat(input, 0);  
}  