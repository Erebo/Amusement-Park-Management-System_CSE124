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

    if (arrIdx >= 0 && arrIdx < 15) {
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
                printf("INVALID OPTION! TRY AGAIN.\n");
                goto chooseAgain;
        }

    } else {
        printf("YOU HAVE CHOSEN THE MAXIMUM NUMBER OF RIDES. YOU CANNOT CHOOSE ANY MORE.\n");
    }

userDoneWithChoosing:

    printf("\nRIDES YOU CHOSE: ");
    for (int i = 0; i < arrIdx; i++) {
        printf("%d ", waterKingdomUserRideChoises[i]);
    }
    printf("\n");
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
