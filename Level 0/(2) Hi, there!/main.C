#include <stdio.h>  
#include <string.h>  
  
int main()      
{      
    char name[50];      
    fgets(name,sizeof(name),stdin);  
    name[strcspn(name, "\n")] = '\0';  
    printf("Hi,there,%s!\n",name);      
      
    return 0;      
}  