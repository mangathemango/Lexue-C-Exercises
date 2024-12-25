#include <stdio.h>  
  
int main()  
{  
    char op[10];  
    scanf("%s",&op);  
    int precedence = 0;  
    if (op[0] == '+' || op[0] == '-') {  
        precedence = 1;  
    }   
    if (op[0] == '*' || op[0] == '/') {  
        precedence = 2;  
    }  
    if (op[0] == '^') {  
        precedence = 3;  
    }  
    if (precedence == 0) {  
        printf("Error: '%s' is not a valid operator.\n",op);  
    } else {  
        printf("The precedence of '%c' is: %d\n",op[0],precedence);  
    }  
  
    return 0;  
}  