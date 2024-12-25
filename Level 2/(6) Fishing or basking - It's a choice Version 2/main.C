#include <stdio.h>  

int isLeapYear(int year) {  
    return (year % 4 == 0) ? 1 : 0;   
} 

int month_to_date (int month, int isLeapYear) {  
    int monthdata[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};  
    if (isLeapYear) {  
        monthdata[2] = 29;  
    }  
    int datenums = 0;  
    for (int monthnum = 0; monthnum < month; monthnum ++) {  
        datenums += monthdata[monthnum];  
    }  
    return datenums;  
}  
int year_to_date (int year) {  
    int date = 0;  
    for (int yearnum = 1990; yearnum < year; yearnum ++) {  
        date += isLeapYear(yearnum) ? 366 : 365;  
    }  
    return date;  
}   
  
int inputIsValid (int year, int month, int date) {  
    int monthdata[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};  
    if (isLeapYear(year)) {  
        monthdata[2] = 29;  
    }  
    if (year < 1990) {  
        printf("Year is wrong!\n");  
        return 0;  
    }  
    if (month < 1 || month > 12) {  
        printf("Month is wrong!\n") ;  
        return 0;  
    }  
    if (date < 1 || date > monthdata[month]) {  
        printf("Day is wrong!\n") ;  
        return 0;  
    }  
    return 1;  
}  
  
  
int main() {  
    int input_num;  
    scanf("%d",&input_num);  
    int year,month,date;  
    int days_since_initial;  
      
    for (int i = 0; i < input_num; i++) {  
        scanf("%d %d %d",&year,&month,&date);  
        if (!inputIsValid(year,month,date)){  
            continue;  
        }  
          
        days_since_initial = year_to_date(year) + month_to_date(month,isLeapYear(year)) + date - 1;  
        if (days_since_initial % 5 < 3) {  
            printf("He was fishing on %d.%d.%d\n",year,month,date);  
        } else {  
            printf("He was basking on %d.%d.%d\n",year,month,date);  
        }  
    }  
}  