#include <stdio.h>   
#include <string.h>   
   
char capitalize (char c) {   
    return c - 'a' + 'A';   
}   
int main()   
{   
    char text[100];   
    scanf("%[^\n]s",&text);   
       
    int newSentence = 1;   
    int length = strlen(text);   
    for (int i = 0; i < length; i++) {   
        if (text[i] == ' ') {   
            continue;   
        }   
        if (text[i] == '!' || text[i] == '?' || text[i] == '.') {   
            newSentence = 1;   
            continue;   
        }   
        if (newSentence) {   
            text[i] = capitalize(text[i]);   
            newSentence = 0;   
            continue;   
        }   
        if (text[i] == 'i') {   
            if ((text[i-1] == ' ') && (text[i+1] == ' '||text[i+1] == '.'||text[i+1] == '!'||text[i+1] == '?'|| text[i+1] == '\'')) {   
                text[i] = 'I';   
            }   
        }   
    }   
       
    printf("%s\n",text);   
   
    return 0;   
}  
