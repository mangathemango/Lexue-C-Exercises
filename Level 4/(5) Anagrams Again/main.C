#include <stdio.h>  
#include <string.h>  
  
void toLowerCase (char *str) {  
    for (int i = 0; i < strlen(str); i++) {  
        if (str[i] >= 'A' && str[i] <= 'Z') {  
            str[i] = str[i] - 'A' + 'a';  
        }  
    }      
}  
  
void sortString (char *str) {  
    int isSorted = 0;  
    while (!isSorted) {  
        isSorted = 1;  
        for (int i = 0; i < strlen(str) - 1 ; i++) {  
              
            if (str[i] > str[i+1]) {  
                char temp = str[i];  
                str[i] = str[i+1];  
                str[i+1] = temp;  
                isSorted = 0;  
            }  
        }  
    }  
}  
  
void removeSpace(char *str) {  
    int index = 0;  
    char newstr[100];  
    for (int i = 0; i < strlen(str); i++) {  
        if (str[i] == ' '||str[i] == ','||str[i] == '.'||str[i] == '!'||str[i] == '?') continue;  
        newstr[index] = str[i];  
        index ++;  
    };  
    strcpy(str,newstr);  
}  
int isAnagram (char s1[], char s2[]) {  
    toLowerCase(s1);  
    toLowerCase(s2);  
    sortString(s1);  
    sortString(s2);  
    removeSpace(s1);  
    removeSpace(s2);  
    if (strlen(s1) != strlen(s2)) return 0;  
    for (int i = 0; i < strlen(s1); i++) {  
        if (s1[i] != s2[i]) return 0;  
    }  
    return 1;  
}  
  
int main () {  
    char s1[100], s2[100];  
    int s1read, s2read = 1;  
    if (scanf("%[^\n]s",&s1) != 1) {  
        s1read = 0;     
    }  
    getchar();  
    if (scanf("%[^\n]s",&s2) != 1) {  
        s2read = 0;     
    }  
    getchar();  
      
    if (!s2read && !s1read) {  
        printf("Those phrases are anagrams.\n");  
        return 0;  
    }   
  
    if (isAnagram(s1,s2)) {  
        printf("Those phrases are anagrams.\n");  
    } else {  
        printf("Those phrases are not anagrams.\n");  
    }  
      
}  