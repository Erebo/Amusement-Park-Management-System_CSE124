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

// entryexit.c  (UPDATED FUNCTION SIGNATURES)
void initEntryExitSystem();
void enterAsLocal(char name[], int age, float height, int childOnly, int childRidePermission);
void enterAsVIP(char name[], int age, float height, int childOnly, int childRidePermission);
void entryExitSystem();

// GLOBAL (declared in entryexit.c)
extern char visitorNameGlobal[];
extern int visitorAge;
extern float visitorHeight;
extern int childOnly;
extern int childRidePermission;

int main() {

    initEntryExitSystem();  // prepare queue + stack

    printf("============================================================\n");
    printf("                WONDERLAND AMUSEMENT PARK\n");
    printf("============================================================\n");

    // ====================================================
    // 1️⃣ CALENDAR FIRST
    // ====================================================
    printDecember2025Calendar();

    int selectedDate = chooseDate2025();
    printf("\nSelected date: December %d, 2025\n", selectedDate);

    // ====================================================
    // 2️⃣ OFFER SECOND
    // ====================================================
    showOffer2025(selectedDate);

    // ====================================================
    // 3️⃣ USER INFO (NAME, AGE, HEIGHT)
    // ====================================================
    char name[100];
    int age;
    float height;

    printf("\nEnter your Name: ");
    scanf(" %[^\n]", name);

    printf("Enter your Age: ");
    scanf("%d", &age);

    printf("Enter your Height (ft): ");
    scanf("%f", &height);

    visitorAge = age;
    visitorHeight = height;

    // ====================================================
    // 4️⃣ AGE RULE SYSTEM (CHILD / PARENT)
    // ====================================================
    if (age < 10) {
        childOnly = 1;
        childRidePermission = 1;
        printf("\nThis visitor is under 10. Children rides ONLY.\n");
    } else {
        childOnly = 0;
        printf("\nAre you buying child ride tickets for your children? (1=Yes, 0=No): ");
        scanf("%d", &childRidePermission);

        if (childRidePermission == 1)
            printf("Child rides permitted.\n");
        else
            printf("Child rides NOT permitted.\n");
    }

    // ====================================================
    // 5️⃣ ADMISSION TYPE
    // ====================================================
    int passType;

    printf("\nSelect Admission Type:\n");
    printf("1) General Pass\n");
    printf("2) VIP Pass\n");
    printf("3) Exit\n");
    printf("> ");
    scanf("%d", &passType);

    if (passType == 1) {
        enterAsLocal(name, age, height, childOnly, childRidePermission);
    }
    else if (passType == 2) {
        enterAsVIP(name, age, height, childOnly, childRidePermission);
    }
    else {
        printf("Exiting program.\n");
        return 0;
    }

    // ====================================================
    // 6️⃣ FIRST PARK SELECTION
    // ====================================================
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

    if (park == 1) fantasyKingdomWelcoming();
    else if (park == 2) waterKingdomWelcoming();
    else if (park == 3) entryExitSystem();
    else if (park == 4) {
        printf("Goodbye!\n");
        return 0;
    }
    else {
        printf("Invalid option.\n");
        goto startParkChoice;
    }

    // ====================================================
    // 7️⃣ POST-PARK MENU LOOP
    // ====================================================
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
    }
    else if (nextAction == 2) {
        waterKingdomWelcoming();
        goto postParkMenu;
    }
    else if (nextAction == 3) {
        entryExitSystem();
        goto postParkMenu;
    }
    else if (nextAction == 4) {
        printDecember2025Calendar();
        goto postParkMenu;
    }
    else if (nextAction == 5) {
        showOffer2025(selectedDate);
        goto postParkMenu;
    }
    else if (nextAction == 6) {
        printf("Goodbye!\n");
        return 0;
    }
    else {
        printf("Invalid option.\n");
        goto postParkMenu;
    }

    return 0;
}
