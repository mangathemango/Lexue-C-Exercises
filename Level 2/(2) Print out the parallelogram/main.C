#include <stdio.h>  
  
int main()  
{  
    int sides;  
    scanf("%d",&sides);  
    if (sides < 1) {  
        printf("Error!\n");  
        return 0;  
    }  
    for (int i=0;i<sides;i++) {  
        for (int k=0; k<i;k++) {  
            printf(" ");  
        }  
        for (int j=0;j<sides;j++) {  
            printf("*");  
        }  
        printf("\n");  
    }  
  
    return 0;  
}  