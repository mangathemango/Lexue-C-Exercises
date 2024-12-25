#include <stdio.h>  
#include <string.h>  
int main () {  
    float o[26] = {0}, wc = 0;  
    char t[10000],l[1000],lo = 'A';  
    while (fgets(l, 1000, stdin) != NULL) strncat(t, l, sizeof(t) - strlen(t) - 1);
    char *w = strtok(t," .,!?\"();\n");  
    while (w != NULL) {  
        for (int i = 0; i < 26; i ++) for (int j = 0; j < strlen(w); j++)   
        if (w[j] == 'A' + i || w[j] == 'a' + i) {  
            o[i] ++;  
            break;  
        }  
        wc++;  
        w = strtok(NULL," .,!?\"();\n");  
    }  

    int lon = o[0];  
    for (int i = 0; i < 26; i ++) {  
        printf("%c occurs in %.2f percent of words\n", i + 'A', o[i]*100/wc);  
        if (lon <= o[i]) continue;  
        lon = o[i];  
        lo = i + 'A';  
    }  
    printf("\nThe letter that is easiest to avoid is '%c'\n", lo);  
}  