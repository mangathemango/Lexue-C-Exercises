#include <stdio.h> 
#include <string.h> 
 
int romanValue (char romanChar) { 
    char roman[7] = {  'M' , 'D' , 'C' , 'L' , 'X' , 'V' , 'I'}; 
    int value[7] = { 1000 , 500 , 100 ,  50 ,  10 ,  5  ,  1 }; 
     
    for (int i = 0; i < 7; i++) { 
        if (romanChar == roman[i]) { 
            return value[i]; 
        } 
    } 
    return 0; 
} 
 
int romanNumtoInt (char romanString[]) { 
    int value = 0; 
    int smallerValueDetected = 0; 
    for (int i = 0; i < strlen(romanString); i++) { 
        if (romanValue(romanString[i]) < romanValue(romanString[i+1])) { 
            smallerValueDetected = 1; 
            continue; 
        } else { 
            value += romanValue(romanString[i]); 
        } 
        if (smallerValueDetected) { 
            smallerValueDetected = 0; 
            value -= romanValue(romanString[i-1]); 
        } 
    } 
    return value; 
} 
 
int main () { 
    char romanString[100]; 
    scanf("%[^\n]s", &romanString); 
    printf("%d\n",romanNumtoInt(romanString)); 
    return 0; 
}  