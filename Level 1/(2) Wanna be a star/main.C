#include <stdio.h>  
  
int main()  
{  
    int scores[10];  
    int max=0, min=100, sum=0, average;  
  
    for (int i=0; i<10;i++) {  
        scanf("%d",&scores[i]);  
    }  
    for (int i=0; i<10;i++) {  
        if (scores[i] < min) {  
            min = scores[i];  
        }  
        if (scores[i] > max) {  
            max = scores[i];  
        }  
        sum += scores[i];  
    }  
    average = (sum - max - min)/8;  
    printf("Canceled Max Score:%d\n",max);  
    printf("Canceled Min Score:%d\n",min);  
    printf("Average Score:%d\n",average);  
    return 0;  
}  