#include <stdio.h>  
int main(){  
while(1){  
    int a,b;  
    scanf("%d %d",&a,&b);  
    if(a==b&&a==0){  
    break;  
    }  
    printf("%d\n",(a+b)*(b-a+1)/2);  
}  
return 0;  
}  