#include <stdio.h>
#include <stdlib.h>

void printDecember2025Calendar();
int chooseDate2025();

void showOffer2025(int date);

void fantasyKingdomWelcoming();
void waterKingdomWelcoming(int age, float height);

void initEntryExitSystem();
void enterAsLocal(char name[], int age, float height);
void enterAsVIP(char name[], int age, float height);
void entryExitSystem();
void restaurant();
void carParking();

extern char visitorNameGlobal[];
extern int visitorAge;
extern float visitorHeight;
extern int childOnly;
extern int childRidePermission;

int main() {
    initEntryExitSystem();

    int passType;

    printf("============================================================\n");
    printf("                FNTASY KINGDOM AMUSEMENT PARK\n");
    printf("============================================================\n");
    printf("Select Admission Type:\n");
    printf("1) General Pass\n");
    printf("2) VIP Pass\n");
    printf("3) Exit\n");
    printf("> ");

    scanf("%d", &passType);

    if (passType == 3) {
        printf("Goodbye!\n");
        return 0;
    }

    int age;
    float height;
    char name[50];

    printf("Enter your name: ");
    scanf(" %[^\n]", name);

    printf("Enter your Age: ");
    scanf("%d", &age);

    printf("Enter your Height (ft): ");
    scanf("%f", &height);

    if (passType == 1) {
        enterAsLocal(name, age, height);
    } else if (passType == 2) {
        enterAsVIP(name, age, height);
    } else if (passType == 3) {
        return 0;
    }

    printDecember2025Calendar();

    int selectedDate = chooseDate2025();
    printf("\nSelected date: December %d, 2025\n", selectedDate);

    showOffer2025(selectedDate);
    int choice;
    printf("Choose an offer: ");
    scanf("%d", &choice);
    startParkChoice:
        if (choice == 1) {
            printf("\n================ PARK SELECTION ================\n");
            printf("1) Fantasy Kingdom\n");
            printf("2) Entry/Exit System\n");
            printf("3) Exit Program\n");
            printf("=================================================\n");
            printf("> ");
        
            int park;
            scanf("%d", &park);
        
            if (park == 1) {
                fantasyKingdomWelcoming();
            } else if (park == 2) {
                entryExitSystem();
            } else if (park == 3) {
                printf("Goodbye!\n");
                return 0;
            }
        } else if (choice == 2)
        {
            printf("\n================ PARK SELECTION ================\n");
            printf("1) Water Kingdom\n");
            printf("2) Entry/Exit System\n");
            printf("3) Exit Program\n");
            printf("=================================================\n");
            printf("> ");
        
            int park;
            scanf("%d", &park);
        
            if (park == 1) {
                waterKingdomWelcoming(age, height);
            } else if (park == 2) {
                entryExitSystem();
            } else if (park == 3) {
                printf("Goodbye!\n");
                return 0;
            }
        } else {
            printf("Invalid option.\n");
            goto startParkChoice;
        }

postParkMenu:

    printf("\n==================================================================\n");
    printf("                WHAT DO YOU WANT TO DO NEXT?\n");
    printf("==================================================================\n");
    printf("1) Choose a park\n");
    printf("2) Entry/Exit System\n");
    printf("3) View Calendar\n");
    printf("4) View Offers\n");
    printf("5) Go to restaurant\n");
    printf("6) Park your vehicle\n");
    printf("7) Exist program\n");
    printf("==================================================================\n");
    printf("> ");

    int nextAction;
    scanf("%d", &nextAction);

    if (nextAction == 1) {
        printf("1) Fantasy Kingdom\n");
        printf("1) Water Kingdom\n");
        printf("> ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            fantasyKingdomWelcoming();
        } else if (choice == 2) {
            waterKingdomWelcoming(age, height);
        }

        goto postParkMenu;
    } else if (nextAction == 2) {
        entryExitSystem();
        goto postParkMenu;
    } else if (nextAction == 3) {
        printDecember2025Calendar();
        goto postParkMenu;
    } else if (nextAction == 4) {
        showOffer2025(selectedDate);
        goto postParkMenu;
    } else if (nextAction == 5) {
        restaurant();
        goto postParkMenu;
    } else if (nextAction == 6) {
        carParking();
        goto postParkMenu;
    } else if (nextAction == 7) {
        printf("Goodbye!\n");
        return 0;
    } else {
        printf("Invalid option.\n");
        goto postParkMenu;
    }

    return 0;
}
