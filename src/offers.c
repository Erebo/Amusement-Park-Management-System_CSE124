#include <stdio.h>
#include <string.h>

int offerChoice = 0;

char* getDayName(int date) {
    int dayIndex = (date % 7);

    switch (dayIndex) {
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        case 0:
            return "Sunday";
        default:
            return "Unknown";
    }
}

void showRegularOffer(int date) {
    printf("------------------------------------------------------------\n");
    printf("  OFFER FOR DECEMBER %d, 2025 (REGULAR)\n", date);
    printf("------------------------------------------------------------\n");
    printf("1) Fantasy Kingdom : 12 rides + Entry = 1000 tk\n");
    printf("2) Water Kingdom   : Unlimited rides + Entry = 1000 tk\n");
    printf("3) Combo Offer     : Fantasy + Water + Entry = 1500 tk\n");
    printf("------------------------------------------------------------\n");
}

void showFamilyDayOffer(int date) {
    printf("------------------------------------------------------------\n");
    printf("  FAMILY DAY OFFER - DECEMBER %d, 2025 (TUESDAY)\n", date);
    printf("------------------------------------------------------------\n");
    printf("1) Fantasy Kingdom : 12 rides + Entry = 500 tk\n");
    printf("2) Water Kingdom   : Unlimited rides = 600 tk\n");
    printf("------------------------------------------------------------\n");
}

void showHolidayOffer(int date) {
    printf("------------------------------------------------------------\n");
    printf("  HOLIDAY OFFER - DECEMBER %d, 2025 (FRIDAY/SATURDAY)\n", date);
    printf("------------------------------------------------------------\n");
    printf("1) Only Entry\n");
    printf("2) Fantasy Kingdom\n");
    printf("3) Water Kingdom\n");
    printf("------------------------------------------------------------\n");
}

void takeOfferChoice(int maxOption) {
    int choice;
    do {
        printf("Choose an offer: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > maxOption);

    if (maxOption == 2) {
        offerChoice = choice;
    } else {
        offerChoice = choice;
    }
}

void showOffer2025(int date) {
    char* day = getDayName(date);

    printf("============================================================\n");
    printf("                OFFERS FOR DECEMBER %d, 2025\n", date);
    printf("============================================================\n");
    printf(" Day: %s\n\n", day);

    if (strcmp(day, "Tuesday") == 0) {
        showFamilyDayOffer(date);
        takeOfferChoice(2);
    } else if (strcmp(day, "Friday") == 0 || strcmp(day, "Saturday") == 0) {
        showHolidayOffer(date);
        takeOfferChoice(3);
    } else {
        showRegularOffer(date);
        takeOfferChoice(3);
    }
}
