#include <stdio.h>

void printDecember2025Calendar();
int chooseDate2025();
void showOffer2025(int date);
void fantasyKingdomWelcoming();
void waterKingdomWelcoming();

int main() {
    printDecember2025Calendar();

    int selectedDate = chooseDate2025();

    printf("\nYou selected: December %d, 2025\n", selectedDate);

    // Show the offer for that day
    showOffer2025(selectedDate);

    printf("Where you want to go: \n");
    printf("1) Fantasy Kingdom\n");
    printf("2) Water kingdom\n");
    printf("> ");
    int parkSelection;
    scanf("%d", &parkSelection);

    switch (parkSelection)
    {
    case 1:
        fantasyKingdomWelcoming();
    case 2:
        waterKingdomWelcoming();
    default:
        break;
    }

    return 0;
}
