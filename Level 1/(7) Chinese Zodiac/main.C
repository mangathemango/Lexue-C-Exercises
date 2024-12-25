#include <stdio.h>  
  
int main()  
{  
    char zodiacList[12][10] = {"Monkey","Rooster","Dog","Pig","Rat","Ox","Tiger","Hare","Dragon","Snake","Horse","Sheep"};  
    int year;  
    scanf("%d",&year);  
    printf("%d is the year of the %s.\n",year,zodiacList[year%12]);  
    return 0;  
}  