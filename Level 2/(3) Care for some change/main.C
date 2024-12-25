#include <stdio.h>  
  
int main()  
{  
    int tenYs;  
    scanf("%d",&tenYs);  
    int exchangeFound = 0;  
    int totalVal = 1000 * tenYs;  
    float h10 = 1.8, h50 = 1.5, h100 = 2.0;  
    int num10, num50, num100;  
    for (num100 = totalVal/100; num100>0; num100--) {    
        num10 = num100*h100/h10;  
        num50 = num100*h100/h50;  
        if (num10 * h10 != num50 * h50 || num50 * h50 != num100 * h100) {  
            continue;  
        }  
        if ((num10 * 10 + num50 * 50 + num100 * 100) != totalVal) {  
            continue;  
        }  
        exchangeFound = 1;  
        printf("%d,%d,%d\n",num10,num50,num100);  
    }   
    if (exchangeFound != 1) {  
        printf("No change.\n");  
    }  
  
    return 0;  
}  