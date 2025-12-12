#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct userLine {
    int userSerial;
    struct userLine* next;
};

struct userLine* start = NULL;

struct userLine* createNode(int serial) {
    struct userLine* newNode = (struct userLine*)malloc(sizeof(struct userLine));

    newNode->userSerial = serial;
    newNode->next = NULL;

    return newNode;
}

void insertInUserLine(int serial) {
    struct userLine* newNode = (struct userLine*)malloc(sizeof(struct userLine));

    newNode->userSerial = serial;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
    } else {
        struct userLine* i = start;

        while (i->next != NULL) {
            i = i->next;
        }
        i->next = newNode;
    }
}

void deleteFromTheUserLine() {
    if (start == NULL) {
        printf("There's nothing to delete \n");
    } else {
        start = start->next;
    }
}

void printFamilyPoolLine() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 5 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void familyPoolFunction() {
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);
    insertInUserLine(6);
    insertInUserLine(7);
    insertInUserLine(8);

    printf("\nFamily Pool is currently full with 200 people, sorry you have to wait\n\n");
    printFamilyPoolLine();

    int totalFamilyPoolMember = 200;

    for (int i = 0; i < 5; i++) {
        Sleep(3000);
        totalFamilyPoolMember--;
        printf("One member left the family pool!\n");
        printf("Current Family Pool member status: %d\n", totalFamilyPoolMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered the pool\n", i + 1);
        totalFamilyPoolMember++;
        printf("Current Family Pool member status: %d\n", totalFamilyPoolMember);
        Sleep(1000);
        i < 4 ? printFamilyPoolLine() : printf("");
    }
    printf("\nyou are in!\n");
}

void userStartsRiding() {
    int rideNumber;
    printf("Choose the ride number you want to go \n");
    printf("> ");
    scanf("%d", &rideNumber);

    if (rideNumber == 1) {
        familyPoolFunction();
    }
}

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
                for (int i = 0; i < 9; i++) {
                    if (waterKingdomUserRideChoises[i] == waterKingdomUserRideChoise) {
                        printf("YOU'VE ALREADY SELECTED THIS OPTION\n");
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
                printf("| 1) Family Pool |");
            } else if (waterKingdomUserRideChoises[i] == 2) {
                printf("| 2) Wave Pool |");
            } else if (waterKingdomUserRideChoises[i] == 3) {
                printf("| 3) Dancing Zone |");
            } else if (waterKingdomUserRideChoises[i] == 4) {
                printf("| 4) Greer Slide |");
            } else if (waterKingdomUserRideChoises[i] == 5) {
                printf("| 5) Multi Slide |");
            } else if (waterKingdomUserRideChoises[i] == 6) {
                printf("| 6) Yellow Fly |");
            } else if (waterKingdomUserRideChoises[i] == 7) {
                printf("| 7) Blue Tunnel |");
            } else if (waterKingdomUserRideChoises[i] == 8) {
                printf("| 8) Red Tunnel |");
            } else if (waterKingdomUserRideChoises[i] == 9) {
                printf("| 9) Lazy River |");
            }
        }
        printf("\n\n");
    } else {
        printf("You've choosen maximum number of rides, can't choose anymore\n");
        goto userDoneWithChoosing;
    }

    userStartsRiding();
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
