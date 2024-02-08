/*
Program calculates probability of drawing a card based on deck size, hand size, mulligan, and number of turns
*/
#include <stdio.h>


/*
calculates probability of not drawing card in initial hand
@param total : total number of cards in deck
@param hand : number of cards in initial hand
@param copies : number of copies of the card in the deck
@return prob : probability of not drawing the card
*/
double initialDraw(int total, int hand, int copies){
    double prob = 1.0;
    for(int i = 0; i < hand; i++) {
        prob *= ((double)(total - copies - i) / (total - i));

    }
    return prob;

}
/*
calculates probability of not drawing card during mulligan
@param total : total number of cards in deck
@param hand : number of cards in initial hand
@param copies : number of copies of the card in the deck
@param mull : number of cards to mulligan
@return prob : probability of not drawing the card
*/
double mulligan(int total, int hand, int copies, int mull) {
    double prob = 1.0;
    for(int i = 0; i < mull; i++) {
        prob *= (double)(total - hand - copies - i) / (total - hand - i);

    }
    return prob;

}
/*
calculates probability of not drawing the card each turn
@param total : total number of cards in deck
@param hand : number of cards in initial hand
@param copies : number of copies of the card in the deck
@param turn : number of turns
@return prob : probability of not drawing the card
*/
double drawTurn(int total, int hand, int copies, int turn) {
    double prob = 1.0;
    for(int i = 0; i < turn; i++) {
        prob *= (double)(total - hand - copies - i) / (total - hand - i);

    }
    return prob;


}



int main() {
    int total;
    int numCopies;
    int initHand;
    int mull;
    int numTurn;
    double notDrawFinal;

    printf("Enter how many total cards there are in the deck: ");
    scanf("%d", &total);
    printf("Enter how many copies of the card that you are looking for are in the deck: ");
    scanf("%d", &numCopies);
    printf("Enter your initial hand size: ");
    scanf("%d", &initHand);
    printf("Enter how many cards you are mulliganing: ");
    scanf("%d", &mull);
    printf("Enter what turn you want to draw the card by: ");
    scanf("%d", &numTurn);


    notDrawFinal = initialDraw(total, initHand, numCopies) * mulligan(total, initHand, numCopies, mull) * drawTurn(total, initHand, numCopies, numTurn);
    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf\n", numTurn, mull, (1.0 -notDrawFinal));

    return 0;
}