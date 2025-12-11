#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_VISITORS 100

//------------------------------------------------------
// Queue (For Local Visitors)
//------------------------------------------------------
typedef struct {
    char names[MAX_VISITORS][MAX_NAME];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX_VISITORS - 1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, char *name) {
    if (isQueueFull(q)) {
        printf("Local Queue is full! Cannot add more visitors.\n");
        return;
    }

    if (isQueueEmpty(q))
        q->front = 0;

    q->rear++;
    strcpy(q->names[q->rear], name);
}

char* dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }

    char *name = q->names[q->front];

    if (q->front == q->rear) {
        initQueue(q);
    } else {
        q->front++;
    }

    return name;
}

//------------------------------------------------------
// Stack (For VIP Visitors)
//------------------------------------------------------
typedef struct {
    char names[MAX_VISITORS][MAX_NAME];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX_VISITORS - 1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *name) {
    if (isStackFull(s)) {
        printf("VIP Stack is full! Cannot add more visitors.\n");
        return;
    }
    s->top++;
    strcpy(s->names[s->top], name);
}

char* pop(Stack *s) {
    if (isStackEmpty(s)) {
        return NULL;
    }
    return s->names[s->top--];
}

//------------------------------------------------------
// ENTRYEXIT SYSTEM FUNCTIONS
//------------------------------------------------------

Queue localQueue;
Stack vipStack;

void enterAsLocal() {
    char name[MAX_NAME];
    printf("Enter Local Visitor Name: ");
    scanf(" %[^\n]", name);

    enqueue(&localQueue, name);
    printf("✔ %s added to Local Queue (ENTRY Gate)\n", name);
}

void enterAsVIP() {
    char name[MAX_NAME];
    printf("Enter VIP Visitor Name: ");
    scanf(" %[^\n]", name);

    push(&vipStack, name);
    printf("%s added to VIP Stack (EXIT Gate Entry)\n", name);
}

void processLocalEntry() {
    char *name = dequeue(&localQueue);

    if (name == NULL) {
        printf("No local visitors waiting.\n");
        return;
    }
    printf("➡ Local Visitor Entered: %s (ENTRY gate)\n", name);
}

void processVIPEntry() {
    char *name = pop(&vipStack);

    if (name == NULL) {
        printf("No VIP visitors waiting.\n");
        return;
    }
    printf("➡ VIP Visitor Entered: %s (EXIT gate)\n", name);
}

//------------------------------------------------------
// Main Interface for this module
//------------------------------------------------------
void entryExitSystem() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf(" AMUSEMENT PARK ENTRY SYSTEM\n");
        printf("==============================\n");
        printf("1. Local Visitor (Entry Gate)\n");
        printf("2. VIP Visitor (Exit Gate)\n");
        printf("3. Process Next Local Entry\n");
        printf("4. Process Next VIP Entry\n");
        printf("5. Exit This Module\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enterAsLocal(); break;
            case 2: enterAsVIP(); break;
            case 3: processLocalEntry(); break;
            case 4: processVIPEntry(); break;
            case 5: return;
            default: printf("Invalid option!\n");
        }
    }
}

//------------------------------------------------------
// INITIALIZER (Call this once in main())
//------------------------------------------------------
void initEntryExitSystem() {
    initQueue(&localQueue);
    initStack(&vipStack);
}
