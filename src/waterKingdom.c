#include <stdio.h>

void waterKingdomRideChoosingOption() {
    printf("CHOOSE YOUR RIDES:\n\n");

    printf("1) FAMILY POOL\n");
    printf("2) WAVE POOL\n");
    printf("3) DANCING ZONE\n");
    printf("4) GREER SLIDE\n");
    printf("5) MULTI SLIDE\n");
    printf("6) YELLOW FLY\n");
    printf("7) BLUE TUNNEL\n");
    printf("8) RED TUNNEL\n");
    printf("9) LAZY RIVER\n\n");

    int waterKingdomUserRideChoises[15];
    int arrIdx = 0;     
    int waterKingdomUserRideChoise;

    chooseAgain:
        int arrIdx = 0;
        int waterKingdomUserRideChoise;

chooseAgain:

    if (arrIdx >= 0 && arrIdx < 15) {  // SAFE LIMIT CHECK
        printf("IF YOU ARE DONE WITH CHOOSING, TYPE 0\n");
        printf("> ");
        scanf("%d", &waterKingdomUserRideChoise);

        switch (waterKingdomUserRideChoise) {

            case 0:
                goto userDoneWithChoosing;

            case 1: case 2: case 3: case 4:
            case 5: case 6: case 7: case 8:
            case 9:
                waterKingdomUserRideChoises[arrIdx] = waterKingdomUserRideChoise;
                arrIdx++;
                printf("OPTION SELECTED!\n");
                goto chooseAgain;

                default:
                    printf("Invalid option!\n");
                    goto chooseAgain;
            }
        
            userDoneWithChoosing:
                printf("Rides you choosed: ");

                for (int i = 0; i < arrIdx; i++) {
                    if (i + 1 == 1) {
                        printf("Family Pool ");
                    } else if (i + 1 == 2) {
                        printf("Wave Pool ");
                    } else if (i + 1 == 3) {
                        printf("Dancing Zone ");
                    } else if (i + 1 == 4) {
                        printf("Greer Slide ");
                    } else if (i + 1 == 5) {
                        printf("Multi Slide ");
                    } else if (i + 1 == 6) {
                        printf("Yellow Fly ");
                    } else if (i + 1 == 7) {
                        printf("Blue Tunnel ");
                    } else if (i + 1 == 8) {
                        printf("Red Tunnel ");
                    } else if (i + 1 == 9) {
                        printf("Lazy River ");
                    }
                }
        } else {
            printf("You've choosen maximum number of rides, can't choose anymore\n");
        }
}



void waterKingdomWelcoming() {

    printf("\n");
    printf("***************************************************************\n");
    printf("*                                                             *\n");
    printf("*                   WELCOME TO WATER KINGDOM                  *\n");
    printf("*                                                             *\n");
    printf("***************************************************************\n\n");

    waterKingdomRideChoosingOption();
}
