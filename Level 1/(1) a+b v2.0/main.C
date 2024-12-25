#include <stdio.h>  
  
int main()  
{  
    int a,b;  
    scanf("%d,%d",&a,&b);  
    if (a<0||b<0) {  
        printf("(%d)+(%d)=(%d)\n",a,b,a+b);  
    } else {  
        printf("%d+%d=%d\n",a,b,a+b);  
    }  
  
    return 0;  
}  