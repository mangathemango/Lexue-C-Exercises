#include <stdio.h>  
  
// Get it? Bc we're validating the date :D  
int valiDate (int year, int month, int date) {  
    int monthData[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};  
    if (year % 4 == 0) {  
        monthData[2] = 29;  
    }  
      
    if (date > monthData[month]) {  
        return 0;  
    }  
      
    return 1;  
}  
  
int main()  
{  
    for (int year = 0; year < 100; year++) {  
        for (int month = 1; month <= 12; month ++) {  
            if (year < month) {  
                break;  
            }  
              
            if (year % month == 0) {  
                int date = year / month;  
                if (!valiDate(year,month,date)) {  
                    continue;     
                }  
                  
                printf("19");  
                if (year < 10) {  
                    printf("0");  
                }  
                printf("%d/",year);  
                if (month < 10) {  
                    printf("0");  
                }  
                printf("%d/",month);  
                if (date < 10) {  
                    printf("0");  
                }  
                printf("%d ",date);  
            }  
        }  
        printf("\n");  
    }  
      
    return 0;  
}  