#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define INVALID_DECK 1
#define NO_DECK 2
#define INVALID_CARD 3
#define CHEATING 4

//puts: 오직 문자열만 출력, 개행이 포함됨

void put_error(int errno) {
    switch (errno)
    {
        case INVALID_DECK:
            puts("ERROR: Invalid deck, only 23456789TJDKA are allowed");
            exit(errno);
        case NO_DECK:
            puts("ERROR: No deck provided, ./blackjack <deck> (23456789TJDKA)");    
            exit(errno);
        case INVALID_CARD:
            puts("ERROR: An invalid card was found in the deck.");
            exit(errno);
        case CHEATING:
            puts("ERROR: Cheating detected, more than 4 cards of the same value.");
            exit(errno);
        default:
            printf("ERROR: Unknown error %d\n", errno);
            break;
    }
}

//2~9 까지의 숫자 : 그 카드의 숫자값
//JQKTD : 10
//A는 1 또는 11, 기준은 현재 sum + 11이 21 초과인경우 : 1 나머지 11
int get_card_value(char card, int *sum) {
    if (card >= '2' && card <= '9')
        return card - '0';
    switch (card)
    {
        case 'J': // Jack
        case 'Q': // Queen
        case 'K': // King
        case 'T': // Ten
        case 'D': // Diamond
            return 10;
        case 'A':
            if (*sum + 11 > 21)
                return 1;
            else
                return 11;
        default:
            break;
    }
}

// 한 종류의 카드가 4개 이상인지 확인
int cheating(char *deck) {
    int cardsCounter[13] = {0};
    for (int i = 0; i < strlen(deck); i++) {
        switch (deck[i])
        {
            case '2':
                cardsCounter[0]++;
                break;
            case '3':
                cardsCounter[1]++;
                break;
            case '4':
                cardsCounter[2]++;
                break;
            case '5':
                cardsCounter[3]++;
                break;
            case '6':
                cardsCounter[4]++;
                break;
            case '7':
                cardsCounter[5]++;
                break;
            case '8':
                cardsCounter[6]++;
                break;
            case '9':
                cardsCounter[7]++;
                break;
            case 'T':
                cardsCounter[8]++;
                break;
            case 'J':
                cardsCounter[9]++;
                break;
            case 'Q':
                cardsCounter[10]++;
                break;
            case 'K':
                cardsCounter[11]++;
                break;
            case 'A':
                cardsCounter[12]++;
                break;
            default:
                break;
        }
    }
    for (int i = 0; i < 13; i++) {
        if (cardsCounter[i] > 4)
            return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) put_error(NO_DECK);
    char possibleValues[14] = "23456789TJDKA\0";
    char *deck = argv[1];
    int length = strlen(deck);
    if (length == 0) put_error(NO_DECK);
    if (cheating(deck)) put_error(CHEATING);
    for (int i = 0; i < strlen(deck); i++) {
        if (strchr(possibleValues, deck[i]) == NULL)
            put_error(INVALID_DECK);
    }

    int score = 0;
    for (int i = 0; i < strlen(deck); i++) {
        score += get_card_value(deck[i], &score);
    }
    if (score != 21)
        printf("%d\n", score);
    else
        puts("Blackjack!");
}