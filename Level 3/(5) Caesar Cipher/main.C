#include <stdio.h> 
#include <string.h> 
 
char encrypt (char c, int key) { 
    int encrypted = c + key % 26; 
    if (c >= 'A' && c <= 'Z') { 
        while (encrypted > 'Z') { 
            encrypted = encrypted - 'Z' + 'A' - 1; 
        } 
        return encrypted; 
    } else if (c >= 'a' && c <= 'z') { 
        while (encrypted > 'z') { 
            encrypted = encrypted - 'z' + 'a' - 1; 
        } 
        return encrypted; 
    } else { 
        return c; 
    } 
} 
 
char decrypt (char c, int key) { 
    int encrypted = c - key % 26; 
    if (c >= 'A' && c <= 'Z') { 
        while (encrypted < 'A') { 
            encrypted = encrypted + 'Z' - 'A' + 1; 
        } 
        return encrypted; 
    } else if (c >= 'a' && c <= 'z') { 
        while (encrypted < 'a') { 
            encrypted = encrypted + 'z' - 'a' + 1; 
        } 
        return encrypted; 
    } else { 
        return c; 
    } 
} 
 
int main() 
{ 
    int mode, key; 
    char text[100]; 
    while (1) { 
        scanf("%d",&mode); 
        if (mode == 0) { 
            break; 
        } 
        scanf(" %d %[^\n]s", &key, &text); 
        if (mode > 2) { 
            printf("Wrong Input. Input Again.\n"); 
            continue; 
        } 
        if (mode == 1) { 
            for (int i = 0; i < strlen(text); i++) { 
                printf("%c",encrypt(text[i],key)); 
            } 
            printf("\n"); 
        } 
        if (mode == 2) { 
            for (int i = 0; i < strlen(text); i++) { 
                printf("%c",decrypt(text[i],key)); 
            } 
            printf("\n"); 
        } 
    } 
}  