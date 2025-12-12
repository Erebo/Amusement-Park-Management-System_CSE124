#include <stdio.h>
#include <stdlib.h>

// calendar.c
void printDecember2025Calendar();
int chooseDate2025();

// offers.c
void showOffer2025(int date);

// fantasy & water kingdom
void fantasyKingdomWelcoming();
void waterKingdomWelcoming(int age, float height);

// entryexit.c
void initEntryExitSystem();
void enterAsLocal();  // General Pass
void enterAsVIP();    // VIP Pass
void entryExitSystem();

int main() {
    initEntryExitSystem();  // prepare stack + queue for entry/exit

    int passType;

    printf("============================================================\n");
    printf("                WONDERLAND AMUSEMENT PARK\n");
    printf("============================================================\n");
    printf("Select Admission Type:\n");
    printf("1) General Pass\n");
    printf("2) VIP Pass\n");
    printf("3) Exit\n");
    printf("> ");

    scanf("%d", &passType);

    if (passType == 1) {
        enterAsLocal();  // name asked inside entryexit.c
    } else if (passType == 2) {
        enterAsVIP();  // name asked inside entryexit.c
    } else {
        printf("Exiting.\n");
        return 0;
    }

    // =====================
    //  CALENDAR SELECTION
    // =====================
    printDecember2025Calendar();

    int selectedDate = chooseDate2025();
    printf("\nSelected date: December %d, 2025\n", selectedDate);

    // =====================
    //  OFFERS BASED ON DAY
    // =====================
    showOffer2025(selectedDate);

    // =====================
    //  USER PROFILE INPUT
    // =====================
    int age;
    float height;

    printf("\nEnter your Age: ");
    scanf("%d", &age);

    printf("Enter your Height (ft): ");
    scanf("%f", &height);

    // =====================
    //  PARK SELECTION MENU (FIRST TIME)
    // =====================
startParkChoice:

    printf("\n================ PARK SELECTION ================\n");
    printf("1) Fantasy Kingdom\n");
    printf("2) Water Kingdom\n");
    printf("3) Entry/Exit System\n");
    printf("4) Exit Program\n");
    printf("=================================================\n");
    printf("> ");

    int park;
    scanf("%d", &park);

    if (park == 1) {
        fantasyKingdomWelcoming();
    } else if (park == 2) {
        waterKingdomWelcoming(age, height);
    } else if (park == 3) {
        entryExitSystem();
    } else if (park == 4) {
        printf("Goodbye!\n");
        return 0;
    } else {
        printf("Invalid option.\n");
        goto startParkChoice;
    }

    // =====================
    //  POST-PARK MENU LOOP
    // =====================

postParkMenu:

    printf("\n==================================================================\n");
    printf("                WHAT DO YOU WANT TO DO NEXT?\n");
    printf("==================================================================\n");
    printf("1) Go to Fantasy Kingdom\n");
    printf("2) Go to Water Kingdom\n");
    printf("3) Entry/Exit System\n");
    printf("4) View Calendar\n");
    printf("5) View Offers\n");
    printf("6) Exit Program\n");
    printf("==================================================================\n");
    printf("> ");

    int nextAction;
    scanf("%d", &nextAction);

    if (nextAction == 1) {
        fantasyKingdomWelcoming();
        goto postParkMenu;
    } else if (nextAction == 2) {
        waterKingdomWelcoming(age, height);
        goto postParkMenu;
    } else if (nextAction == 3) {
        entryExitSystem();
        goto postParkMenu;
    } else if (nextAction == 4) {
        printDecember2025Calendar();
        goto postParkMenu;
    } else if (nextAction == 5) {
        showOffer2025(selectedDate);
        goto postParkMenu;
    } else if (nextAction == 6) {
        printf("Goodbye!\n");
        return 0;
    } else {
        printf("Invalid option.\n");
        goto postParkMenu;
    }

    return 0;
}
