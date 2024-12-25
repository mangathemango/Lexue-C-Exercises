#include <stdio.h>  

int step (int pos) {  
    if (pos < 0) return 0;
    if (pos == 0) return 1;
    return step(pos - 1) + step(pos - 2);
}  

int main() {  
    int stairs;  
    scanf("%d",&stairs);  

    int count = step(stairs);
    if (count == 1) {  
        printf("There is 1 way of climbing the stairs!\n");  
    } else {  
        printf("There are %d ways of climbing the stairs!\n",count);  
    }  
    return 0;  
}  