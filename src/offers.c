#include <stdio.h>
#include <string.h>

char* getDayName(int date) {
    // December 1, 2025 = Monday
    int dayIndex = (date % 7);

    switch (dayIndex) {
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        case 0: return "Sunday";
        default: return "Unknown";
    }
}

void showRegularOffer(int date) {
    printf("------------------------------------------------------------\n");
    printf("  OFFER FOR DECEMBER %d, 2025 (REGULAR)\n", date);
    printf("------------------------------------------------------------\n");
    printf(" - Fantasy Kingdom : 12 rides + Entry = 1000 tk\n");
    printf(" - Water Kingdom   : Unlimited rides + Entry = 1000 tk\n");
    printf(" - Combo Offer     : Fantasy + Water + Entry = 1500 tk\n");
    printf("------------------------------------------------------------\n");
}

void showFamilyDayOffer(int date) {
    printf("------------------------------------------------------------\n");
    printf("  FAMILY DAY OFFER - DECEMBER %d, 2025 (TUESDAY)\n", date);
    printf("------------------------------------------------------------\n");
    printf(" - Fantasy Kingdom : 12 rides + Entry = 500 tk\n");
    printf(" - Water Kingdom   : Unlimited rides = 600 tk\n");
    printf("------------------------------------------------------------\n");
}

void showHolidayOffer(int date) {
    printf("------------------------------------------------------------\n");
    printf("  HOLIDAY OFFER - DECEMBER %d, 2025 (FRIDAY/SATURDAY)\n", date);
    printf("------------------------------------------------------------\n");
    printf(" - Only Entry             = 500 tk\n");
    printf(" - Fantasy Kingdom        = 12 rides + Entry = 1000 tk\n");
    printf(" - Water Kingdom          = Unlimited rides + Entry = 1000 tk\n");
    printf("------------------------------------------------------------\n");
}

void showOffer2025(int date) {
    char* day = getDayName(date);

    printf("============================================================\n");
    printf("                OFFERS FOR DECEMBER %d, 2025\n", date);
    printf("============================================================\n");
    printf(" Day: %s\n\n", day);

    if (strcmp(day, "Tuesday") == 0) {
        showFamilyDayOffer(date);
    }
    else if (strcmp(day, "Friday") == 0 || strcmp(day, "Saturday") == 0) {
        showHolidayOffer(date);
    }
    else {
        showRegularOffer(date);
    }
}
