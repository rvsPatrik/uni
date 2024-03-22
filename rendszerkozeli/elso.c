#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void seperator() {
    printf("\n- - - - - - - - - -\n");
}

void showVersion() {
    seperator();
    printf("\nA program verzioszama: alpha v0.1\n");
    printf("A program elkeszulesenek datuma: 2024.02.29");
    printf("A program fejlesztojenek neve: Revesz Patrik\n");
    seperator();
}

void showHelp() {
    seperator();
    printf("A program uzemmpdjai: \n");
    printf("- A program alapertelmezetten kuldokent viselkedik -\n");
    printf("\n| -send | - A program kuldokent viselkedik.\n");
    printf("| -recieve | - A program fogadokent mukodik.\n");
    seperator();
    printf("\nA kommunikacio modja:\n");
    printf("- A program alapertelmezett kommunikacios modja: fajl -\n");
    printf("| -file | - A program fajt hasznal kommunikaciora.\n");
    printf("| -socket | - A program socketet hasznal a kommunikaciora.\n");
    seperator();
}

int contains(char **array, int size, const char *element) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i], element) == 0) {
            return 1; // Found
        }
    }
    return 0; // Not found
}


int Measurement(int **Values) {
    
    int count = 100; 
    
    *Values = (int *)malloc(count * sizeof(int));
    if (*Values == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1; 
    }

    
    (*Values)[0] = 0;

    
    for (int i = 1; i < count; i++) {
        
        int random = rand() % 31 + 1;
        
        if (random <= 13) {
            (*Values)[i] = (*Values)[i - 1];
        }

        else if (random <= 24) {
            (*Values)[i] = (*Values)[i - 1] + 1;
        }
        
        else {
            (*Values)[i] = (*Values)[i - 1] - 1;
        }
    }

    
    return count;
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    if (strcmp(argv[0], "chart") != 0) {
        printf("Hiba: A futtatható állomány neve nem chart.\n");
        return 1;
    }

    if (argc == 1 || contains(argv, argc, "--help")) {
        showHelp();
        return 0;
    }

    if (contains(argv, argc, "--version")) {
        showVersion();
        return 0;
    }

    int senderMode = 1;
    int useFile = 1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-send") == 0) {
            senderMode = 1;
        } else if (strcmp(argv[i], "-receive") == 0) {
            senderMode = 0;
        } else if (strcmp(argv[i], "-file") == 0) {
            useFile = 1;
        } else if (strcmp(argv[i], "-socket") == 0) {
            useFile = 0;
        } else {
            printf("Nem érvényes argumentum: %s\n", argv[i]);
            showHelp();
            return 1;
        }
    }

    if (senderMode) {
        printf("A program küldő üzemmódban fut.\n");
    } else {
        printf("A program fogadó üzemmódban fut.\n");
    }

    if (useFile) {
        printf("A program fájlt használ a kommunikáció során.\n");
    } else {
        printf("A program socketet használ a kommunikáció során.\n");
    }

    
    int *values;
    int valueCount = Measurement(&values);
    printf("Előállított értékek: ");
    for (int i = 0; i < valueCount; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    
    free(values);

    return 0;
}
