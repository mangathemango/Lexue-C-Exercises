#include <stdio.h>   
int main()   
{      
    int age;   
    float cost = 0;   
    while (1) {   
        printf("Enter the age of the guest (blank to finish):\n");   
        if (scanf("%d",&age) != 1) {   
            break;   
        }   
        if (age <= 2) {   
            continue;   
        } else if (age <= 12) {   
            cost += 14.00;   
        } else if (age < 65) {   
            cost += 23.00;   
        } else {   
            cost += 18.00;   
        }   
           
    }   
    printf("The total for that group is $%.2f\n",cost);   
    return 0;   
}  