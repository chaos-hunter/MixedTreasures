#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    // Initialize varaibles here
    int birthYear;
    int currentAward = 100;
    char userAnswer;
    char lifelineUsed = 0;
    int x;
    srand(time(NULL));

    // Ask the user for birth year and check if valid
    do {
        printf("Enter your birth Year (yyyy): ");
        scanf("%d", &birthYear);
    } while (birthYear < 1000 || birthYear > 9999); // prompt user to repeat if invalid birth year is entered

    // Calculate the lucky number
    int luckyNumber = 0;
    int tempYear = birthYear;
    while (tempYear > 0) {
        luckyNumber += tempYear % 10;
        tempYear /= 10;
    }

    printf("\n");
    // Iterate to print 25 stars
    for (int i = 0; i < 25; i++) {
        printf("*");
    }
    printf("\nWelcome to Mixed Treasures\n");
    printf("Your Lucky Number is %d\n", luckyNumber);
    for (int i = 0; i < 25; i++) {
        printf("*");
    }
    printf("\n");

    // Start the game loop for 7 questions
    for (int questionNumber = 1; questionNumber <= 7; questionNumber++) {

        // Set the award for the questions
        if (questionNumber == 1){
            currentAward = 100;
        }
        else if (questionNumber % 2 == 0) {
            currentAward = currentAward * 5;
        }
        else {
            currentAward = currentAward * 2;
        }
        printf("\nQuestion %d: This question is worth $%d \n", questionNumber, currentAward);

        // Generate a random greeting number
        x = (rand() % 5) + 1;
        char* greeting; // to store the random greetings
        switch (x){
            case 1:
                greeting = "Bravo, ";
                break;
            case 2:
                greeting = "Congrats, ";
                break;
            case 3:
                greeting = "Well done, ";
                break;
            case 4:
                greeting = "Very nice, ";
                break;
            case 5:
                greeting = "Proud of you, ";
                break;
        }

        // Display the question and choices
        switch (questionNumber) {
            case 1:
                printf("\nWhat is the University of Guelph's mascot?\n");
                printf("A. Dragon\nB. Centaur\nC. Aggie\nD. Gryphon\n");
                break;
            case 2:
                printf("\nWhat is the name of the cannon that is painted by students?\n");
                printf("A. Old Jeremiah\nB. Painty McPaintface\nC. George III\nD. Duke of Wellington\n");
                break;
            case 3:
                printf("\nWho was the School of Computer Science building at UoG named after?\n");
                printf("A. Joseph Reynolds\nB. Ryan Reynolds\nC. Joshua Reynolds\nD. Greg Klotz\n");
                break;
            case 4:
                printf("\nHow many brains does an octopus have?\n");
                printf("A. 9\nB. 2\nC. 1\nD. 16\n");
                break;
            case 5:
                printf("\nHow many bones does a shark have?\n");
                printf("A. 42\nB. 5\nC. 10\nD. 0\n");
                break;
            case 6:
                printf("\nWhat is the largest ocean on Earth?\n");
                printf("A. Pacific\nB. Atlantic\nC. Indian\nD. Arctic\n");
                break;
            case 7:
                printf("\nWhat is the name of the largest fish in the sea?\n");
                printf("A. Blue whale\nB. Great white shark\nC. Hammerhead shark\nD. Whale shark\n");
                break;
            default:
                break;
        }

        // Check if the player wants to use the lifeline
        if (!lifelineUsed) {
            char lifelineResponse;
            printf("\nWould you like to use a lifeline (50-50)?\n");
            printf("Enter Y or y, N or n: ");
            scanf(" %c", &lifelineResponse);
            lifelineResponse = toupper(lifelineResponse);
            // Check if they used the lifeline
            if (lifelineResponse == 'Y') {
                lifelineUsed = 1;
                printf("\nOK - here are your 2 choices after using the 50-50 lifeline\n");
                // display two options for the question
                switch (questionNumber) {
                    case 1:
                        printf("\nA. Dragon\nD. Gryphon\n");
                        printf("\nReminder - You get only 1 lifeline - and you are using it now\n");
                        break;
                    case 2:
                        printf("\nA. Old Jeremiah\nD. Duke of Wellington\n");
                        printf("\nReminder - You get only 1 lifeline - and you are using it now\n");
                        break;
                    case 3:
                        printf("\nA. Joseph Reynolds\nD. Greg Klotz\n");
                        printf("\nReminder - You get only 1 lifeline - and you are using it now\n");
                        break;
                    case 4:
                        printf("\nA. 9\nD. 16\n");
                        printf("\nReminder - You get only 1 lifeline - and you are using it now\n");
                        break;
                    case 5:
                        printf("\nA. 42\nD. 0\n");
                        printf("\nReminder - You get only 1 lifeline - and you are using it now\n");
                        break;
                    case 6:
                        printf("\nA. Pacific\nD. Arctic\n");
                        printf("\nReminder - You get only 1 lifeline - and you are using it now\n");
                        break;
                    case 7:
                        printf("\nA. Blue whale\nD. Whale shark\n");
                        printf("\nReminder - You get only 1 lifeline - and you are using it now\n");
                        break;
                    default:
                        break;
                }
            }
        }
        // Ask the user for answer and check whether is valid
        do {
            printf("\nEnter your answer (A, B, C, D) here: ");
            scanf(" %c", &userAnswer);
            userAnswer = toupper(userAnswer);
        } while (userAnswer != 'A' && userAnswer != 'B' && userAnswer != 'C' && userAnswer != 'D');

        // Check if users answers are coorect and provide a  response
        if (questionNumber == 1 && userAnswer =='D') {
            printf("\n%sYou just won $%d\n", greeting, currentAward);
            printf("Let us play the next question now\n");
        }
        else if (questionNumber == 2 && userAnswer == 'A') {
            printf("\n%sYou just won $%d\n", greeting, currentAward);
            printf("Let us play the next question now\n");
        }
        else if (questionNumber == 3 && userAnswer == 'A') {
            printf("\n%sYou just won $%d\n", greeting, currentAward);
            printf("Let us play the next question now\n");
        }
        else if (questionNumber == 4 && userAnswer == 'A') {
            printf("\n%sYou just won $%d\n", greeting, currentAward);
            printf("Let us play the next question now\n");
        }
        else if (questionNumber == 5 && userAnswer == 'D') {
            printf("\n%sYou just won $%d\n", greeting, currentAward);
            printf("Let us play the next question now\n");
        }
        else if (questionNumber == 6 && userAnswer == 'A') {
            printf("\n%sYou just won $%d\n", greeting, currentAward);
            printf("Let us play the next question now\n");
        }
        else if (questionNumber == 7 && userAnswer == 'D') {
            printf("\n%sYou just won $%d\n", greeting, currentAward);
            printf("It was fun playing with you");

        }
        // codition for when player is wrong
        else {
            // Calculate the reduced award
            if (questionNumber == 1){
                currentAward = 0;
                printf("\nOops - that was incorrect. You won %d dollars, but it was fun playing with you.\n", currentAward);
            }
            else if (questionNumber % 2 == 0) {
                currentAward -= currentAward / 5;
                printf("\nOops - that was incorrect. You still won $%d. Well done. It was fun playing with you\n", currentAward);
            }else {
                currentAward /= 2;
                printf("\nOops - that was incorrect. You still won $%d. Well done. It was fun playing with you\n", currentAward);
            }
            // End the Game
            break;
}
}
    return 0;
}
