#include <stdio.h>  
  
int main()  
{  
    int sides;  
    scanf("%d",&sides);  
    for (int i = 1; i <= sides * sides; i++) {  
        if (i<10) {  
            printf("  %d",i);  
        } else if (i < 100) {  
            printf(" %d",i);  
        } else {  
            printf("%d",i);  
        }  
  
        if (i % sides == 0) {  
            printf("\n");  
        }  
    }  
  
    return 0;  
}  