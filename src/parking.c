#include <stdio.h>
#include <stdlib.h>


struct Car {
    int carNumber;
    struct Car* next;
};

struct Car* front = NULL;
struct Car* rear = NULL;


void parkCar() {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));

    if (newCar == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter car number: ");
    scanf("%d", &newCar->carNumber);

    newCar->next = NULL;

    if (rear == NULL) {
        front = rear = newCar;
    } else {
        rear->next = newCar;
        rear = newCar;
    }

    printf("Car %d parked successfully.\n", newCar->carNumber);
}


void removeCar() {
    if (front == NULL) {
        printf("Parking is empty. No car to remove.\n");
        return;
    }

    struct Car* temp = front;
    printf("Car %d left the parking.\n", temp->carNumber);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}


void showParking() {
    if (front == NULL) {
        printf("Parking is empty.\n");
        return;
    }

    struct Car* temp = front;
    printf("\nCars currently parked (Front -> Rear):\n");

    while (temp != NULL) {
        printf("Car %d\n", temp->carNumber);
        temp = temp->next;
    }
}

void carParking() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf("      AMUSEMENT PARK PARKING\n");
        printf("==============================\n");
        printf("1. Park Car\n");
        printf("2. Remove Car\n");
        printf("3. Show Parked Cars\n");
        printf("4. Exit Parking\n");
        printf("> ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                parkCar();
                break;

            case 2:
                removeCar();
                break;

            case 3:
                showParking();
                break;

            case 4:
                printf("Exiting Car Parking System...\n");
                return;

            default:
                printf("Invalid option!\n");
        }
    }
}
