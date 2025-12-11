#include <stdio.h>
#include <stdlib.h>

// calendar.c
void printDecember2025Calendar();
int chooseDate2025();

// offers.c
void showOffer2025(int date);

// fantasy & water kingdom
void fantasyKingdomWelcoming();
void waterKingdomWelcoming();

// entryexit.c
void initEntryExitSystem();
void enterAsLocal();   // General Pass
void enterAsVIP();     // VIP Pass
void entryExitSystem();

int main() {

    initEntryExitSystem();

    int passType;

    printf("======================================\n");
    printf("       WONDERLAND AMUSEMENT PARK\n");
    printf("======================================\n");
    printf("Select Admission Type:\n");
    printf("1) General Pass\n");
    printf("2) VIP Pass\n");
    printf("3) Exit\n");
    printf("> ");

    scanf("%d", &passType);

    if (passType == 1) {
        enterAsLocal();     // <-- Name asked here ONLY ONCE
    }
    else if (passType == 2) {
        enterAsVIP();       // <-- Name asked here ONLY ONCE
    }
    else {
        printf("Exiting.\n");
        return 0;
    }

    // ===== CALENDAR =====
    printDecember2025Calendar();
    int selectedDate = chooseDate2025();
    printf("Selected date: December %d, 2025\n", selectedDate);

    // ===== OFFERS =====
    showOffer2025(selectedDate);

    // ===== USER INFO (NO NAME HERE ANYMORE!) =====
    int age;
    float height;

    printf("Enter your Age: ");
    scanf("%d", &age);

    printf("Enter your Height (ft): ");
    scanf("%f", &height);

    // ===== PARK SELECTION =====
    printf("\nChoose Your Park:\n");
    printf("1) Fantasy Kingdom\n");
    printf("2) Water Kingdom\n");
    printf("> ");

    int park;
    scanf("%d", &park);

    if (park == 1) {
        fantasyKingdomWelcoming();
    } else if (park == 2) {
        waterKingdomWelcoming();
    } else {
        printf("Invalid option.\n");
    }

    return 0;
}
