#include <stdio.h>  
#include <string.h>  
int main(){  
    int a,b,c;  
    char type[12];  
    scanf("%d",&a);  
    scanf("%d",&b);  
    scanf("%d",&c);  
    if (a==b && b==c) {  
        strcpy(type,"equilateral");  
    } else if (a==b||b==c||c==a) {  
        strcpy(type,"isosceles");  
    } else {  
        strcpy(type,"scalene");  
    }  
    printf("That's a %s triangle.\n", type);  
} 