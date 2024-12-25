#include <stdio.h>  
  
  
int main () {  
    int numPeople, step;  
    scanf("%d %d", &numPeople, &step);  
    getchar();  
    int dead[100] = {0};  
    int aliveCount = numPeople;  
    int stepCount = 0;  
    int position = 0;  
    while (aliveCount > 1) {  
        position ++;  
        if (position == numPeople) {  
            position = 0;  
        }  
        if (dead[position]) {  
              
            continue;  
        }  
        stepCount ++;  
        if (stepCount == step) {  
  
            dead[position] = 1;  
            stepCount = -1;  
            aliveCount --;  
        }  
          
    }  
      
    for (int i = 0; i < numPeople; i++) {  
        if (!dead[i]) {  
            printf("The lucky person is no:%d\n",i+1);  
            return 0;  
        }  
    }  
}  