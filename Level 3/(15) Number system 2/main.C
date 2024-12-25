#include <stdio.h>  
#include <string.h>  
  
      
int numeralToDecValue (char numeral) {  
    for (int i = 0; i < 36; i++) {  
        char checkedNumeral;  
        if (i < 10) {  
            checkedNumeral = '0' + i;     
        } else {  
            checkedNumeral = 'A' + i - 10;  
        }  
          
        if (checkedNumeral == numeral) {  
            return i;  
        }  
    }  
}  
  
int power (int base, int exponential) {  
    int temp = 1;  
    for (int i = 0; i < exponential; i++) {  
        temp *= base;  
    }      
    return temp;  
}  
  
int convertToDec(char num[], int base) {  
    int dec = 0;  
    int isNegative = 1;  
    for (int i = 0; i < strlen(num); i++) {  
        if (num[i] == '-') {  
            continue;  
        }  
        dec += numeralToDecValue(num[i]) * power(base, strlen(num) - i-  1);   
    }  
    return dec;  
}  
  
int validateBase (char num[], int base) {  
    for (int i = 0; i < strlen(num); i++) {  
        if (num[i] == '-') {  
            continue;  
        }  
        if (numeralToDecValue(num[i]) > base - 1) return 0;  
    }  
    return 1;  
}  
  
int main () {  
    char num1[10], num2[10];  
    scanf("%s %[^\n]s",&num1, &num2);  
    int found = 0;  
    int base1, base2;  
    for (base1 = 2; base1 <= 36; base1 ++) {  
          
        if (!validateBase(num1,base1)) continue;  
        int a = convertToDec(num1, base1);  
          
        for (base2 = 2; base2 <= 36; base2 ++) {  
            if (!validateBase(num2,base2)) continue;  
            int b = convertToDec(num2, base2);  
              
            if (b > a) break;  
              
            if (b == a) {  
                found = 1;  
                break;  
            }  
        }  
        if (found) {  
            break;  
        }  
    }  
    if (found) {  
        printf("%s (base %d) = %s (base %d)\n",num1,base1,num2,base2);  
    } else {  
        printf("%s is not equal to %s in any base 2..36\n",num1,num2);  
    }  
}  