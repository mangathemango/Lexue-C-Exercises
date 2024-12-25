#include <stdio.h>  
void printResult (int dec,int base) {  
    if (dec == 0) return;  
    printResult(dec/base,base);  
    printf("%c","0123456789ABCDEF"[dec%base]);  
}  
  
int main () {    
    int dec, base;    
    scanf("%d",&dec);    
    scanf("%d",&base);    
    printf("%d in %d based system is ",dec,base);    
    printResult(dec,base);  
    printf("\n");    
    return 0;    
}  