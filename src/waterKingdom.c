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

    int arrIdx = 0;                    // FIXED: MUST START AT 0
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

    // 🔥 FULL CAPS ASCII ART BANNER (UPDATED)
    printf("__        __   _    _                     _          _   _                               \n");
    printf("\\ \\      / /__| | _| | ___  ___  _ __   | | ___  __| | | | __ ___   ____ _ _ __   ___   \n");
    printf(" \\ \\ /\\ / / _ \\ |/ / |/ _ \\/ _ \\| '_ \\  | |/ _ \\/ _` | | |/ _` \\ \\ / / _` | '_ \\ / _ \\  \n");
    printf("  \\ V  V /  __/   <| |  __/ (_) | | | | | |  __/ (_| | | | (_| |\\ V / (_| | | | |  __/  \n");
    printf("   \\_/\\_/ \\___|_|\\_\\_|\\___|\\___/|_| |_| |_|\\___|\\__,_| |_|\\__,_| \\_/ \\__,_|_| |_|\\___|  \n");
    printf("                                                                                           \n");

    printf("__          __        _                              _                 \n");
    printf("\\ \\        / /__  ___| |__   ___  _ __   __ _ _ __  | |_ ___  _ __ ___ \n");
    printf(" \\ \\ /\\ / / _ \\/ __| '_ \\ / _ \\| '_ \\ / _` | '__| | __/ _ \\| '__/ _ \\ \n");
    printf("  \\ V  V /  __/ (__| | | | (_) | | | | (_| | |    | || (_) | | |  __/ \n");
    printf("   \\_/\\_/ \\___|\\___|_| |_|\\___/|_| |_|\\__,_|_|     \\__\\___/|_|  \\___| \n");
    printf("\n");

    waterKingdomRideChoosingOption();
}
