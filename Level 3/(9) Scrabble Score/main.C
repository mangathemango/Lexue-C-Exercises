#include <stdio.h>    
#include <ctype.h>  
int sb(char s[], int i){  
    if (s[i]=='\0')return 0;  
    int sd[26]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,6,4,10};  
    return sd[toupper(s[i])-'A']+sb(s,i+1);  
}  
int main(){  
    char s[100];  
    scanf("%[^\n]",s);  
    printf("%d\n",sb(s,0));  
}  