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

void clearUserLine() {
    struct userLine* cur = start;
    while (cur != NULL) {
        struct userLine* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    start = NULL;
}

void familyPoolFunction() {
    clearUserLine();
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
    printf("\nyou are in!\n\n");
}

void printWavePoolLine() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 8 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void wavePoolFunction() {
    clearUserLine();
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);
    insertInUserLine(6);
    insertInUserLine(7);
    insertInUserLine(8);
    insertInUserLine(9);

    int totalWavePoolMember = 100;
    printf("\nWave Pool is currently full with %d people, sorry you have to wait\n\n", totalWavePoolMember);
    printWavePoolLine();

    for (int i = 0; i < 8; i++) {
        Sleep(3000);
        totalWavePoolMember--;
        printf("One member left the Wave Pool!\n");
        printf("Current Wave Pool member status: %d\n", totalWavePoolMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered the pool\n", i + 1);
        totalWavePoolMember++;
        printf("Current Wave Pool member status: %d\n", totalWavePoolMember);
        Sleep(1000);
        i < 7 ? printWavePoolLine() : printf("");
    }
    printf("\nyou are in!\n");
}

void printDancingZoneLine() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 5 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void dancingZoneFunction() {
    clearUserLine();
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);

    int totalDancingZoneMember = 50;
    printf("\nDancing Zone is currently full with %d people, sorry you have to wait\n\n", totalDancingZoneMember);
    printDancingZoneLine();

    for (int i = 0; i < 5; i++) {
        Sleep(3000);
        totalDancingZoneMember--;
        printf("One member left the Dancing Zone!\n");
        printf("Current Dancing Zone member status: %d\n", totalDancingZoneMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered the pool\n", i + 1);
        totalDancingZoneMember++;
        printf("Current Dancing Zone member status: %d\n", totalDancingZoneMember);
        Sleep(1000);
        i < 4 ? printDancingZoneLine() : printf("");
    }
    printf("\nyou are in!\n");
}

void printGreerSlideLine() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 1 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void greerSlideFunction() {
    clearUserLine();
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);

    int totalDancingZoneMember = 30;
    printf("\nGreer Slide is currently full with %d people, sorry you have to wait\n\n", totalDancingZoneMember);
    printGreerSlideLine();

    for (int i = 0; i < 1; i++) {
        Sleep(3000);
        totalDancingZoneMember--;
        printf("One member left the Greer Slide!\n");
        printf("Current Greer Slide member status: %d\n", totalDancingZoneMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered the pool\n", i + 1);
        totalDancingZoneMember++;
        printf("Current Greer Slide member status: %d\n", totalDancingZoneMember);
        Sleep(1000);
        i < 0 ? printGreerSlideLine() : printf("");
    }
    printf("\nyou are in!\n");
}

void printMultiSlideLine() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 5 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void multiSlideFunction() {
    clearUserLine();
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);
    insertInUserLine(6);
    insertInUserLine(7);

    int totalDancingZoneMember = 30;
    printf("\nMulti Slide is currently full with %d people, sorry you have to wait\n\n", totalDancingZoneMember);
    printMultiSlideLine();

    for (int i = 0; i < 5; i++) {
        Sleep(3000);
        totalDancingZoneMember--;
        printf("One member left the Multi Slide!\n");
        printf("Current Multi Slide member status: %d\n", totalDancingZoneMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered Multi Slide\n", i + 1);
        totalDancingZoneMember++;
        printf("Current Multi Slide member status: %d\n", totalDancingZoneMember);
        Sleep(1000);
        i < 4 ? printMultiSlideLine() : printf("");
    }
    printf("\nyou are in!\n");
}

void printYellowFly() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 5 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void yellowFlyFunction() {
    clearUserLine();
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);
    insertInUserLine(6);
    insertInUserLine(7);

    int totalYellowFlyMember = 30;
    printf("\nYellow Fly is currently full with %d people, sorry you have to wait\n\n", totalYellowFlyMember);
    printYellowFly();

    for (int i = 0; i < 5; i++) {
        Sleep(3000);
        totalYellowFlyMember--;
        printf("One member left the Yellow Fly!\n");
        printf("Current Yellow Fly member status: %d\n", totalYellowFlyMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered Yellow Fly\n", i + 1);
        totalYellowFlyMember++;
        printf("Current Yellow Fly member status: %d\n", totalYellowFlyMember);
        Sleep(1000);
        i < 4 ? printYellowFly() : printf("");
    }
    printf("\nyou are in!\n");
}

void printBlueTunnel() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 5 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void blueTunnelFunction() {
    clearUserLine();
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);
    insertInUserLine(6);
    insertInUserLine(7);

    int totalBlueTunnelMember = 30;
    printf("\nBlue Tunnel is currently full with %d people, sorry you have to wait\n\n", totalBlueTunnelMember);
    printBlueTunnel();

    for (int i = 0; i < 5; i++) {
        Sleep(3000);
        totalBlueTunnelMember--;
        printf("One member left the Blue Tunnel!\n");
        printf("Current Blue Tunnel member status: %d\n", totalBlueTunnelMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered Blue Tunnel\n", i + 1);
        totalBlueTunnelMember++;
        printf("Current Blue Tunnel member status: %d\n", totalBlueTunnelMember);
        Sleep(1000);
        i < 4 ? printBlueTunnel() : printf("");
    }
    printf("\nyou are in!\n");
}

void printRedTunnel() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 5 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void redTunnelFunction() {
    clearUserLine();
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);
    insertInUserLine(6);
    insertInUserLine(7);

    int totalRedTunnelMember = 30;
    printf("\nRed Tunnel is currently full with %d people, sorry you have to wait\n\n", totalRedTunnelMember);
    printRedTunnel();

    for (int i = 0; i < 5; i++) {
        Sleep(3000);
        totalRedTunnelMember--;
        printf("One member left the Red Tunnel!\n");
        printf("Current Red Tunnel member status: %d\n", totalRedTunnelMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered Red Tunnel\n", i + 1);
        totalRedTunnelMember++;
        printf("Current Red Tunnel member status: %d\n", totalRedTunnelMember);
        Sleep(1000);
        i < 4 ? printRedTunnel() : printf("");
    }
    printf("\nyou are in!\n");
}

void printLazyRiverLine() {
    struct userLine* i = start;

    while (i != NULL) {
        i->userSerial == 5 ? printf("%d (You are here) \n", i->userSerial) : printf("%d\n", i->userSerial);
        i = i->next;
    }
    printf("\n");
}

void lazyRiverFunction() {
    clearUserLine();
    insertInUserLine(1);
    insertInUserLine(2);
    insertInUserLine(3);
    insertInUserLine(4);
    insertInUserLine(5);
    insertInUserLine(6);
    insertInUserLine(7);

    int totalLazyRiverMember = 30;
    printf("\nLazy River is currently full with %d people, sorry you have to wait\n\n", totalLazyRiverMember);
    printLazyRiverLine();

    for (int i = 0; i < 5; i++) {
        Sleep(3000);
        totalLazyRiverMember--;
        printf("One member left the Lazy River!\n");
        printf("Current Lazy River member status: %d\n", totalLazyRiverMember);
        Sleep(1000);
        deleteFromTheUserLine();
        printf("User with serial number %d entered Lazy River\n", i + 1);
        totalLazyRiverMember++;
        printf("Current Lazy River member status: %d\n", totalLazyRiverMember);
        Sleep(1000);
        i < 4 ? printLazyRiverLine() : printf("");
    }
    printf("\nyou are in!\n");
}

int deleteRideFromTheRideList(int waterKingdomUserRideChoises[], int size, int rideNumber) {
    int deletingNumbersIdx = -1;

    for (int i = 0; i < size; i++) {
        if (waterKingdomUserRideChoises[i] == rideNumber) {
            deletingNumbersIdx = i;
            break;
        }
    }

    if (deletingNumbersIdx == -1) {
        return size;
    }

    for (int i = deletingNumbersIdx; i < size - 1; i++) {
        waterKingdomUserRideChoises[i] = waterKingdomUserRideChoises[i + 1];
    }

    return size - 1;
}

void printLeftRides(int totalRideLeft, int waterKingdomUserRideChoises[]) {
    printf("Ride left: ");

    for (int i = 0 ; i < totalRideLeft ; i++) {
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
}

void userStartsRiding(int waterKingdomUserRideChoises[], int arrIdx) {
    int rideNumber;
    chooseAgainToStartRiding:
        printf("Choose the ride number you want to go \n");
        printf("Or type 0 to exit\n");
        printf("> ");
        scanf("%d", &rideNumber);

        if (rideNumber == 0) {
            return;
        }

        if (rideNumber == 1) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 1) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                familyPoolFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else if (rideNumber == 2) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 2) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                wavePoolFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else if (rideNumber == 3) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 3) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                dancingZoneFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else if (rideNumber == 4) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 4) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                greerSlideFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else if (rideNumber == 5) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 5) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                multiSlideFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else if (rideNumber == 6) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 6) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                yellowFlyFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else if (rideNumber == 7) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 7) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                blueTunnelFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else if (rideNumber == 8) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 8) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                redTunnelFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else if (rideNumber == 9) {
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (waterKingdomUserRideChoises[i] == 9) {
                    count++;
                    break;
                }
            }

            if (count == 1) {
                lazyRiverFunction();
                int leftRideNumber = deleteRideFromTheRideList(waterKingdomUserRideChoises, arrIdx, rideNumber);
                printLeftRides(leftRideNumber, waterKingdomUserRideChoises);
                goto chooseAgainToStartRiding;
            } else {
                printf("Your rider list doesn't contain this ride\n\n");
                goto chooseAgainToStartRiding;
            }
        } else {
            printf("Invalid option!\n");
            goto chooseAgainToStartRiding;
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

    int waterKingdomUserRideChoises[15] = {0};
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
                        for (int i = 0; i < arrIdx; i++) {
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
                        for (int i = 0; i < arrIdx; i++) {
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
                    for (int i = 0; i < arrIdx; i++) {
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

    userStartsRiding(waterKingdomUserRideChoises, arrIdx);
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
