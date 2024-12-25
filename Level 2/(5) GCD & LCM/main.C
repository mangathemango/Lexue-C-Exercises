#include <stdio.h>  
  
int GCD (int num1, int num2) {  
    int lower = num1 < num2? num1 : num2;  
    for (int checkedGCD = lower; checkedGCD > 0; checkedGCD --) {  
        if (num1 % checkedGCD == 0 && num2 % checkedGCD == 0) {  
            return checkedGCD;  
        }  
    }  
}  
  
int LCM (int num1, int num2) {  
    int higher = num1 > num2? num1 : num2;  
    int step = GCD(num1,num2);  
    for (int checkedLCM = higher; checkedLCM > 0; checkedLCM += step) {  
        if (checkedLCM % num1 == 0 && checkedLCM % num2 == 0) {  
            return checkedLCM;  
        }  
    }  
}  
  
  
int main() {  
    int num1,num2;  
    while (1) {  
        scanf("%d %d",&num1, &num2);  
        if (num1 == 0 && num2 == 0) {  
            break;  
        }  
        if (num1 <= 0 || num2 <= 0) {  
            printf("Error!\n");  
            continue;  
        }  
          
        printf("The GCD of %d and %d is:%d\n",num1, num2, GCD(num1,num2));  
        printf("The LCM of %d and %d is:%d\n",num1, num2, LCM(num1,num2));  
    }  
  
}  