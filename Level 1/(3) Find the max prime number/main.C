#include <stdio.h>  
#include <math.h>  
  
int isPrime(int num) {  
    int sqrtnum = sqrt(num);  
    int prime = 1;  
    if (num <= 1) {  
        return 0;  
    }   
    for (int i = 2; i<=sqrtnum; i++) {  
        if (num % i == 0) {  
            prime = 0;  
            break;  
        }  
    }  
    return prime;  
}  
  
int main()  
{  
    int num, maxPrime;  
    scanf("%d",&num);  
    for (int i = num; i > 0; i--) {  
        if (isPrime(i)) {  
            maxPrime = i;  
            break;  
        }  
    }  
    printf("The max prime number is %d.\n",maxPrime);  
    return 0;  
}  