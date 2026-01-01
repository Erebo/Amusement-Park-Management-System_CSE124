#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_VISITORS 100

//------------------------------------------------------
// GLOBAL VISITOR PROFILE (Shared Across Modules)
//------------------------------------------------------
char visitorNameGlobal[MAX_NAME];
int visitorAge = 0;
float visitorHeight = 0.0;
int childRidePermission = 0;   // 1 = adult can buy child tickets
int childOnly = 0;             // 1 = visitor is under age 10

//------------------------------------------------------
// QUEUE + STACK STRUCTURES
//------------------------------------------------------
typedef struct {
    char names[MAX_VISITORS][MAX_NAME];
    int front, rear;
} Queue;

typedef struct {
    char names[MAX_VISITORS][MAX_NAME];
    int top;
} Stack;

//------------------------------------------------------
// GLOBAL QUEUE & STACK INSTANCES
//------------------------------------------------------
Queue localQueue;
Stack vipStack;

//------------------------------------------------------
// QUEUE FUNCTIONS
//------------------------------------------------------
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isQueueFull(Queue *q) { 
    return q->rear == MAX_VISITORS - 1; 
}

int isQueueEmpty(Queue *q) { 
    return q->front == -1; 
}

void enqueue(Queue *q, const char *name) {
    if (isQueueFull(q)) {
        printf("Local Queue is full!\n");
        return;
    }

    if (isQueueEmpty(q))
        q->front = 0;

    q->rear++;
    strcpy(q->names[q->rear], name);
}

char* dequeue(Queue *q) {
    if (isQueueEmpty(q)) 
        return NULL;

    char *name = q->names[q->front];

    if (q->front == q->rear)
        initQueue(q);
    else
        q->front++;

    return name;
}

//------------------------------------------------------
// STACK FUNCTIONS
//------------------------------------------------------
void initStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) { 
    return s->top == MAX_VISITORS - 1; 
}

int isStackEmpty(Stack *s) { 
    return s->top == -1; 
}

void push(Stack *s, const char *name) {
    if (isStackFull(s)) {
        printf("VIP Stack is full!\n");
        return;
    }
    s->top++;
    strcpy(s->names[s->top], name);
}

char* pop(Stack *s) {
    if (isStackEmpty(s)) 
        return NULL;

    return s->names[s->top--];
}

void enterAsLocal(char name[], int age, float height){
    strcpy(visitorNameGlobal, name);
    visitorAge = age;
    visitorHeight = height;

    enqueue(&localQueue, name);

    printf("%s added to Local Queue (ENTRY Gate)\n", name);
}

void enterAsVIP(char name[], int age, float height)
{
    strcpy(visitorNameGlobal, name);
    visitorAge = age;
    visitorHeight = height;

    push(&vipStack, name);

    printf("✔ %s added to VIP Stack (EXIT Gate Entry)\n\n", name);
}

void processLocalEntry() {
    char *name = dequeue(&localQueue);

    if (!name) {
        printf("No local visitors waiting.\n");
        return;
    }
    printf("➡ Local Visitor Entered: %s\n", name);
}

void processVIPEntry() {
    char *name = pop(&vipStack);

    if (!name) {
        printf("No VIP visitors waiting.\n");
        return;
    }
    printf("➡ VIP Visitor Entered: %s\n", name);
}

void entryExitSystem() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf(" AMUSEMENT PARK ENTRY SYSTEM\n");
        printf("==============================\n");
        printf("1. Process Next Local Entry\n");
        printf("2. Process Next VIP Entry\n");
        printf("3. Exit This Module\n");
        printf("> ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: processLocalEntry(); break;
            case 2: processVIPEntry(); break;
            case 3: return;
            default: printf("Invalid option!\n");
        }
    }
}

void initEntryExitSystem() {
    initQueue(&localQueue);
    initStack(&vipStack);
}
