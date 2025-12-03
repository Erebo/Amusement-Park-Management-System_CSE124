#include <stdio.h>

// Display Welcome Screen + Calendar
void printDecember2025Calendar() {

    printf("\n===========================================\n");
    printf("        WELCOME TO FANTASY KINGDOM\n");
    printf("===========================================\n");
    printf("  Please select your suitable date below:\n");
    printf("===========================================\n\n");

    printf("                December 2025\n");
    printf("-------------------------------------------\n");
    printf("Su  Mo  Tu  We  Th  Fr  Sa\n");

    int startDay = 1;  // Monday
    int day;

    // Print spaces before day 1
    for (int i = 0; i < startDay; i++)
        printf("    ");

    // Print all 31 days of December 2025
    for (day = 1; day <= 31; day++) {
        printf("%2d  ", day);

        // New line after Saturday
        if ((day + startDay) % 7 == 0)
            printf("\n");
    }

    printf("\n-------------------------------------------\n");
}

// Ask user for a valid date
int chooseDate2025() {
    int date;

    while (1) {
        printf("Select a date (1-31): ");
        if (scanf("%d", &date) != 1) {
            while (getchar() != '\n'); // clear buffer
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        if (date >= 1 && date <= 31)
            return date;

        printf("Invalid date! Please choose between 1 and 31.\n");
    }
}
