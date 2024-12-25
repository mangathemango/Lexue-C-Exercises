#include <stdio.h>  
#include <string.h>  
int isVowel(char character) {  
    char vowels[11] = "aeiouAEIOU";  
    for (int i = 0; i < 11; i ++) {  
        if (character == vowels[i]) return 1;  
    }  
    return 0;  
}  
  
int main()  
{  
    int n;  
    scanf("%d",&n);  
      
    char textList[n][14000];  
    for (int i = 0; i < n; i++) {  
        getchar();  
        scanf("%[^\n]s",&textList[i]);  
    }  
    for (int i = 0; i < n; i++) {  
        int length = strlen(textList[i]);  
        for (int j = 0; j < length; j++) {  
            if (textList[i][j] == '\0') break;  
            if (isVowel(textList[i][j])) continue;  
            printf("%c",textList[i][j]);  
        }  
        printf("\n");  
    }  
}  