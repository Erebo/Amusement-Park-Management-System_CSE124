#include <stdio.h>

void waterKingdomRideChoosingOption(int age, float height) {
    printf("CHOOSE YOUR RIDES:\n\n");

    printf("1) FAMILY POOL\n");
    printf("2) WAVE POOL (MINIMUM AGE: 16)\n");
    printf("3) DANCING ZONE\n");
    printf("4) GREER SLIDE\n");
    printf("5) MULTI SLIDE\n");
    printf("6) YELLOW FLY\n");
    printf("7) BLUE TUNNEL (MINIMUM HEIGHT: 5FT)\n");
    printf("8) RED TUNNEL (MINIMUM HEIGHT: 5FT)\n");
    printf("9) LAZY RIVER\n\n");

    int waterKingdomUserRideChoises[15];
    int arrIdx = 0;     
    int waterKingdomUserRideChoise;

    chooseAgain:
    if (arrIdx >= 0 && arrIdx < 9) {
        printf("IF YOU ARE DONE WITH CHOOSING, TYPE 0\n");
        printf("> ");
        scanf("%d", &waterKingdomUserRideChoise);

        switch (waterKingdomUserRideChoise) {

            case 0:
                goto userDoneWithChoosing;
            case 2:
                if (age >= 16) {
                    for (int i = 0; i < 9; i++) {
                        if (waterKingdomUserRideChoises[i] == waterKingdomUserRideChoise) {
                            printf("YOU'VE ALREADY SELECTED THIS OPTION");
                            goto chooseAgain;
                        }
                    }
                    waterKingdomUserRideChoises[arrIdx] = waterKingdomUserRideChoise;
                    arrIdx++;
                    printf("OPTION SELECTED!\n");
                    goto chooseAgain;
                } else {
                    printf("You are not eligible for this ride, minimum age required is 16\n");
                    goto chooseAgain;
                }
            case 7:
            case 8:
                if (height >= 5) {
                    for (int i = 0; i < 9; i++) {
                        if (waterKingdomUserRideChoises[i] == waterKingdomUserRideChoise) {
                            printf("YOU'VE ALREADY SELECTED THIS OPTION");
                            goto chooseAgain;
                        }
                    }
                    waterKingdomUserRideChoises[arrIdx] = waterKingdomUserRideChoise;
                    arrIdx++;
                    printf("OPTION SELECTED!\n");
                    goto chooseAgain;
                } else {
                    printf("You are not eligible for this ride, minimum height required is 5ft\n");
                    goto chooseAgain;
                }
            case 1:
            case 3: 
            case 4:
            case 5: 
            case 6:
            case 9:
                for (int i = 0 ; i < 9 ; i++) {
                    if (waterKingdomUserRideChoises[i] == waterKingdomUserRideChoise) {
                        printf("YOU'VE ALREADY SELECTED THIS OPTION");
                        goto chooseAgain;
                    }
                }
                waterKingdomUserRideChoises[arrIdx] = waterKingdomUserRideChoise;
                arrIdx++;
                printf("OPTION SELECTED!\n");
                goto chooseAgain;

            default:
                    printf("INVALID OPTION\n");
                    goto chooseAgain;
        }
        
            userDoneWithChoosing:
                printf("Rides you choosed: ");

                for (int i = 0; i < arrIdx; i++) {
                    if (waterKingdomUserRideChoises[i] == 1) {
                        printf("| Family Pool |");
                    } else if (waterKingdomUserRideChoises[i] == 2) {
                        printf("| Wave Pool |");
                    } else if (waterKingdomUserRideChoises[i] == 3) {
                        printf("| Dancing Zone |");
                    } else if (waterKingdomUserRideChoises[i] == 4) {
                        printf("| Greer Slide |");
                    } else if (waterKingdomUserRideChoises[i] == 5) {
                        printf("| Multi Slide |");
                    } else if (waterKingdomUserRideChoises[i] == 6) {
                        printf("| Yellow Fly |");
                    } else if (waterKingdomUserRideChoises[i] == 7) {
                        printf("| Blue Tunnel |");
                    } else if (waterKingdomUserRideChoises[i] == 8) {
                        printf("| Red Tunnel |");
                    } else if (waterKingdomUserRideChoises[i] == 9) {
                        printf("| Lazy River |");
                    }
                }
    } else {
        printf("You've choosen maximum number of rides, can't choose anymore\n");
        goto userDoneWithChoosing;
    }
}

void waterKingdomWelcoming(int age, float height) {
    printf("\n");
    printf(" __        __   _                            \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  \n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ \n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ \n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \n");
    printf("                                             \n");

    printf("  _____    \n");
    printf(" |_   _|__  \n");
    printf("   | |/ _ \\ \n");
    printf("   | | (_) |\n");
    printf("   |_|\\___/ \n");
    printf("            \n");
    printf(" __        __    _              _  __  _             _            \n");
    printf(" \\ \\      / /_ _| |_ ___ _ __  | |/ / (_)_ __   __ _  __| | ___  _ __ ___  \n");
    printf("  \\ \\ /\\ / / _` | __/ _ \\ '__| | ' /  | | '_ \\ / _` |/ _` |/ _ \\| '_ ` _ \\ \n");
    printf("   \\ V  V / (_| | ||  __/ |    | . \\  | | | | | (_| | (_| | (_) | | | | | |\n");
    printf("    \\_/\\_/ \\__,_|\\__\\___|_|    |_|\\_\\ |_|_| |_|\\__, |\\__,_|\\___/|_| |_| |_|\n");
    printf("                                               |___/                       \n");

    waterKingdomRideChoosingOption(age, height);
}
