#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n\n");
    printf("        ▄     ▄ ▄▄▄▄▄▄▄ ▄▄▄     ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄▄▄▄▄          \n");
    printf("        █ █ ▄ █ █       █   █   █       █       █  █▄█  █       █        \n");
    printf("        █ ██ ██ █    ▄▄▄█   █   █       █   ▄   █       █    ▄▄▄█        \n");
    printf("        █       █   █▄▄▄█   █   █     ▄▄█  █ █  █       █   █▄▄▄         \n");
    printf("        █       █    ▄▄▄█   █▄▄▄█    █  █  █▄█  █       █    ▄▄▄█        \n");
    printf("        █   ▄   █   █▄▄▄█       █    █▄▄█       █ ██▄██ █   █▄▄▄         \n");
    printf("        █▄▄█ █▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄█   █▄█▄▄▄▄▄▄▄█        \n");
    printf("\n\n");

    int seconds = time(0);
    srand(seconds);

    int bigNumber = rand();
    int secretNumber = bigNumber % 100;

    int guess;
    int numberOfTries;
    int dificulty;
    double points = 1000;

    printf("Select the dificult you want.\n");
    printf("(1) Easy (2) Medium (3) Hard\n");
    printf("Choose: ");
    scanf("%d", &dificulty);

    switch (dificulty)
    {
    case 1:
        numberOfTries = 15;
        break;
    case 2:
        numberOfTries = 10;
        break;
    case 3:
        numberOfTries = 5;
        break;    
    default:
        numberOfTries = 10;
        break;
    }

    for (int i = 1; i <= numberOfTries; i++) {
        printf("\nGuess a number: ");
        scanf("%d", &guess);

        if (guess < 0) {
            printf("You should to try a positive number.\n");
            continue;
        }

        if (guess == secretNumber) {
            printf("Congratulations, you get it!\n");
            printf("You only needed %d tries.\n", i);
            printf("And made %.2f points.\n", points);
            break;
        } else if (guess > secretNumber) {
            printf("Your number is bigger than the secret number. Try again.\n");
        } else {
            printf("Your number is smallest than the secret number. Try again.\n");
        }

        double losePoints = abs(guess - secretNumber) / (double)i;
        points = points - losePoints;
    }
}