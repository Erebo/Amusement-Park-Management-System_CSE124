#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_RIDE_NAME 64
#define MAX_HISTORY 100
#define CHILD_RIDE_FARE 40

/* ============================================================
   DATA STRUCTURES
   Queue (linked list), Stack, Ride, Category Tree
   ============================================================ */

typedef struct QueueNode {
    char visitorName[MAX_NAME_LEN];
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *head;
    QueueNode *tail;
    int length;
} Queue;

typedef struct {
    char items[MAX_HISTORY][MAX_RIDE_NAME];
    int top;
} RideStack;

typedef struct {
    char name[MAX_RIDE_NAME];
    int durationMinutes;
    Queue queue;
} Ride;

typedef struct Category {
    char name[40];
    Ride *rides;
    int rideCount;
    struct Category *left;
    struct Category *right;
} Category;

/* ============================================================
   FIXED — Fantasy Kingdom Queue/Stack functions (NO conflicts)
   ============================================================ */

void FK_initQueue(Queue *q) {
    q->head = q->tail = NULL;
    q->length = 0;
}

void FK_enqueue(Queue *q, const char *name) {
    QueueNode *node = malloc(sizeof(QueueNode));
    if (!node) return;

    strncpy(node->visitorName, name, MAX_NAME_LEN - 1);
    node->visitorName[MAX_NAME_LEN - 1] = '\0';
    node->next = NULL;

    if (!q->tail) q->head = q->tail = node;
    else {
        q->tail->next = node;
        q->tail = node;
    }

    q->length++;
}

int FK_dequeue(Queue *q, char *outName) {
    if (!q->head) return 0;

    QueueNode *temp = q->head;
    strncpy(outName, temp->visitorName, MAX_NAME_LEN);
    q->head = q->head->next;
    if (!q->head) q->tail = NULL;

    free(temp);
    q->length--;
    return 1;
}

void FK_initStack(RideStack *s) {
    s->top = -1;
}

void FK_push(RideStack *s, const char *rideName) {
    if (s->top < MAX_HISTORY - 1) {
        s->top++;
        strncpy(s->items[s->top], rideName, MAX_RIDE_NAME - 1);
        s->items[s->top][MAX_RIDE_NAME - 1] = '\0';
    }
}

void FK_printStack(RideStack *s) {
    if (s->top < 0) {
        printf("  No rides taken yet.\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("  %d) %s\n", s->top - i + 1, s->items[i]);
    }
}

/* ============================================================
   GLOBALS FOR THIS MODULE
   ============================================================ */

static Ride *adultRides = NULL;
static Ride *childrenRides = NULL;
static Ride *heritageSites = NULL;

static int adultCount = 0;
static int childrenCount = 0;
static int heritageCount = 0;

static RideStack rideHistory;
static int remainingRides = 12;
static char currentVisitor[MAX_NAME_LEN] = "";

/* ============================================================
   Read last visitor name from userData.txt
   ============================================================ */

int getLastVisitorName(char *outName, int size) {
    FILE *f = fopen("userData.txt", "r");
    if (!f) return 0;

    char line[1000];
    char last[1000] = "";

    while (fgets(line, sizeof(line), f)) {
        strcpy(last, line);
    }
    fclose(f);

    char *p = strstr(last, "name:");
    if (!p) return 0;

    p += 5; // skip "name:"
    while (*p == ' ') p++;

    char *q = strstr(p, " age:");
    if (!q) return 0;

    int len = q - p;
    if (len >= size) len = size - 1;

    strncpy(outName, p, len);
    outName[len] = '\0';
    return 1;
}

/* ============================================================
   Create rides
   ============================================================ */

Ride *FK_createRides(const char *names[], int count, const int durations[]) {
    Ride *arr = malloc(sizeof(Ride) * count);
    for (int i = 0; i < count; i++) {
        strncpy(arr[i].name, names[i], MAX_RIDE_NAME - 1);
        arr[i].name[MAX_RIDE_NAME - 1] = '\0';
        arr[i].durationMinutes = durations[i];
        FK_initQueue(&arr[i].queue);
    }
    return arr;
}

/* ============================================================
   BUILD ALL SECTIONS
   ============================================================ */

void buildFantasyKingdom() {

    if (adultRides != NULL) return; // already built

    // Adult rides (13)
    const char *adultNames[] = {
        "Roller Coaster", "Magic Carpet", "Bumper Cars", "Flying Disco",
        "Ferris Wheel", "Pirate Ship", "VR Zone", "Horror House",
        "Tornado 360", "Santa Maria", "Wheely Bird", "ZuZu Train",
        "Heritage Coaster"
    };

    int adultDur[] = {6,4,5,5,6,5,8,7,6,6,4,3,7};
    adultCount = 13;

    adultRides = FK_createRides(adultNames, adultCount, adultDur);

    // Children rides
    const char *childNames[] = {
        "Highway Convoy", "Bull Dozer", "Sun & Moon",
        "Zip Around", "Pony Adventure", "Sky Hopper", "Kids Bumper Car"
    };
    int childDur[] = {3,3,2,3,4,3,3};
    childrenCount = 7;

    childrenRides = FK_createRides(childNames, childrenCount, childDur);

    // Heritage sites
    const char *heritNames[] = {
        "Sitakot Bihar", "Kantajir Mandir", "Ahsan Manzil", "Chunakhola Mosque",
        "National Monument", "Puthia Palace", "Shat Gombuj Mosque", "Paharpur"
    };
    int hDur[] = {0,0,0,0,0,0,0,0};
    heritageCount = 8;

    heritageSites = FK_createRides(heritNames, heritageCount, hDur);

    FK_initStack(&rideHistory);
}

/* ============================================================
   UI DISPLAYS
   ============================================================ */

void FK_showRideList() {
    printf("\n================== FANTASY KINGDOM RIDE LIST ==================\n");

    printf("\n-- Adult Section --\n");
    for (int i = 0; i < adultCount; i++)
        printf("%2d) %-22s  Queue: %2d  Wait: %d min\n",
               i + 1,
               adultRides[i].name,
               adultRides[i].queue.length,
               adultRides[i].queue.length * adultRides[i].durationMinutes);

    printf("\n-- Children Section --\n");
    for (int i = 0; i < childrenCount; i++)
        printf("%2d) %-22s  Queue: %2d  Wait: %d min  (Fare: %d tk)\n",
               i + 1,
               childrenRides[i].name,
               childrenRides[i].queue.length,
               childrenRides[i].queue.length * childrenRides[i].durationMinutes,
               CHILD_RIDE_FARE);

    printf("\n-- Heritage Section --\n");
    for (int i = 0; i < heritageCount; i++)
        printf("%2d) %-22s  (Visiting Only)\n",
               i + 1, heritageSites[i].name);

    printf("=================================================================\n");
}

/* ============================================================
   ADULT RIDE OPERATION
   ============================================================ */

void FK_takeAdultRide() {
    int choice;
    FK_showRideList();

    printf("\nSelect Adult Ride (1-%d) or 0 to cancel: ", adultCount);
    scanf("%d", &choice);

    if (choice <= 0 || choice > adultCount) return;

    if (remainingRides <= 0) {
        printf("No remaining rides left.\n");
        return;
    }

    int idx = choice - 1;

    FK_enqueue(&adultRides[idx].queue, currentVisitor);

    char name[MAX_NAME_LEN];
    FK_dequeue(&adultRides[idx].queue, name);

    printf("\nYou are now riding: %s\n", adultRides[idx].name);

    remainingRides--;
    FK_push(&rideHistory, adultRides[idx].name);

    printf("Remaining rides: %d\n", remainingRides);
}

/* ============================================================
   CHILD RIDE OPERATION
   ============================================================ */

void FK_takeChildRide() {
    FK_showRideList();

    printf("\nSelect Children Ride (1-%d) or 0 to cancel: ", childrenCount);
    int choice;
    scanf("%d", &choice);

    if (choice <= 0 || choice > childrenCount) return;

    int idx = choice - 1;

    FK_enqueue(&childrenRides[idx].queue, currentVisitor);

    char out[MAX_NAME_LEN];
    FK_dequeue(&childrenRides[idx].queue, out);

    printf("\nRide completed: %s\n", childrenRides[idx].name);

    printf("You paid: %d tk\n", CHILD_RIDE_FARE);

    FK_push(&rideHistory, childrenRides[idx].name);
}

/* ============================================================
   HERITAGE VISIT
   ============================================================ */

void FK_visitHeritage() {
    FK_showRideList();
    printf("\nSelect Heritage Site (1-%d) or 0 to cancel: ", heritageCount);
    int choice;
    scanf("%d", &choice);

    if (choice <= 0 || choice > heritageCount) return;

    int idx = choice - 1;

    printf("Visiting: %s\n", heritageSites[idx].name);

    FK_push(&rideHistory, heritageSites[idx].name);
}

/* ============================================================
   MAIN MODULE ENTRY
   ============================================================ */

void fantasyKingdomWelcoming() {

    buildFantasyKingdom();

    if (!getLastVisitorName(currentVisitor, sizeof(currentVisitor))) {
        printf("Enter your name: ");
        scanf(" %[^\n]", currentVisitor);
    }

    printf("\n=============== WELCOME %s TO FANTASY KINGDOM ===============\n",
           currentVisitor);

    remainingRides = 12;

    while (1) {
        printf("\nFantasy Kingdom Menu:\n");
        printf("1) View Ride List\n");
        printf("2) Take a Ride\n");
        printf("3) Show Remaining Rides\n");
        printf("4) Ride History\n");
        printf("5) Exit Fantasy Kingdom\n");
        printf("> ");

        int op;
        scanf("%d", &op);

        if (op == 1) FK_showRideList();

        else if (op == 2) {
            printf("\nSelect Ride Type:\n");
            printf("1) Adult Ride\n");
            printf("2) Children Ride\n");
            printf("3) Heritage Visit\n");
            printf("> ");
            int t;
            scanf("%d", &t);

            if (t == 1) FK_takeAdultRide();
            else if (t == 2) FK_takeChildRide();
            else if (t == 3) FK_visitHeritage();
        }

        else if (op == 3)
            printf("\nRemaining rides: %d\n", remainingRides);

        else if (op == 4)
            FK_printStack(&rideHistory);

        else if (op == 5) {
            printf("\nExiting Fantasy Kingdom...\n");
            return;
        }

        else printf("Invalid option.\n");
    }
}
