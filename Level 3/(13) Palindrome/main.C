#include <stdio.h>    
#include <string.h>    
    
int isPalindrome (char string[],int i,int len) {    
    if(i >= len/2) return 1;  
    if(string[i] != string[len-i-1]) return 0;  
    return isPalindrome(string,i+1,len);  
}    
int main () {    
    char string[100];    
    fgets(string,sizeof(string),stdin);  
    string[strlen(string) - 1] = '\0';  
    printf("%s\n",isPalindrome(string,0,strlen(string))?"Yes":"No");  
}