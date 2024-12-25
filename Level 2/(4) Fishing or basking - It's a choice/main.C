#include <stdio.h>  
  
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
        date += (yearnum % 4 == 0) ? 366 : 365;  
    }  
    return date;  
}  
int main() {  
    int input_num;  
    scanf("%d",&input_num);  
  
    int year,month,date;  
    int isLeapYear = 0;  
    int days_since_initial;  
    for (int i = 0; i < input_num; i++) {  
        scanf ("%d %d %d",&year,&month,&date);  
        if (year % 4 == 0) {  
            isLeapYear = 1;  
        }  
        days_since_initial = year_to_date(year) + month_to_date(month,isLeapYear) + date - 1;  
        if (days_since_initial % 5 < 3) {  
            printf("He was fishing on %d.%d.%d\n",year,month,date);  
        } else {  
            printf("He was basking on %d.%d.%d\n",year,month,date);  
        }  
    }  
}  