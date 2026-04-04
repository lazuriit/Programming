#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


    while (fgets(buf, sizeof(buf), file)) {
        if (sscanf(buf, "%[^;];%d;%s", fullName, &id, level) == 3) {
            printf("%s; %d; %s\n", fullName, id, level);
        }
    }

    fclose(file);
    return 0;
}
