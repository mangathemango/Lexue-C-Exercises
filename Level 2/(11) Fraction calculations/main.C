#include <stdio.h>

int GCD (int num1, int num2) {  
    int lower = num1 < num2 ? num1 : num2;  
    for (int i = lower; i > 0; i--) {  
        if (num1 % i == 0 && num2 % i == 0) {  
            return i;  
        }  
    }  
    return 1;  
}  
  
int LCM (int num1, int num2) {  
    int higher = num1 > num2 ? num1 : num2;  
    int step = GCD(num1,num2);  
    for (int i = higher; i > 0; i+=step) {  
        if (i % num1 == 0 && i % num2 == 0) {  
            return i;  
        }  
    }  
    return 1;  
}  
  
int main()  
{  
    int num1,den1,num2,den2,resultnum,resultden;  
    char op;  
    scanf("%d/%d %c %d/%d",&num1,&den1,&op,&num2,&den2);  
    printf("%d/%d %c %d/%d = ",num1,den1,op,num2,den2);  
    if (op == '+') {  
        resultden = LCM(den1,den2);  
        resultnum = num1 * resultden / den1 + num2 * resultden / den2;  
    } else if (op == '-') {  
        resultden = LCM(den1,den2);  
        resultnum = num1 * resultden / den1 - num2 * resultden / den2;  
    } else if (op == '*') {  
        resultden = den1 * den2;  
        resultnum = num1 * num2;  
    } else if (op == '/') {  
        resultden = den1 * num2;  
        resultnum = num1 * den2;  
    }  
  
    int tempGCD = GCD(resultnum,resultden);  
    resultnum /= tempGCD;  
    resultden /= tempGCD;  
    if (resultden == 1) {  
        printf("%d\n",resultnum);  
    } else if (resultnum == 0) {  
        printf("0\n");  
    } else {  
        printf("%d/%d\n",resultnum,resultden);  
    }  
    return 0;  
      
}  