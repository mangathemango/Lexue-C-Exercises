#include <stdio.h>  
#include <string.h>  
  
int isNumberChar (char ch) {  
    return (ch >= '0' && ch <= '9')? 1 : 0;  
}  

// lexue doesn't have built in strreverse
void strreverse (char *str) {  
    if (str == NULL) return;  
    int len = strlen(str);  
    for (int i = 0; i * 2 < len; i++) {  
        char temp = str[i];  
        str[i] = str[len - i - 1];  
        str[len - i - 1] = temp;  
    }  
}  
  
int compareStrings (char *num1, char *num2) {  
    int len1 = strlen(num1);  
    int len2 = strlen(num2);  
    if (len1 > len2) return 1;  
    if (len1 < len2) return -1;  
  
    for (int i = 0; i < len1; i++) {  
        if (num1[i] > num2[i]) return 1;  
        if (num1[i] < num2[i]) return -1;  
    }  
      
    return 0;  
}  
  
void addStrings (char *sum, char *num1, char *num2) {  
    int len1 = strlen(num1);  
    int len2 = strlen(num2);  
    strreverse(num1);  
    strreverse(num2);  
      
    int longerLen = len1 > len2? len1 : len2;  
    int carry = 0;  
    int i;  
    for (i = 0; i < longerLen; i ++) {  
        int val1 = 0;  
        int val2 = 0;  
        if (i < len1) {  
            val1 = num1[i] - '0';  
        }  
        if (i < len2) {  
            val2 = num2[i] - '0';  
        }  
        int sumval = val1 + val2 + carry;  
        if (sumval >= 10) {  
            sumval -= 10;  
            carry = 1;  
        } else {  
            carry = 0;  
        }  
          
        sum[i] = sumval + '0';  
    }  
    if (carry == 1) sum[i++] = '1';  
    sum[i] = '\0';  
    strreverse(sum);  
}  
  
void subStrings (char *dif, char *num1, char *num2) {  
    int negative = 0;  
    if (compareStrings(num1,num2) == - 1) {  
        negative = 1;  
    }  
    if (compareStrings(num1, num2) == -1) {  
        negative = 1;  
        char *temp = num1;  
        num1 = num2;  
        num2 = temp;  
    }  
    strreverse(num1);  
    strreverse(num2);  
    int len1 = strlen(num1);  
    int len2 = strlen(num2);  
    int longerLen = len1 > len2? len1 : len2;  
    int carry = 0;  
    int i;  
    for (i = 0; i < longerLen; i ++) {  
        int val1 = 0;  
        int val2 = 0;  
        if (i < len1) {  
            val1 = num1[i] - '0';  
        }  
        if (i < len2) {  
            val2 = num2[i] - '0';  
        }  
  
        int difval = val1 - val2 - carry;  
        if (difval < 0) {  
            difval += 10;  
            carry = 1;  
        } else {  
            carry = 0;  
        }  
        dif[i] = difval + '0';  
    }  
    if (negative) dif[i++] = '-';  
    dif[i] = '\0';  
    strreverse(dif);  
}  
  
void printString(char *string) {  
    int startPoint = 0;  
    int detectedNumber = 0;  
    if (string[0] == '-') {  
        printf("-");  
        startPoint = 1;  
    }  
    int frontZero = 1;  
    for (int i = startPoint; i < strlen(string); i++) {  
        if (string[i] != '0') {  
            frontZero = 0;  
        }  
        if (frontZero) {  
            continue;  
        }  
        if (isNumberChar(string[i])) {  
            printf("%c",string[i]);  
            detectedNumber ++;  
        }  
    }  
    if (detectedNumber == 0) {  
        printf("0");  
    }  
    printf("\n");  
}  
  
int main() {  
    int inputs;  
    scanf("%d",&inputs);  
    getchar();  
    for (int i = 0; i < inputs; i++) {  
        char operation[1000];  
        scanf("%[^\n]s",operation);  
        getchar();  
        char op;  
        op = operation[strspn(operation,"1234567890")];  
        char *num1 = strtok(operation," +-\n");  
        char *num2 = strtok(NULL," +-\n");  
        char output[100] = "\0";  
        if (op == '+') {  
            addStrings(output,num1,num2);  
        }  
        if (op == '-') {  
            subStrings(output,num1,num2);  
        }  
        printString(output);  
    }  
   
}  