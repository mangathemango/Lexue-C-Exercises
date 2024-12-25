#include <stdio.h>    
#include <math.h>    
    
int main() {    
    int numberOfDigits;    
    scanf("%d",&numberOfDigits);    
        
    int numberOfAmstrongNumbers = 0;    
        
    for (int checkedNumber = pow(10,numberOfDigits-1); checkedNumber < pow(10,numberOfDigits); checkedNumber++){    
        int temp = checkedNumber;    
        int sumOfPoweredDigits = 0;    
        while(temp > 0) {    
            int digitValue = temp % 10;  
            temp = temp / 10;    
            sumOfPoweredDigits += pow(digitValue,numberOfDigits);    
        }    
            
        if (checkedNumber == sumOfPoweredDigits) {    
            printf("%d\n",checkedNumber);    
            numberOfAmstrongNumbers += 1;    
        }    
    }    
    if (numberOfAmstrongNumbers == 0) {    
        printf("No output.\n");    
    }    
}  