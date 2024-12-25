#include <stdio.h>  
#include <string.h>  
  
void toLowerCase (char *str) {  
    for (int i = 0; i < strlen(str); i++) {  
        if (str[i] >= 'A' && str[i] <= 'Z') {  
            str[i] = str[i] - 'A' + 'a';  
        }  
    }      
}  
  
void removePunctuation(char *str) {  
    int index = 0;  
    char newstr[100];  
    for (int i = 0; i < strlen(str); i++) {  
        if (str[i] == ' '||str[i] == ','||str[i] == '.'||str[i] == '!'||str[i] == '?'||str[i] == '\0') continue;  
        newstr[index] = str[i];  
        index ++;  
    };  
    str = newstr;  
}  
  
int sameString (char s1[], char s2[]) {  
    if (strlen(s1) != strlen(s2)) return 0;  
    for (int i = 0; i < strlen(s1); i ++) {  
        if (s1[i] == ' ' || s2[i] == ' ') continue;  
        if (s1[i] != s2[i]) {  
            return 0;  
        }  
    }  
    return 1;  
}  
  
  
int main () {  
    char wordList[1000][1000];  
    int occurence[1000] = {0};  
    int wordListIndex = 0;  
    int maxOccurence = 0;  
    while (1) {  
        int detectedWordsCount = 0;  
        for (int wordCount = 0; wordCount < 1000; wordCount ++) {  
            char word[100];  
            scanf("%s",&word);  
  
            toLowerCase(word);  
            removePunctuation(word);  
              
            int wordIsAlreadyInList = 0;  
            for (int i = 0; i < wordListIndex; i++) {  
                if (sameString(word, wordList[i])) {  
                    wordIsAlreadyInList = 1;  
                    occurence[i] += 1;  
                    if (occurence[i] > maxOccurence) {  
                        maxOccurence = occurence[i];  
                    }  
                    break;  
                }  
            }  
            if (!wordIsAlreadyInList) {  
                strcpy(wordList[wordListIndex],word);  
                occurence[wordListIndex] = 1;  
                wordListIndex++;  
                detectedWordsCount ++;  
            }  
              
            char ch;  
            scanf("%c",&ch);  
            if (ch == '\n') break;  
        }  
          
        if (detectedWordsCount <= 1) {  
            break;  
        }  
    }  
      
    for (int i = 0; i < wordListIndex; i++) {  
        if (occurence[i] == maxOccurence) {  
            printf("%s\n",wordList[i]);  
        }  
    }  
}  