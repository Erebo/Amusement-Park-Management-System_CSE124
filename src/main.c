#include <stdio.h>

void printDecember2025Calendar();
int chooseDate2025();
void showOffer2025(int date);
void fantasyKingdomWelcoming();
void waterKingdomWelcoming();

int main() {
    printDecember2025Calendar();

    int selectedDate = chooseDate2025();

    printf("\nYOU SELECTED: DECEMBER %d, 2025\n", selectedDate);

    showOffer2025(selectedDate);

    char userName[100];
    int userAge;
    float userHeight, userWeight;

    printf("ENTER YOUR NAME: ");
    scanf(" %[^\n]", userName);  // ✔ FIXED (NO &userName)

    printf("ENTER YOUR AGE: ");
    scanf("%d", &userAge);

    printf("ENTER YOUR HEIGHT (IN FT.): ");
    scanf("%f", &userHeight);

    printf("ENTER YOUR WEIGHT (IN KG): ");
    scanf("%f", &userWeight);

    FILE *userDataForWriting, *userDataForReading;

    int lastSerial = 0;

    userDataForReading = fopen("userData.txt", "r");

    if (userDataForReading != NULL) {
        char line[1000];

        while (fgets(line, sizeof(line), userDataForReading)) {
            int serial;
            if (sscanf(line, "serial: %d", &serial) == 1) {
                lastSerial = serial;
            }
        }

        fclose(userDataForReading);
    }

    int newSerial = lastSerial + 1;

    userDataForWriting = fopen("userData.txt", "a");
    fprintf(userDataForWriting, "serial: %d ", newSerial);
    fprintf(userDataForWriting, "name: %s ", userName);
    fprintf(userDataForWriting, "age: %d ", userAge);
    fprintf(userDataForWriting, "height: %.2f ", userHeight);
    fprintf(userDataForWriting, "weight: %.2f\n", userWeight);
    fclose(userDataForWriting);

    userDataForReading = fopen("userData.txt", "r");
    char data[1000];
    fscanf(userDataForReading, "%[^\n]", data);
    printf("%s\n", data);
    fclose(userDataForReading);

    printf("\nWELCOME %s, WHERE DO YOU WANT TO GO?\n", userName);
    printf("1) FANTASY KINGDOM\n");
    printf("2) WATER KINGDOM\n");

    int parkSelection;

chooseOptionAgain:
    printf("> ");
    scanf("%d", &parkSelection);

    switch (parkSelection) {
        case 1:
            fantasyKingdomWelcoming();
            break;

        case 2:
            waterKingdomWelcoming();
            break;

        default:
            printf("INVALID OPTION! TRY AGAIN.\n");
            goto chooseOptionAgain;
    }

    return 0;
}
