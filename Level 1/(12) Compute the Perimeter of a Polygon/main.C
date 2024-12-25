#include <stdio.h>  
#include <math.h>  
  
float distance(float x1, float y1, float x2, float y2) {  
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));  
}  
  
int main()  
{  
    float firstX, firstY, nextX, nextY, lastX, lastY;  
    float perimeter = 0;  
    printf("Enter the first x-coordinate:\n");  
    scanf("%f",&firstX);  
    printf("Enter the first y-coordinate:\n");  
    scanf("%f",&firstY);  
    lastX = firstX;  
    lastY = firstY;  
    while (1) {  
        printf("Enter the next x-coordinate (blank to quit):\n");  
        if (scanf("%f",&nextX) != 1) {  
            break;  
        }  
        printf("Enter the next y-coordinate:\n");  
        scanf("%f",&nextY);  
        perimeter += distance(lastX,lastY,nextX,nextY);  
        lastX = nextX;  
        lastY = nextY;  
    }  
    perimeter += distance(lastX,lastY,firstX,firstY);  
    printf("The perimeter of that polygon is %.6f\n",perimeter);  
    return 0;  
}  