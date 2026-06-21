#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int ile=0;
    int granica_min;
    int granica_max;
    int *temps=nullptr;
    temps=(int *)malloc(sizeof(int)*ile);
    printf("Ile liczb chcesz wylosowac:\n");
    scanf("%d",&ile);
    printf("Podaj dolna granica przedzialu:\n");
    scanf("%d",&granica_min);
    printf("Podaj gorna granica przedzialu:\n");
    scanf("%d",&granica_max);
    int losowa_liczba=0;
    for(int i=0;i<ile;i++) {
        losowa_liczba=rand()%(granica_max - granica_min+1)+granica_min;
        temps[i]=losowa_liczba;
        printf("%d ",temps[i]);
    }free(temps);
    return 0;
}