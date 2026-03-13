#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct room {
    char name[50];  
    int level;      
    int number;      
    int resolution;  
};

struct node {
    struct room data;
    struct node *next;
};

typedef struct node node_t;

node_t* newNode(struct room data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node_t* appendBack(node_t* head, struct room data) {
    node_t* new_node = newNode(data);

    if (head == NULL)
        return new_node;

    node_t* cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = new_node;
    return head;
}

void printList(node_t* head) {
    node_t* cur = head;

    while (cur != NULL) {
        printf("Name: %s\n", cur->data.name);
        printf("Level: %d\n", cur->data.level);
        printf("Number: %d\n", cur->data.number);
        printf("Resolution: %d\n", cur->data.resolution);
        printf("---------------------\n");

        cur = cur->next;
    }
}

struct room randomRoom(int i) {
    struct room r;

    sprintf(r.name, "Room_%d", i+1);
    r.level = rand() % 10 + 1;
    r.number = rand() % 100;
    r.resolution = rand() % 50 + 10;

    return r;
}

int main() {
    srand(time(NULL));

    int N;
    printf("Введите количество комнат: ");
    scanf("%d", &N);

    node_t* head = NULL;

    for (int i = 0; i < N; i++) {
        struct room r = randomRoom(i);
        head = appendBack(head, r);
    }

    printf("\nСписок комнат:\n");
    printList(head);

    return 0;
}
