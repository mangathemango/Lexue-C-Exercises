#include <stdio.h>  
int main(){  
    int sides;  
    char shapeNames[10][10] = {"triangle","rectangle","pentagon","hexagon","heptagon","octagon","septagon","decagon"};  
    scanf("%d",&sides);  
    if (sides > 10 || sides < 3) {  
        printf("That number of sides is not supported by this program.\n");  
    } else {  
        printf("That's a %s.\n",shapeNames[sides-3]);  
    }  
    return 0;  
}  