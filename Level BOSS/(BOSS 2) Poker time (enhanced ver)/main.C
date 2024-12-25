#include <stdio.h>  
  
char suits[5] = "CDSH";  
// The 1 is there so that   
char weights[14] = "234567891JQKA";  
  
struct Card {  
    char suit;  
    char weight[2];  
    int value;  
};  
  
struct Player {      
    char name;  

    struct Card card[10];  
    int numCards;  
    int totalPoints;  
      
    // For blackjack  
    int hasAce;  
    int blackjack;  
};  
  
struct Player A;  
struct Player B;  
  
int validateSuit (char suit) {  
    for (int i = 0; i < 4; i ++) if (suit == suits[i]) return 1;  
    return 0;  
}  
  
int validateWeight (char weight[]) {  
    if (weight[0] == '1' && weight[1] == '0') return 1;  
    for (int i = 0; i < 13; i ++) {  
        if (weights[i] == '1') continue;  
        if (weight[0] == weights[i] && !weight[1]) return 1;  
    }  
    return 0;  
}  
  
void inputCards (struct Player *player) {  
    for (int i = 0; i < 10; i ++) {  
        struct Card *card = &(player->card)[i];  
        scanf("%c",&(card->suit));  
        scanf("%s",card->weight);  
        char temp;  
        scanf("%c",&temp);   
        if (temp == '\n') {  
            player->numCards = i + 1;  
            break;  
        }  
    }  
}  
  
void resetPlayer (struct Player *player) {  
    player->numCards = 0;  
    player->totalPoints = 0;  
    player->hasAce = 0;  
    player->blackjack = 0;  
}  
  
void getBJvalue (struct Card *card) {  
    if (card->weight[0] == 'A') {  
        card->value = 1;  
    } else if (card->weight[0] >= '2' && card->weight[0] <= '9') {  
        card->value = card->weight[0] - '0';  
    } else card->value = 10;  
}  
  
void processBJ (struct Player *player) {  
    for (int i = 0; i < player->numCards; i ++) {  
        getBJvalue(&(player->card[i]));  
        player->totalPoints += (player->card[i]).value;  
        if ((player->card[i]).weight[0] == 'A') player->hasAce = 1;  
    }  
    // Turn Ace value from 1 to 11 if it's beneficial;  
    if (player->hasAce && player->totalPoints + 10 <= 21) player->totalPoints += 10;  
      
    if (player->totalPoints == 21 && player->numCards == 2) player->blackjack = 1;  
}  
  
int tractorWeightValue (struct Card *card) {  
    for (int i = 0; i < 13; i ++) if (card->weight[0] == weights[i]) return i + 1;  
}  
  
int tractorSuitValue (struct Card *card) {  
    for (int i = 0; i < 4; i ++) if (card->suit == suits[i]) return i + 1;  
}  
  
void processTractor (struct Player *player) {  
    int weightCounter[13] = {0};  
    int suitCounter[4] = {0};  
    int flush = 0;  
    int highCard = 0;  
    int suitWeight          =   1,  
        pairWeight          =   100,  
        straightWeight      =   10000,  
        tripleWeight        =   1000000,  
        straightFlushWeight =   100000000;  
          
    for (int i = 0; i < 3; i ++) {  
        int weightVal = tractorWeightValue(&(player->card[i]));  
        int suitVal = tractorSuitValue(&(player->card[i]));  
          
        (player->card[i]).value = 10 * weightVal + suitVal;  
          
        weightCounter[weightVal] ++;  
        suitCounter[suitVal] ++;  
          
        if ((player->card[i]).value > highCard) highCard = (player->card[i]).value;     // High Card  
        player->totalPoints += suitWeight * suitVal;                                         // Suit  
        if (weightCounter[weightVal] == 2) player->totalPoints += pairWeight * weightVal;    // Pair  
        if (weightCounter[weightVal] == 3) player->totalPoints += tripleWeight * weightVal;  // Triple  
        if (suitCounter[suitVal] == 3) flush = 1;                                       // Flush  
    }  
      
    for (int i = 0; i < 10; i ++) {  
        // Checking for Straight (consecutive 3)  
        if (weightCounter[i] && weightCounter[i+1] && weightCounter[i+2]) {  
            if (flush) player->totalPoints += straightFlushWeight * (i + 1);  
            else player->totalPoints += straightWeight * (i + 1);  
        }  
    }  
      
    // Resolve to high card value if no pair is found  
    if (player->totalPoints < pairWeight) player->totalPoints = highCard;  
}  
  
void sortCards (struct Player *player) {  
    int isSorted = 1;  
    for (int i = 0 ; i < 2; i ++) {  
        if (player->card[i].value < player->card[i+1].value) {  
            struct Card temp = player->card[i];  
            player->card[i] = player->card[i+1];  
            player->card[i+1] = temp;  
            isSorted = 0;  
        }  
    }  
    if (!isSorted) sortCards(player);  
}  
  
void blackjackHandler () {  
    resetPlayer(&A);    resetPlayer(&B);  
    printf("You're playing Blackjack.\n");  
    printf("Please input cards for each player:\n");  
    inputCards(&A);     inputCards(&B);  
      
    for (int i = 0; i < A.numCards; i++) {  
        if (!validateWeight(A.card[i].weight) || !validateSuit(A.card[i].suit)) {  
            printf("Input Error!\n");  
            return;  
        }  
    }  
    for (int i = 0; i < B.numCards; i++) {  
        if (!validateWeight(B.card[i].weight) || !validateSuit(B.card[i].suit)) {  
            printf("Input Error!\n");  
            return;  
        }  
    }  
      
    processBJ(&A);      processBJ(&B);  
  
    if (A.blackjack && !B.blackjack) {  
        printf("A wins with a Blackjack!\n");  
        return;  
    }  
    else if (!A.blackjack && B.blackjack) {  
        printf("B wins with a Blackjack!\n");  
        return;  
    }  
    else if (A.totalPoints == B.totalPoints) {  
        printf("Draw!\n");  
        return;  
    } else {  
        struct Player winner = (A.totalPoints > B.totalPoints) ? A : B;  
        int diff = A.totalPoints - B.totalPoints;  
        diff = diff < 0 ? -diff : diff;  
        printf("%c wins by %d points!\n",winner.name,diff);  
    }  
}  
  
void tractorHandler () {  
    resetPlayer(&A);        resetPlayer(&B);  
    printf("You're playing Tractor.\n");  
    printf("Please input cards for each player:\n");  
    inputCards(&A);         inputCards(&B);  
    processTractor(&A);     processTractor(&B);  
      
    int appearedBefore[200] = {0};  
    for (int i = 0; i < 3; i++) {  
        if ( !validateWeight(A.card[i].weight) || !validateWeight(B.card[i].weight) ||  
               !validateSuit(A.card[i].suit)   ||   !validateSuit(B.card[i].suit)   ||  
              appearedBefore[A.card[i].value]  ||  appearedBefore[B.card[i].value]  ) {  
                    
            printf("Input Error!\n");  
            return;  
        }  
        appearedBefore[A.card[i].value] = 1;    appearedBefore[B.card[i].value] = 1;  
    }  
    struct Player winner = A.totalPoints > B.totalPoints ? A : B;  
    printf("Winner is %c!\n",winner.name);  
  
    sortCards(&A);   sortCards(&B);  
    printf("A: ");  
    for (int i = 0; i < 3; i ++) {  
        printf("%c%s",A.card[i].suit, A.card[i].weight);  
        if (i!=2) printf(" ");  
        else printf("\n");  
    }  
    printf("B: ");  
    for (int i = 0; i < 3; i ++) {  
        printf("%c%s",B.card[i].suit, B.card[i].weight);  
        if (i!=2) printf(" ");  
        else printf("\n");  
    }  
}  
  
int main () {  
    A.name = 'A';   B.name = 'B';  
  
    while (1) {  
        printf("1. Blackjack\n");  
        printf("2. Tractor\n");  
        printf("0. Exit\n");  
        printf("Input your choice:\n");  
        while (1) {  
            int mode;  
            scanf("%d",&mode);  
            getchar();  
            if (mode == 0) return 0;  
            else if (mode == 1) blackjackHandler();  
            else if (mode == 2) tractorHandler();  
            else {  
                printf("Wrong Input. Input Again.\n");  
                continue;  
            }  
            break;  
        }  
        printf("Do you want to play again? (Y/N)\n");  
        char answer[10];  
        scanf("%s",answer);  
        if (answer[0] == 'Y') continue;  
        else if (answer[0] == 'N') return 0;  
    }  
}  