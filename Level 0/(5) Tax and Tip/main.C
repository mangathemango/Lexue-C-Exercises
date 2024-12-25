#include <stdio.h>    
    
int main() {    
    int cost;  
    float tax,tip,total;  
    printf("Enter the cost of the meal: \n");  
    scanf("%d",&cost);  
    tax = cost * 0.05;  
    tip = cost * 0.18;  
    total = tax + tip + cost;  
    printf("The tax is %.2f and the tip is %.2f, making the total %.2f.\n",tax,tip,total);  
    return 0;    
}  