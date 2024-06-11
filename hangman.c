#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LEN 20
#define MAX_GUESSES 6

void printHangman(int guessesleft)
{
    switch (guessesleft)
    {
        case 6:
            printf(" _______\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      \n");
            printf("|      \n");
            printf("|      \n");
            break;
        case 5:
            printf(" _______\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|       |\n");
            printf("|      \n");
            printf("|      \n");
            break;
        case 4:
            printf(" _______\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\n");
            printf("|      \n");
            printf("|      \n");
            break;
        case 3:
            printf(" _______\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|      \n");
            printf("|      \n");
            break;
        case 2:
            printf(" _______\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|      /\n");
            printf("|      \n");
            break;
        case 1:
            printf(" _______\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|      / \\\n");
            printf("|      \n");
            break;
        case 0:
            printf(" _______\n");
            printf("|       |\n");
            printf("|      X\n");
            printf("|      /|\\\n");
            printf("|      / \\\n");
            printf("|      GAME OVER\n");
            break;
    }

}

int main()
{
    srand(time (NULL));
    char words[][MAX_WORD_LEN] = {"apple", "banana", "cherry", "date", "elderberry","peach","Lambo","G-wagon","Pagani" };
    int numWords = sizeof(words)/sizeof(words[0]);
    int wordLength;
    char word[MAX_WORD_LEN];
    strcpy(word, words[rand() % numWords]);
    wordLength = strlen(word);

    char guessedWord[MAX_WORD_LEN];
    for (int i = 0; i < wordLength; i++) 
    {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    int guessesLeft = MAX_GUESSES;

    while (guessesLeft > 0) {
        printf("Hangman: %s\n", guessedWord);
        printHangman(guessesLeft);
        printf("Guesses left: %d\n", guessesLeft);
        printf("Enter a letter: ");
        char guess;
        scanf(" %c", &guess);

        int correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            guessesLeft--;
        }

        int won = 1;
        for (int i = 0; i < wordLength; i++) {
            if (guessedWord[i] == '_') {
                won = 0;
                break;
            }
        }

        if (won) {
            printf("Congratulations, you won! The word was %s.\n", word);
            return 0;
        }
    }

    printf("Game over! The word was %s.\n", word);
    return 0;
}
