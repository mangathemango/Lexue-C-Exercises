#include <stdio.h>   
#include <string.h>  
  
int findPointPos (char num[]) {  
    for (int i = 0; i < strlen(num); i ++) {  
        if (num[i] == '.') {  
            return i;  
        }  
    }      
    return strlen(num);  
}  
  
void addPrecision (char num[]) {  
    int pointPos = findPointPos(num);  
    int numAfterDecimal = strlen(num) - pointPos - 1;  
    if (pointPos == strlen(num)) {  
        strcat(num,".");  
        numAfterDecimal ++;  
    }  
    for (int i = numAfterDecimal; i < 8; i++) {  
        strcat(num,"0");  
    }  
}  
  
  
void moveDecimalPointLeft (char num[]) {  
    int pointPos = findPointPos(num);  
    num[pointPos] = num[pointPos - 1];  
    num[pointPos - 1] = '.';  
    if (pointPos == 1) {  
        char temp[100] = "0";  
        strcat(temp,num);  
        strcpy(num,temp);  
    }  
}  
  
void moveDecimalPointRight (char num[]) {  
    int pointPos = findPointPos(num);  
    num[pointPos] = num[pointPos + 1];  
    num[pointPos + 1] = '.';  
    addPrecision(num);  
}  
  
int main () {   
    char num[100];   
    int exponent;   
    char e;   
    scanf("%s %c%d",&num,&e,&exponent);   
    addPrecision(num);  
    if (exponent > 0) {  
        for (int i = 0; i < exponent; i ++) {  
            moveDecimalPointRight(num);  
        }  
    } else {  
        for (int i = 0; i > exponent; i --) {  
            moveDecimalPointLeft(num);  
        }  
    }  
    for (int i = 0; i <= findPointPos(num) + 8; i++) {  
        printf("%c",num[i]);  
    }  
    printf("\n");  
}  