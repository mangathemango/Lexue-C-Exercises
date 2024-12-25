#include <stdio.h>     
int main () {     
    int width,height,x,y,i,j;     
    int fieldCount = 1;     
    char result[101][102];     
    char temp;    
    while (1) {    
        scanf("%d %d\n",&height,&width);    
        if (width == 0 && height == 0) break;    
        if (fieldCount > 1) printf("\n");    
        for (y = 0; y < height; y++) for (x = 0; x <= width; x++) result[y][x] = x < width ? '0' : '\0';    
        for (y = 0; y < height; y++) for (x = 0; x <= width; x++) {    
            scanf("%c",&temp);    
            if (temp != '*') continue;    
            result[y][x] = '*';    
            for (i = x - 1;i <= x + 1;i++) for(j = y - 1;j <= y + 1; j++) {    
                if (!(i >= 0 && j >= 0 && i < width && y < height)) continue;    
                if (result[j][i] != '*') result[j][i]++;    
            }    
        }    
        printf("Field #%d:\n",fieldCount);    
        for (y = 0; y < height; y++) {    
            printf("%s\n",result[y]);    
        }    
        fieldCount ++;    
    }    
}  