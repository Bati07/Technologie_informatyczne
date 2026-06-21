#include <iostream>
#include "struktury.h"
#include "Funkcje.h"

int main() {
    printf("------------------------\n");
    printf("Witaj w grze!!!\n");
    printf("------------------------\n");
    struct Postac bohater;
    struct Przedmiot przedmiot;
    wybierz_klase(&bohater);
    printf("\n--- POSTAC UTWORZONA PONYSLNIE ---\n");
    Statystyki_bohatera(&bohater);
    printf("Witaj w Miescie\n");
    while (bohater.hp>0) {
        printf("Gdzie chcesz sie udac?\n");
        printf("------------------------\n");
        printf("1- karczma\n");
        printf("2- sklep\n");
        printf("3- lochy\n");
        printf("------------------------\n");
        printf("Jaka akcje chcesz wykonac?\n");
        printf("------------------------\n");
        printf("4- Wyswietl statystyki\n");
        printf("5- Pokaz ekwipunek\n");
        int wybor;
        scanf("%d", &wybor);
        switch (wybor) {
            case 1:
                wejsce_do_karczmy(&bohater);
                Statystyki_bohatera(&bohater);
                break;
            case 2:
                wejsce_do_sklepu(&bohater,&przedmiot);
                break;
            case 3:
                wejdz_do_lochow(&bohater);
                break;
            case 4:
                Statystyki_bohatera(&bohater);
                break;
            case 5:
                opcje_ekwipunek(&bohater,&przedmiot);
                break;
        }
    }
    return 0;
}