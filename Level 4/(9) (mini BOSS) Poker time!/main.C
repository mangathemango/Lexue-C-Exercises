#include <string.h>  
#include <stdio.h>  
int suitValue (char suit) {    
    char suits[5] = "CDSH";    
    for (int i = 0; i < 4; i++) {    
        if (suit == suits[i]) return (i*13);    
    }    
    return -1;    
}    
int weightValue (char weight) {    
    if (weight == '1') return 10;    
    char weights[13] = "23456789JQKA";    
    for (int i = 0; i < 12; i++) {    
        if (weight == weights[i]) return (i + 1);    
    }    
    return -1;    
}    
int cardValue (char card[2]) {    
    return suitValue(card[0]) + weightValue(card[1]);    
}    
int validateCard (char card[2]) {    
    return (suitValue(card[0]) == -1 || weightValue(card[1]) == -1) ? 0 : 1;   
}    
void sortCards (char hand[3][3]) {    
    int isSorted = 1;    
    for (int i = 0; i < 2; i++)   
        if (cardValue(hand[i]) < cardValue(hand[i + 1])) {    
            char temp[3];    
            strcpy(temp,hand[i + 1]);    
            strcpy(hand[i + 1],hand[i]);    
            strcpy(hand[i],temp);    
            isSorted = 0;    
        }    
    if (isSorted) return;    
    sortCards(hand);  
}    
int isEqual(char hand[3][3], int i1, int i2) {    
    return (hand[i1][0] == hand[i2][0] && hand[i1][1] == hand[i2][1]) ? 1 : 0;  
}    
int hasRepeatingCards (char hand[3][3]) {    
    return (isEqual(hand,0,1)||isEqual(hand,0,2)||isEqual(hand,1,2)) ? 1 : 0;  
}    
int main () {    
    char A_cards[3][3], B_cards[3][3];    
    for (int i = 0; i < 3; i ++) {    
        fgets(A_cards[i],3, stdin);    
        getchar();    
        if (A_cards[i][1] == '1') getchar();    
    }    
    for (int i = 0; i < 3; i ++) {    
        fgets(B_cards[i],3, stdin);    
        getchar();    
        if (B_cards[i][1] == '1') getchar();    
    }    
    for (int i = 0; i < 3; i ++) {    
        if (!validateCard(A_cards[i]) || !validateCard(B_cards[i])) {    
            printf("Input Error!\n");    
            return 0;    
        }    
    }    
    if (hasRepeatingCards(A_cards) || hasRepeatingCards(B_cards)) {    
        printf("Input Error!\n");    
        return 0;    
    }    
    sortCards(A_cards);    
    sortCards(B_cards);    
    int A_points = 0, B_points = 0;    
    for (int i = 0; i < 3; i++) {    
        if (cardValue(A_cards[i]) > cardValue(B_cards[i])) A_points++;    
        else if (cardValue(A_cards[i]) < cardValue(B_cards[i])) B_points++;    
    }    
    char winner = (A_points > B_points) ? 'A' : (A_points < B_points) ? 'B' : 'X';   
    printf("Winner is %c!\n",winner);    
    printf("A:");    
    for (int i = 0; i < 3; i++) {    
        printf(" %s",A_cards[i]);    
        if (A_cards[i][1] == '1') printf("0");    
    }    
    printf("\nB:");    
    for (int i = 0; i < 3; i++) {    
        printf(" %s",B_cards[i]);    
        if (B_cards[i][1] == '1') printf("0");    
    }    
    printf("\n");    
}  