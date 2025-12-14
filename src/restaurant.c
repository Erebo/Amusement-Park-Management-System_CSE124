#include <stdio.h>
#include <string.h>

#define MAX 5

struct OrderStack {
    char orders[MAX][30];  
    int top;
};

struct OrderStack stack;

void initializeStack() {
    stack.top = -1;
}

void placeOrder() {
    if (stack.top == MAX - 1) {
        printf("\nRestaurant is full! Cannot take more orders.\n");
        return;
    }

    stack.top++;
    printf("Enter food name: ");
    scanf(" %[^\n]", stack.orders[stack.top]);

    printf("Order added: %s\n", stack.orders[stack.top]);
}

void serveOrder() {
    if (stack.top == -1) {
        printf("\nNo orders to serve.\n");
        return;
    }

    printf("Serving order: %s\n", stack.orders[stack.top]);
    stack.top--;
}

void showOrders() {
    if (stack.top == -1) {
        printf("\nNo current orders.\n");
        return;
    }

    printf("\nCurrent Orders (Top to Bottom):\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("- %s\n", stack.orders[i]);
    }
}

void restaurant() {
    int choice;
    initializeStack();

    while (1) {
        printf("\n==============================\n");
        printf("     AMUSEMENT PARK RESTAURANT\n");
        printf("==============================\n");
        printf("1. Place Order\n");
        printf("2. Serve Order\n");
        printf("3. Show Orders\n");
        printf("4. Exit Restaurant\n");
        printf("> ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                placeOrder();
                break;

            case 2:
                serveOrder();
                break;

            case 3:
                showOrders();
                break;

            case 4:
                printf("\nExiting Restaurant...\n");
                return;

            default:
                printf("\nInvalid option!\n");
        }
    }
}
