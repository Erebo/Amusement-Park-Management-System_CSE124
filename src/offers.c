#include <stdio.h>

// Determine weekday for December 2025
// Return: 0=Sun, 1=Mon, 2=Tue, 3=Wed, 4=Thu, 5=Fri, 6=Sat
int getWeekday2025(int date) {
    int startDay = 1;  // December 1, 2025 = Monday
    return (startDay + (date - 1)) % 7;
}

// Show offer for the selected date
void showOffer2025(int date) {
    int weekday = getWeekday2025(date);

    printf("\n=====================================\n");
    printf("     OFFERS FOR DECEMBER %d, 2025\n", date);
    printf("=====================================\n");

    switch (weekday) {
        case 0:
            printf("Sunday Offer: REGULAR OFFER AVAILABLE\n");
            break;
        case 1:
            printf("Monday Offer: REGULAR OFFER AVAILABLE\n");
            break;
        case 2:
            printf("Tuesday Offer: FAMILY OFFER AVAILABLE\n");
            break;
        case 3:
            printf("Wednesday Offer: REGULAR OFFER AVAILABLE\n");
            break;
        case 4:
            printf("Thursday Offer: REGULAR OFFER AVAILABLE\n");
            break;
        case 5:
            printf("Friday Offer: HOLIDAY OFFER AVAILABLE\n");
            break;
        case 6:
            printf("Saturday Offer: HOLIDAY OFFER AVAILABLE\n");
            break;
        default:
            printf("Error: Invalid Weekday!\n");
    }

    printf("=====================================\n");
}
