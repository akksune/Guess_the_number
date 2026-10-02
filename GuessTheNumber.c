#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void displayTitle() {
    printf("====================\n");
    printf("|  Guess The Number |\n");
    printf("====================\n");
}

int gameMode() {
    char gamemode[20];
    printf("\nHow hard do you want the game to be?\n");
    printf("Easy (1-10)\n");
    printf("Medium (1-50)\n");
    printf("Hard (1-100)\n");
    printf("God Mode (1-1000)\n");
    printf("Custom\n");
    printf("- ");
    scanf(" %[^\n]", gamemode);
    if (_stricmp(gamemode, "Easy") == 0) {
        printf("\nYou picked Easy!\n");
        return 10;
    }
    else if (_stricmp(gamemode, "Medium") == 0) {
        printf("\nYou picked Medium!\n");
        return 50;
    }
    else if (_stricmp(gamemode, "Hard") == 0) {
        printf("\nYou picked Hard!\n");
        return 100;
    }
    else if (_stricmp(gamemode, "God Mode") == 0) {
        printf("\nYou picked God Mode!\n");
        return 1000;
    }
    else if (_stricmp(gamemode, "Custom") == 0) {
        int customMax;
        printf("\nEnter the maximum number: ");
        scanf("%d", &customMax);
        if (customMax < 2) {
            printf("That's too low. Let's use 10 instead.\n");
            customMax = 10;
        }
        printf("Custom mode: 1-%d!\n", customMax);
        return customMax;
    }
    else {
        printf("\nSeems like you didn't put in any of the choices. Let's run it back.\n");
        return gameMode();
    }
}

void playGame(int maximum) {
    int secretNumber;
    int guess;
    int attempts = 0;
    secretNumber = (rand() % maximum) + 1;
    printf("\n========================\n");
    printf("|   GUESS THE NUMBER   |\n");
    printf("========================\n");
    printf("I'm thinking of a number between 1 and %d.\n", maximum);

    do {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        }
        else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        }
        else {
            printf("\nCorrect! You got it!\n");
            printf("The number was %d.\n", secretNumber);
            printf("You got it in %d attempt(s)!\n", attempts);
        }
    } while (guess != secretNumber);
}

int main() {
    char start;
    char again;
    srand(time(NULL));
    displayTitle();
    printf("Are you ready to start guessing? (Y/N): ");
    scanf(" %c", &start);

    if (start == 'Y' || start == 'y') {
        printf("\nLet's Get Started!\n");
        do {
            int maximum;
            maximum = gameMode();
            playGame(maximum);
            printf("\nDo you want to play again? (Y/N): ");
            scanf(" %c", &again);
        } while (again == 'Y' || again == 'y');
        printf("\nThanks for playing! See you next time!\n");
    }
    else {
        printf("\nOK! See you later!\n");
    }
    return 0;
}