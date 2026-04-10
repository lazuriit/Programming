#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fullName[32];
    int id;
    char level[16];
} Employee;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s staff.csv\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char buf[256];
    char fullName[32];
    char level[16];
    int id;

    Employee staff[100];
    int count = 0;

    while (fgets(buf, sizeof(buf), file)) {
        if (sscanf(buf, "%[^;];%d;%s", fullName, &id, level) == 3) {
            printf("%s; %d; %s\n", fullName, id, level);
            
            strcpy(staff[count].fullName, fullName);
            staff[count].id = id;
            strcpy(staff[count].level, level);
            count++;
        }
    }

    fclose(file);

    FILE *dbOut = fopen("database.dat", "wb");
    if (dbOut) {
        fwrite(staff, sizeof(Employee), count, dbOut);
        fclose(dbOut);
    }

    int searchId;
    printf("\nEnter ID to search: ");
    if (scanf("%d", &searchId) != 1) return 0;

    FILE *dbIn = fopen("database.dat", "rb");
    if (dbIn == NULL) {
        perror("Error opening database.dat");
        exit(1);
    }

    Employee temp;
    int found = 0;

    while (fread(&temp, sizeof(Employee), 1, dbIn)) {
        if (temp.id == searchId) {
            printf("\nFound: %s, %d, %s\n", temp.fullName, temp.id, temp.level);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: ID %d not found\n", searchId);
    }

    fclose(dbIn);

    return 0;
}
