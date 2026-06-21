#include <algorithm>
#include <iostream>



void toLower(char *text) {
    while (*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}

void toUpper(char *text) {
    while (*text) {
        if ('a' <= *text && *text <= 'z') {
            *text += ('A' - 'a');
        }
        text++;
    }
}
int policzZnaki(char *text) {
    int licznik = 0;
    while (*text) {
        licznik++;
        text++;
    }
    return licznik;
}

int main(int argc, char* argv[]) {
    for (int i=1; i<argc; i++ ) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    for (int i=1; i<argc; i++ ) {
        toUpper(argv[i]);
        printf("%s ", argv[i]);
    }
    printf("\n");
    for (int i=1; i<argc; i++ ) {
        toLower(argv[i]);
        printf("%s ", argv[i]);
    }
    printf("\n");
    int suma_cal = 0;
    for (int i=1; i<argc; i++ ) {
       int result = policzZnaki(argv[i]);
        suma_cal += result;
        printf("Slowo: %s ma %d znakow\n", argv[i], result);
    }
    printf("ilosc wszystkich znakwo %d",suma_cal);

    return 0;
}