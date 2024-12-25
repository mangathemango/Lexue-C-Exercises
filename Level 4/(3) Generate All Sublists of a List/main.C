#include <stdio.h>  
#include <string.h>  
  
int main() {  
    int list[100];  
    int listSize;  
    char buffer;  
    for (listSize = 0; listSize < 1000; listSize++) {  
        if (scanf("%d%c",&list[listSize], &buffer) < 1 && listSize == 0) {  
            printf("\n");  
            return 1;  
        }  
        if (buffer == '\n') {  
            listSize++;  
            break;  
        }  
    }  
    printf("\n");  
    for (int length = 1; length <= listSize; length ++) {  
        for (int start = 0; start <= listSize - length; start++) {  
            for (int i = start; i < start + length; i++) {  
                printf("%d ",list[i]);  
            }  
            printf("\n");  
        }  
    }  
}  