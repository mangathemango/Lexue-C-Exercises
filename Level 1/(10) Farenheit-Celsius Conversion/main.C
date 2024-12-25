#include <stdio.h>  
  
int main()  
{  
    for (int i=0;i<3;i++) {  
        int mode;  
        float value;  
        scanf("%d  %f", &mode,&value);  
        if (mode == 1) {  
            printf("The Centigrade is %.2f\n",(value-32)*5/9);  
        } else if (mode == 2) {  
            printf("The Fahrenheit is %.2f\n",value*9/5 + 32);  
        } else {  
            printf("Wrong input!\n");  
        }  
    }  
  
    return 0;  
}  