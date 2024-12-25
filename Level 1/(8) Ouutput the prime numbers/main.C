#include <stdio.h>  
#include <math.h>  
  
int isPrime(int num) {  
    int temp = 1;  
    for (int i=2; i<=sqrt(num); i++) {  
        if (num % i == 0) {  
            temp = 0;  
            break;  
        }  
    }  
    return temp;  
}  
  
int main() {  
    int number;  
    scanf("%d",&number);   
      
    int numbersPrinted = 0;  
    int lastPrime = 0;  
      
    for (int n = 2; n <= number; n++) {  
        if (isPrime(n)) {  
            if (lastPrime > 0) {  
                printf("%d",lastPrime);  
                numbersPrinted += 1;  
                if (numbersPrinted % 5 == 0) {  
                    printf("\n");  
                } else {  
                    printf("\t");  
                }  
            }  
            lastPrime = n;  
        }  
    }  
    printf("%d\n",lastPrime);  
      
    return 0;  
}  