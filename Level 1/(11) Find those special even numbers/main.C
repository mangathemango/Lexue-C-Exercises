#include <stdio.h>  
  
int isSpecialEvenNumber (int num) {  
    int digits[10]={0,1,2,3,4,5,6,7,8,9};  
    int temp = num;  
    while (temp > 0) {  
        if (digits[temp % 10] == -1) {  
            return 0;  
        }  
        digits[temp % 10] = -1;  
        temp = temp / 10;  
    }  
    return 1;  
}  
int main()  
{  
    int belowLimit, upperLimit;  
    while (1) {  
        int counter = 0;  
          
        if (!scanf("%d  %d",&belowLimit, &upperLimit)) {  
            printf("Error\n");  
            continue;  
        };  
        if (belowLimit == 0 && upperLimit == 0) {  
            break;  
        }  
        if (belowLimit > upperLimit || belowLimit < 1000 || upperLimit < 1000 || belowLimit >= 10000 || upperLimit >= 10000) {  
            printf("Error\n");  
            continue;  
        }  
          
        for (int num = belowLimit; num <= upperLimit; num += 1) {  
            if (num % 2 != 0) {  
                continue;  
            }  
            if (isSpecialEvenNumber(num)) {  
                printf("%d  ",num);  
                counter += 1;  
            }  
        }  
        if (counter >= 1) {  
            printf("\ncounter=%d\n",counter);  
        }  
    }  
  
    return 0;  
}  