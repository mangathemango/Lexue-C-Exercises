#include <stdio.h>    

int main() {    
    int n1,n2,n3,s,l,m;  
    printf("Enter the first number: \n");  
    scanf("%d",&n1);  
    printf("Enter the second number: \n");  
    scanf("%d",&n2);  
    printf("Enter the third number: \n");  
    scanf("%d",&n3);  
    s=n1<n2?n1<n3?n1:n3:n2<n3?n2:n3;  
    l=n1>n2?n1>n3?n1:n3:n2>n3?n2:n3;  
    m=n1+n2+n3-s-l;  
    printf("The numbers in sorted order are: %d %d %d.\n",s,m,l);  
    return 0;    
} 