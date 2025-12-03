#include <stdio.h>

void printDecember2025Calendar();
int chooseDate2025();
void showOffer2025(int date);   // <-- ADD THIS LINE

int main() {
    printDecember2025Calendar();

    int selectedDate = chooseDate2025();

    printf("\nYou selected: December %d, 2025\n", selectedDate);

    // Show the offer for that day
    showOffer2025(selectedDate);

    return 0;
}
