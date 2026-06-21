//
// Created by bati2 on 5.06.2026.
//
#include <iostream>
#include "struktury.h"
#include "Funkcje.h"

#include <limits>
#include <time.h>
void wybierz_klase(struct Postac *g) {
    int wybor;
    printf("Wybierz klase postaci:\n1. Wojownik (Wiecej HP)\n2. Lotr (Wiecej zlota i ataku)\nWybor: ");
    scanf("%d", &wybor);

    printf("Podaj imie: ");
    scanf("%29s", g->imie);

    if (wybor == 1) {
        g->max_hp = 150;
        g->atak = 6;
        g->obrona = 5;
        g->zloto = 20;
    } else {
        g->max_hp = 90;
        g->atak = 18;
        g->obrona = 0;
        g->zloto = 100;
    }
    g->hp = g->max_hp;
    g->liczba_przedmiotow = 0;
    g->id_lokacji = 0;
}
void Statystyki_bohatera(struct Postac *g) {
    printf("Imie: %s\n", g->imie);
    printf("HP: %d/%d\n", g->hp, g->max_hp);
    printf("Atak: %d\n", g->atak);
    printf("Obrona: %d\n",g->obrona);
    printf("Zloto: %d\n", g->zloto);}
void wyswietl_ekwipunek(struct Postac *g) {
    printf("\n===== TWOJ EKWIPUNEK (%d/5) =====\n", g->liczba_przedmiotow);
    if (g->liczba_przedmiotow == 0) {
        printf("Twoj plecak jest pusty.\n");
        return;
    }
    for (int i = 0; i < g->liczba_przedmiotow; i++) {
        printf("%d. %s (Atak: +%d, Obrona: +%d)\n",
               i + 1,
               g->ekwipunek[i].nazwa,
               g->ekwipunek[i].bonusowy_atak,
               g->ekwipunek[i].bonusowa_obrona);
    }
}
void opcja_picia(struct Postac *g) {
    int kontynuj_picie=1;
    while (kontynuj_picie) {
        int wybor;
        printf("Czy chcesz wydac 5zl na piwo?\n");
        printf("1- Tak\n2- Nie\n");
        scanf("%d", &wybor);
        switch (wybor) {
            case 1:
                g->zloto= g->zloto - 5;
                g->atak = g->atak + 1 ;
                g->hp = g->hp - 5;
                printf("Twoj atak wzrosl!! o 1\n");
                printf("Twoje zdrowiezmalalo!! o 5\n");
                printf("Masz %d hp\n",g->hp);
                break;
            case 2:
                kontynuj_picie=0;
                break;
            default:
                printf("zly wybor!!\n");
                break;
        }
    }
}
void opcja_leczenia (struct  Postac *g) {
                    int kontynuj_leczenie=1;
                while (kontynuj_leczenie){
                printf("z jakiej oferty chcesz skozyzstac?\n");
                printf("Masz %d hp\n",g->hp);
                printf("Masz %d zl\n",g->zloto);
                printf("1- za 10 zl 5hp\n");
                printf("2- za 20 zl 10hp\n");
                printf("3- za 30 zl 15hp\n");
                printf("4- za 50zl uleczyc sie calkowice\n");
                printf("5- opuscic medyka\n");
                int wybor;
                scanf("%d", &wybor);
                switch (wybor) {
                    case 1:
                        if (g->zloto>=10) {
                            g->hp = g->hp + 5;
                            g->zloto = g->zloto - 10;
                            if (g->hp>g->max_hp) {
                                g->hp=g->max_hp;
                            }
                        }else printf("nie masz wystarczajaco zl\n");
                        printf("Masz %d/%d hp\n",g->hp,g->max_hp);
                        break;
                    case 2:
                        if (g->zloto>=20) {
                            g->hp = g->hp + 10;
                            g->zloto = g->zloto - 20;
                            if (g->hp>g->max_hp) {
                                g->hp=g->max_hp;
                            }
                        }else printf("nie masz wystarczajaco zl\n");
                        printf("Masz %d/%d hp\n",g->hp,g->max_hp);
                        break;
                    case 3:
                        if (g->zloto>=30) {
                            g->hp = g->hp + 15;
                            g->zloto = g->zloto - 30;
                            if (g->hp>g->max_hp) {
                                g->hp=g->max_hp;
                            }
                        }printf("nie masz wystarczajaco zl\n");
                        printf("Masz %d/%d hp\n",g->hp,g->max_hp);
                        break;
                    case 4:
                        if (g->zloto>=50) {
                            g->hp = g->max_hp;
                            g->zloto = g->zloto - 50;
                        }else printf("nie masz wystarczajaco zl\n");
                        printf("Masz %d/%d hp\n",g->hp,g->max_hp);
                        break;
                    case 5:
                        kontynuj_leczenie=0;
                        break;
                    default:
                        printf("zly wybor\n");
                    }
                }
}
void gra_w_kosci (struct Postac *g) {
    int kontynuj=1;
    while (kontynuj){
        printf("Czy chcesz zagrac w kosci?\n");
        printf("1- Tak\n2- Nie\n");
        int wybor;
        scanf("%d",&wybor);
        switch (wybor) {
            case 1: {
                srand(time(NULL));
                printf("Masz %d zlota\n",g->zloto);
                int kwota_zakladu;
                printf("Ile chcesz postawic?\n");
                scanf("%d",&kwota_zakladu);
                if (kwota_zakladu>g->zloto) {
                    printf("nie masz wystarczajaco zl\n");
                    return;
                }
                int suma_gracza=0;
                int suma_przeciwnika=0;
                for (int i=0; i<3; i++) {
                    int rzut_kosci = (rand() % 6)+1;
                    suma_gracza=+rzut_kosci;
                }
                printf("Twoj wynik to: %d\n",suma_gracza);
                for (int i=0; i<3; i++) {
                    int rzut_kosci = (rand() % 6)+1;
                    suma_przeciwnika=+rzut_kosci;
                }
                printf("Wyniki przeciwnika to: %d\n",suma_przeciwnika);
                if (suma_gracza>suma_przeciwnika) {
                    g->zloto=g->zloto+(kwota_zakladu*2);
                    printf("Ilosc twojego zlota to: %d\n", g->zloto);
                }else if (suma_gracza==suma_przeciwnika) {
                    printf("Nic sie nie stalo\n");
                }else {
                    g->zloto=g->zloto-kwota_zakladu;
                }
                printf("Masz %d zl\n",g->zloto);
                break;
            }
            case 2:
                kontynuj=0;
                break;
        }
    }
}
void wejsce_do_karczmy(struct Postac *g) {

    printf("Witaj w karczmie!!\n");
    while (1) {
        int wybor_karczma=0;
        printf("co chialbys zrobic?\n");
        printf("------------------------\n");
        printf("1- Napij sie\n");
        printf("2- zagraj w kosci\n");
        printf("3- ulecz sie\n");
        printf("4- wyjdz na rynke\n");
        printf("------------------------\n");
        scanf("%d", &wybor_karczma);
        switch (wybor_karczma) {
            case 1:
                opcja_picia(g);
                break;
            case 2:
                gra_w_kosci(g);
                break;
            case 3:
                opcja_leczenia(g);
                break;
            case 4:
                printf("jestes na rynku\n");
                return;
            default:
                printf("zly wybor\n");
        }
    }
}

void oferta_sklepu(struct Przedmiot towar[], int rozmiar) {
    printf("\n===== OFERTA KUPCA =====\n");
    printf("%-3s | %-22s | %-6s | %-6s | %-6s\n", "ID", "Nazwa przedmiotu", "Atak", "Obrona", "Cena");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("%d.  | %-22s | +%-5d | +%-5d | %d zl\n",
                i +1,
               towar[i].nazwa,
               towar[i].bonusowy_atak,
               towar[i].bonusowa_obrona,
               towar[i].wartosc);
    }
}
struct Przedmiot sklep[10] = {
    {"Drewniany Miecz",      3,  0,  15},
    {"Zardzewialy Sztylet",   2,  1,  20},
    {"Skorzana Kurtka",       0,  4,  25},
    {"Puklerz z Drewna",      1,  5,  35},

    {"Zelazny Miecz",        8,  0,  75},
    {"Kolczuga",             0, 12, 110},
    {"Wzmocniona Tarcza",    2, 15, 140},

    {"Krolewski Rapier",    18,  2, 300},
    {"Krysztalowa Zbroja",   0, 25, 450},
    {"Smoczy Kiel", 30,  5, 800}
};
int dodaj_do_ekwipunku(struct Postac *g, struct Przedmiot nowy_przedmiot) {
    if (g->liczba_przedmiotow >= 5) {
        printf("Twój ekwipunek jest pełny! (Max 5 przedmiotów)\n");
        return 0;
    }
    g->ekwipunek[g->liczba_przedmiotow] = nowy_przedmiot;
    g->atak += nowy_przedmiot.bonusowy_atak;
    g->obrona += nowy_przedmiot.bonusowa_obrona;
    g->liczba_przedmiotow++;
    return 1;
}
void kupno_przedmiotu(struct Przedmiot towar[], int rozmiar, struct Postac *g) {
        printf("Masz %d zlota\n",g->zloto);
        oferta_sklepu(sklep, rozmiar);
        printf("ktora pozycje chcesz kupic? wpisz 0 zeby wyjsc\n");
        scanf("%d", &rozmiar);
        if (rozmiar==0) return;
        rozmiar= rozmiar-1;
        if (rozmiar < 10) {
            if (g->zloto<towar[rozmiar].wartosc) {
                printf("Masz za malo zlota\n");
            }else {

                if (dodaj_do_ekwipunku(g, towar[rozmiar])) {
                    g->zloto=g->zloto-towar[rozmiar].wartosc;
                    printf("kupiles %s\n",towar[rozmiar].nazwa);
                    printf("Twoj atak wzrosl o: %d, a obrona o: %d\n", towar[rozmiar].bonusowy_atak, towar[rozmiar].bonusowa_obrona);
                }
            }
        }else {
            printf("zly wybor\n");
        }
        printf("zostalo ci %d zl\n",g->zloto);
}
void wejsce_do_sklepu(struct Postac *g, struct Przedmiot *p) {
    printf("Witaj w sklepie\n");
    printf("Co chcesz zrobic?\n");
    printf("------------------------\n");
    printf("1- zobacz oferte\n");
    printf("2- Kupic przedmiot\n");


    int wybor;
    scanf("%d", &wybor);
    switch(wybor) {
        case 1:
            oferta_sklepu(sklep, 10);
            break;
        case 2:
            kupno_przedmiotu(sklep, 10, g);

    }
}
void usun_przedmiot(struct Przedmiot *p, struct Postac *g) {
    if (g->liczba_przedmiotow == 0) {
        printf("Twoj ekwipunek jest pusty! Nie masz czego usunac.\n");
        return;
    }
    wyswietl_ekwipunek(g);
    printf("Ktory przedmiot chcesz usunac?\n");
    printf("Wpisz 0 zeby wyjsc: ");
    int numer;
    scanf("%d", &numer);
    if (numer == 0) return;
    int indeks = numer - 1;
    if (indeks < 0 || indeks >= g->liczba_przedmiotow) {
        printf("Bledny wybor! Taki przedmiot nie istnieje.\n");
        return;
    }
    g->atak -= g->ekwipunek[indeks].bonusowy_atak;
    g->obrona -= g->ekwipunek[indeks].bonusowa_obrona;

    printf("Usunieto przedmiot: %s (Straciles: Atak -%d, Obrona -%d)\n",
           g->ekwipunek[indeks].nazwa,
           g->ekwipunek[indeks].bonusowy_atak,
           g->ekwipunek[indeks].bonusowa_obrona);
    g->liczba_przedmiotow--;
    for (int i = indeks; i < g->liczba_przedmiotow; i++) {
        g->ekwipunek[i] = g->ekwipunek[i + 1];
    }
}
void opcje_ekwipunek(struct Postac *g, struct Przedmiot *p) {
    printf("Witaj w ekwipunku\n");

    int kontynuj=1;
    while (kontynuj) {
        int wybor;
        printf("co chcesz zrobic?\n");
        printf("1- wyswietl ekwipunek\n");
        printf("2- usun przedmio z ekwipunku\n");
        printf("3- wyjdz z ekwipunku\n");
        scanf("%d",&wybor);
        switch(wybor) {
            case 1:
                wyswietl_ekwipunek(g);
                break;
            case 2:
                usun_przedmiot(p,g);
                break;
            case 3:
                kontynuj=0;
                break;
        }

    }
}
struct Potwor lochy_lvl1[3] = {
    {"Zly Szczur",          1, 20,  4, 12},
    {"Szkielet Wojownik",   1, 35,  6, 20},
    {"Przywodca Goblinow",  2, 55,  9, 35}
};
struct Potwor lochy_lvl2[3] = {
    {"Skalny Golem",        3, 70,  12, 50},
    {"Mroczny Elf",         4, 85,  16, 75},
    {"Minotaur Berserker",  5, 120, 21, 110}
};
struct Potwor lochy_lvl3[3] = {
    {"Ogr Szaman",          6, 150, 26, 160},
    {"Wampirzy Lord",       7, 190, 32, 250},
    {"Czerwony Smok",       8, 280, 38, 500}
};

void walka(struct Postac *g, struct Potwor *p) {
    printf("\n!!! ROZPOCZYNASZ WALKE Z: %s !!!\n", p->nazwa);
    while (p->hp > 0 && g->hp > 0) {
        int rozrzut_gracza = (rand() % 5) - 2;
        int obrazenia_gracza = g->atak + rozrzut_gracza;
        int szansa_na_kryta = rand() % 100;
        int czy_kryt = 0;
        if (szansa_na_kryta < 15) {
            obrazenia_gracza *= 2;
            czy_kryt = 1;
        }
        if (obrazenia_gracza < 1) obrazenia_gracza = 1;
        p->hp -= obrazenia_gracza;
        if (czy_kryt) {
            printf("[KRYTYK!] Trafiasz potwora poteznym ciosem za %d obrazen!\n", obrazenia_gracza);
        } else {
            printf("Uderzasz %s za %d punktow obrazen! (Rozrzut: %+d)\n", p->nazwa, obrazenia_gracza, rozrzut_gracza);
        }
        int wyswietlane_hp_potwora = (p->hp < 0) ? 0 : p->hp;
        printf("HP Potwora: %d\n", wyswietlane_hp_potwora);
        if (p->hp <= 0) break;
        int rozrzut_potwora = (rand() % 3) - 1;
        int obrazenia_potwora = (p->atak + rozrzut_potwora) - (g->obrona / 2);
        int szansa_na_kryta_potwora = rand() % 100;
        int czy_kryt_potwora = 0;
        if (szansa_na_kryta_potwora < 5) {
            obrazenia_potwora *= 2;
            czy_kryt_potwora = 1;
        }
        if (obrazenia_potwora < 1) obrazenia_potwora = 1;
        g->hp -= obrazenia_potwora;
        if (czy_kryt_potwora) {
            printf("[KRYTYK POTWORA!] %s wyprowadza morderczy atak za %d punktow obrazen!\n", p->nazwa, obrazenia_potwora);
        } else {
            printf("%s kontratakuje za %d punktow obrazen!\n", p->nazwa, obrazenia_potwora);
        }
        int wyswietlane_hp_gracza = (g->hp < 0) ? 0 : g->hp;
        printf("Twoje HP: %d/%d\n\n", wyswietlane_hp_gracza, g->max_hp);
    }
    if (g->hp > 0) {
        printf("Zwyciestwo! Pokonales %s.\n", p->nazwa);
        printf("Znajdujesz %d złota przy ciele potwora.\n", p->zloto_drop);
        g->zloto += p->zloto_drop;
    }
}

struct Potwor* pobierz_zestaw_potworow(int poziom) {
    if (poziom == 0) return lochy_lvl1;
    if (poziom == 1) return lochy_lvl2;
    return lochy_lvl3;
}

void obsluga_smierci(struct Postac *g, int poziom) {
    int koszt_odrodzenia = (g->max_hp / 2) * (poziom + 1);
    printf("\nPOLEGLES! Koszt wskrzeszenia u medyka: %d zl.\n", koszt_odrodzenia);
    printf("1- Zaplac i wroc na rynek (zachowujesz postep)\n2- Poddaj sie (Koniec gry)\n");

    int wybor;
    scanf("%d", &wybor);
    if (wybor == 1 && g->zloto >= koszt_odrodzenia) {
        g->zloto -= koszt_odrodzenia;
        g->hp = g->max_hp / 2;
        printf("Medyk poskladal Twoje kosci. Wracasz na rynek z polowa HP.\n");
    } else {
        printf("Twoja przygoda dobiegla konca...\n");
        exit(0);
    }
}

void generuj_mape(int mapa[3][3]) {
    for (int r = 0; r < 3; r++) {
        for (int k = 0; k < 3; k++) {
            mapa[r][k] = 0;
        }
    }
    int klucz_k = rand() % 3;
    mapa[1][klucz_k] = 4;
    int wyjscie_k = rand() % 3;
    mapa[2][wyjscie_k] = 5;
    for (int potwor = 1; potwor <= 3; potwor++) {
        int rzucono = 0;
        while (!rzucono) {
            int los_r = rand() % 3;
            int los_k = rand() % 3;
            if (mapa[los_r][los_k] == 0 && !(los_r == 0 && los_k == 0)) {
                mapa[los_r][los_k] = potwor;
                rzucono = 1;
            }
        }
    }
}

void wykonaj_ruch(int *r, int *k) {
    printf("Gdzie chcesz sie ruszyc?\n");
    printf("1 - Gora  | 2 - Dol\n3 - Lewo  | 4 - Prawo\nWybor: ");
    int ruch;
    scanf("%d", &ruch);
    int nowy_r = *r;
    int nowy_k = *k;
    switch (ruch) {
        case 1: nowy_r--; break;
        case 2: nowy_r++; break;
        case 3: nowy_k--; break;
        case 4: nowy_k++; break;
        default: printf("Zly wybor kierunku!\n"); return;
    }
    if (nowy_r < 0 || nowy_r > 2 || nowy_k < 0 || nowy_k > 2) {
        printf("[!] Uderzasz w sciane! Nie mozesz tam przejsc.\n");
        return;
    }
    *r = nowy_r;
    *k = nowy_k;
}

void obsluga_pola(struct Postac *g, int mapa[3][3], int r, int k, struct Potwor *aktualny_zestaw, int *ma_klucz, int *poziom_zakonczony, int poziom) {
    int zawartosc = mapa[r][k];
    if (zawartosc >= 1 && zawartosc <= 3) {
        struct Potwor potwor_w_walce = aktualny_zestaw[zawartosc - 1];
        walka(g, &potwor_w_walce);
        if (g->hp <= 0) {
            obsluga_smierci(g, poziom);
            return;
        }
        mapa[r][k] = 0;
    }
    else if (zawartosc == 4) {
        *ma_klucz = 1;
        printf("\n[ KLUCZ ] Przeszukujesz pokoj i znajdujesz lsniacy klucz!\n");
        mapa[r][k] = 0;
    }
    else if (zawartosc == 5) {
        printf("\n[ WYJSCIE ] Odnajdujesz wielkie, debowe drzwi prowadzace na rynek.\n");
        if (*ma_klucz) {
            printf("Uzywasz klucza! Drzwi otwieraja sie z glosnym skrzypieniem.\n");
            *poziom_zakonczony = 1;
        } else {
            printf("Drzwi sa zamkniete! Musisz najpierw znalezc klucz\n");
        }
    }
    else {
        printf("\nWkraczasz do ciemnego, pustego pomieszczenia. Jest tu bezpiecznie.\n");
    }
}

void wejdz_do_lochow(struct Postac *g) {
    if (g->id_lokacji >= 3) {
        printf("\nGratulacje! Wszystkie lochy zostaly juz przez Ciebie oczyszczone!\n");
        return;
    }
    int poziom = g->id_lokacji;
    struct Potwor *aktualny_zestaw = pobierz_zestaw_potworow(poziom);
    int mapa[3][3];
    generuj_mape(mapa);
    int gracz_r = 0;
    int gracz_k = 0;
    int ma_klucz = 0;
    int poziom_zakonczony = 0;
    printf("\n=======================================================\n");
    printf("WKRACZASZ DO LOCHOW POZIOMU %d!\n", poziom + 1);
    printf("=======================================================\n");
    while (!poziom_zakonczony && g->hp > 0) {
        printf("\n--- MAPA LOCHOW ---\n");
        for (int r = 0; r < 3; r++) {
            for (int k = 0; k < 3; k++) {
                if (r == gracz_r && k == gracz_k) printf("[ P ] ");
                else printf("[ ? ] ");
            }
            printf("\n");
        }
        printf("-------------------\n");
        printf("Pozycja: Rzad %d, Kolumna %d | Klucz: %s\n", gracz_r + 1, gracz_k + 1, ma_klucz ? "TAK" : "NIE");
        wykonaj_ruch(&gracz_r, &gracz_k);
        if (g->hp <= 0) return;
        obsluga_pola(g, mapa, gracz_r, gracz_k, aktualny_zestaw, &ma_klucz, &poziom_zakonczony, poziom);
    }
    if (g->hp > 0) {
        printf("\n=======================================================\n");
        printf("SUKCES! Udalo Ci sie znalezc wyjscie z Poziomu %d lochow!\n", poziom + 1);
        printf("=======================================================\n");
        printf("Co chcesz teraz zrobic?\n");
        printf("1 - Wroc bezpiecznie na rynek miasta\n");
        if (g->id_lokacji < 2) {
            printf("2 - Awansuj i przejdz do nastepnego, trudniejszego poziomu (Poziom %d)\n", poziom + 2);
        } else {
            printf("[!] To byl ostatni poziom lochow, nie mozesz isc dalej!\n");
        }
        if (g->id_lokacji > 0) {
            printf("3 - Wroc na poprzedni, latwiejszy poziom (Poziom %d)\n", poziom);
        }
        printf("Wybor: ");
        int wybor_progresu;
        scanf("%d", &wybor_progresu);
        if (wybor_progresu == 2 && g->id_lokacji < 2) {
            g->id_lokacji++;
            printf("\nAwansowales! Przy nastepnym wejsciu trafisz na Poziom %d.\n", g->id_lokacji + 1);
            printf("Teraz wracasz na rynek, abys mogl sie przygotowac.\n");
        }
        else if (wybor_progresu == 3 && g->id_lokacji > 0) {
            g->id_lokacji--;
            printf("\nObnizyles poziom trudnosci. Przy nastepnym wejsciu trafisz na Poziom %d.\n", g->id_lokacji + 1);
            printf("Teraz wracasz na rynek, abys mogl sie przygotowac.\n");
        }
        else {
            printf("\nZdecydowales sie pozostac na Poziomu %d.\n", g->id_lokacji + 1);
            printf("Wracasz na rynek miasta.\n");
        }
    }
}