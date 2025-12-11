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

    chooseAgain:
        int arrIdx = 0;
        int waterKingdomUserRideChoise;

        if (arrIdx >= 0 && arrIdx <= 7){
            printf("If you are done with choosing, type 0\n");
            printf("> ");
            scanf("%d", &waterKingdomUserRideChoise);

            switch (waterKingdomUserRideChoise){
                case 0:
                    goto userDoneWithChoosing;
                    break;
                case 1:
                    waterKingdomUserRideChoises[arrIdx] = 1;
                    arrIdx++;
                    printf("Option selected!\n");
                    goto chooseAgain;
                    break;

                case 2:
                    waterKingdomUserRideChoises[arrIdx] = 2;
                    arrIdx++;
                    printf("Option selected!\n");
                    goto chooseAgain;
                    break;

                case 3:
                    waterKingdomUserRideChoises[arrIdx] = 3;
                    arrIdx++;
                    printf("Option selected!\n");
                    goto chooseAgain;
                    break;

                case 4:
                    waterKingdomUserRideChoises[arrIdx] = 4;
                    arrIdx++;
                    printf("Option selected!\n");
                    goto chooseAgain;
                    break;

                case 5:
                    waterKingdomUserRideChoises[arrIdx] = 5;
                    arrIdx++;
                    printf("Option selected!\n");
                    goto chooseAgain;
                    break;

                case 6:
                    waterKingdomUserRideChoises[arrIdx] = 6;
                    arrIdx++;
                    printf("Option selected!\n");
                    goto chooseAgain;
                    break;

                case 8:
                    waterKingdomUserRideChoises[arrIdx] = 8;
                    arrIdx++;
                    printf("Option selected!\n");
                    goto chooseAgain;
                    break;

                case 9:
                    waterKingdomUserRideChoises[arrIdx] = 9;
                    arrIdx++;
                    printf("Option selected!\n");
                    goto chooseAgain;
                    break;

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
