#include <stdio.h>  

float calculateSum(int pos) {  
    if (pos == 1) return 1;
    float sum = (float)(((int)pos % 2 == 0) ? 1 : -1) / (float) pos + calculateSum(pos - 1);
    return sum;
} 

int main()  {  
    int n;  
    scanf("%d",&n);  
    if (n==1) {  
        printf("1\n");  
        return 1;  
    }  
    printf("%.6f\n",calculateSum(n));  
    return 0;  
}  