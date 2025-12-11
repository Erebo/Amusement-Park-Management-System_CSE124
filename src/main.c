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

    showOffer2025(selectedDate);

    char userName[100];
    int userAge;
    float userHeight, userWeight;
    printf("Enter you name: ");
    scanf(" %[^\n]", &userName);
    printf("Enter your age: ");
    scanf("%d", &userAge);
    printf("Enter your height (in ft.): ");
    scanf("%f", &userHeight);
    printf("Enter your weight(in kg): ");
    scanf("%f", &userWeight);

    FILE *userDataForWriting, *userDataForReading;

    int lastSerial = 0; 

    userDataForReading = fopen("userData.txt", "r");

    if (userDataForReading != NULL)
    {
        char line[1000];

        while (fgets(line, sizeof(line), userDataForReading))
        {
            int serial;
            if (sscanf(line, "serial: %d", &serial) == 1)
            {
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

    printf("Welcome %s, Where you want to go: \n", userName);
    printf("1) Fantasy Kingdom\n");
    printf("2) Water kingdom\n");
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
        printf("Invalid option\n");
        goto chooseOptionAgain;
    }

    return 0;
}
