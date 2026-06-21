#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int ile = 0;
    int granica_min, granica_max;
    int *temps = nullptr;
    printf("Podaj dolna granice przedzialu:\n");
    scanf("%d", &granica_min);
    printf("Podaj gorna granice przedzialu:\n");
    scanf("%d", &granica_max);
    int losowa_liczba = 0;
    do {
        printf("Ile liczb chcesz wylosowac (wpisz 0 aby skonczyc):\n");
        scanf("%d", &ile);
        if (ile > 0) {
            int *ptr = (int *)realloc(temps, sizeof(int) * ile);
            if (ptr == nullptr) {
                printf("Blad alokacji pamieci!\n");
                free(temps);
                return 1;
            }
            temps = ptr;
            for (int i = 0; i < ile; i++) {
                losowa_liczba = rand() % (granica_max - granica_min + 1) + granica_min;
                temps[i] = losowa_liczba;
                printf("%d ", temps[i]);
            }
            printf("\n");
        }
    } while (ile > 0);
    free(temps);
    return 0;
}