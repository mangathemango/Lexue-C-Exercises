#include <stdio.h>  
  
struct Warrior {  
    int height;  
    int used;  
};  
  
struct Dragon {  
    int height;  
    int slain;  
};  
  
int main () {  
    struct Warrior warrior[100];  
    struct Dragon dragon[100];  
      
    int num_warriors, num_dragons;  
    scanf("%d %d", &num_dragons, &num_warriors);  
    for (int i = 0; i < num_dragons; i ++) {  
        scanf("%d",&dragon[i].height);  
        dragon[i].slain = 0;  
    }  
    for (int i = 0; i < num_warriors; i ++) {  
        scanf("%d",&warrior[i].height);  
        warrior[i].used = 0;  
    }  
      
    while (1) {  
        int warriorSorted = 1;  
        for (int i = 0; i < num_warriors - 1; i++) {  
            if (warrior[i].height > warrior[i+1].height) {  
                struct Warrior temp = warrior[i];  
                warrior[i] = warrior[i+1];  
                warrior[i+1] = temp;  
                warriorSorted = 0;  
            }  
        }  
        if (warriorSorted) break;  
    }  
      
    int credits = 0;  
    for (int i = 0; i < num_dragons; i ++) {  
        int warriorFound = 0;  
        for (int j = 0; j < num_warriors; j ++) {  
            if (warrior[j].used) continue;  
            if (warrior[j].height < dragon[i].height) continue;  
            warrior[j].used = 1;  
            dragon[i].slain = 1;  
            credits += warrior[j].height;  
            warriorFound = 1;  
            break;  
        }  
        if (!warriorFound) {  
            printf("bit is doomed!\n");  
            return 0;  
        }  
    }  
    printf("%d\n",credits);  
      
}  