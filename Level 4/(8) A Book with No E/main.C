#include <stdio.h>  
#include <string.h>  
int main () {  
    float occurence[26] = {0}, wordCount = 0;  
    char text[10000],line[1000];
    while (fgets(line, 1000, stdin) != NULL) strncat(text, line, sizeof(text) - strlen(text) - 1);
    char *w = strtok(text," .,!?\"();\n");  
    while (w != NULL) {  
        for (int i = 0; i < 26; i ++) for (int j = 0; j < strlen(w); j++)   
        if (w[j] == 'A' + i || w[j] == 'a' + i) {  
            occurence[i] ++;  
            break;  
        }  
        wordCount++;  
        w = strtok(NULL," .,!?\"();\n");  
    }  

    char lowestOccurence = 'A';  
    int lon = occurence[0];  
    for (int i = 0; i < 26; i ++) {  
        printf("%c occurs in %.2f percent of words\n", i + 'A', occurence[i]*100/wordCount);  
        if (lon <= occurence[i]) continue;  
        lon = occurence[i];  
        lowestOccurence = i + 'A';  
    }  
    printf("\nThe letter that is easiest to avoid is '%c'\n", lowestOccurence);  
}  