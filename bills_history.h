#include <stdio.h>

void save_bill(char name[], char bill[14][200]){
    FILE *f;

    char path[30];

    sprintf(path, "bills/%s.txt", name);

    f = fopen(path, "w");

    for (int i=0; i<14; i++){
        fprintf(f, "%s\n", bill[i]);
    }

    fclose(f);
}

char (*read_bill(char name[]))[200] {
    static char bill[14][200] = {0};
    char path[100];

    sprintf(path, "bills/%s.txt", name);

    FILE *f = fopen(path, "r");

    if (f == NULL) {
        return NULL;
    }

    for (int i = 0; i < 14; i++) {
        bill[i][0] = '\0';
    }

    int i = 0;

    while (i < 14 && fgets(bill[i], 200, f) != NULL) {
        i++;
    }

    fclose(f);

    return bill;
}
