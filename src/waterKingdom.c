#include <stdio.h>

void waterKingdomRideChoosingOption() {
    printf("Choose your rides: \n");

    printf("1) Family Pool\n");
    printf("2) Wave Pool\n");
    printf("3) Dancing Zone\n");
    printf("4) Greer Slide\n");
    printf("5) Multi Slide\n");
    printf("6) Yellow Fly\n");
    printf("7) Blue Tunnel\n");
    printf("8) Red Tunnel\n");
    printf("9) Lazy River\n");

    int waterKingdomUserRideChoises[15];

    chooseAgain:
        int arrIdx;
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

                for (int i = 0 ; i<arrIdx  ; i++) {
                    printf("%d ", waterKingdomUserRideChoises[i]);
                }
        } else {
            printf("You've choosen maximum number of rides, can't choose anymore\n");
        }
}

void waterKingdomWelcoming() {
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

    waterKingdomRideChoosingOption();
}

