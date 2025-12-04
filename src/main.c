#include <stdio.h>

void printDecember2025Calendar();
int chooseDate2025();
void showOffer2025(int date);   // <-- ADD THIS LINE

int main() {

    
    printf(" __        __   _                            \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  \n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ \n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ \n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \n");
    printf("                                             \n");

    printf("  _____    \n");
    printf(" |_   _|__  \n");
    printf("   | |/ _ \\ \n");
    printf("   | | (_) |\n");
    printf("   |_|\\___/ \n");
    printf("            \n");
    printf("  _____          _                    _  __  _                         \n");
    printf(" |  ___|_ _ _ __ | |_ __ _ ___ _   _  | |/ / (_)_ __   __ _  __| | ___  _ __ ___  \n");
    printf(" | |_ / _` | '_ \\| __/ _` / __| | | | | ' /  | | '_ \\ / _` |/ _` |/ _ \\| '_ ` _ \\ \n");
    printf(" |  _| (_| | | | | || (_| \\__ \\ |_| | | . \\  | | | | | (_| | (_| | (_) | | | | | |\n");
    printf(" |_|  \\__,_|_| |_|\\__\\__,_|___/\\__, | |_|\\_\\ |_|_| |_|\\__, |\\__,_|\\___/|_| |_| |_|\n");
    printf("                               |___/                   |___/                       \n");
    printDecember2025Calendar();

    int selectedDate = chooseDate2025();

    printf("\nYou selected: December %d, 2025\n", selectedDate);

    // Show the offer for that day
    showOffer2025(selectedDate);

    return 0;
}
