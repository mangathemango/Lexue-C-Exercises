#include <stdio.h>  
  
void reduce(int *num, int *den) {    
    int higher = *num > *den? *num : *den;  
    for (int i = 2; i <= higher; i++) {  
        if (*num % i == 0 && *den % i == 0) {  
            *num = *num / i;
            *den = *den / i;
            reduce(num,den);  
            break;
        }  
    }  
}    

int main()  
{  
    int num,den;  
    scanf("%d,%d",&num,&den);  
    if (den == 0) {  
        printf("Denominator cannot be zero.\n");  
        return 0;  
    }  
    printf("%d/%d can be reduced to ",num,den);  
    reduce(&num,&den);  
    printf("%d/%d.\n",num,den);  
}  