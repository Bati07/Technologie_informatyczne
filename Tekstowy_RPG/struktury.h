//
// Created by bati2 on 5.06.2026.
//

#ifndef TEKSTOWY_RPG_STRUKTURY_H
#define TEKSTOWY_RPG_STRUKTURY_H
struct Przedmiot {
    char nazwa[50];
    int bonusowy_atak;
    int bonusowa_obrona;
    int wartosc;
};
struct Postac {
    char imie[30];
    int hp;
    int max_hp;
    int atak;
    int obrona;
    int zloto;
    struct Przedmiot ekwipunek[5];
    int liczba_przedmiotow;
    int id_lokacji;
    char nazwa[30];
};
struct Potwor {
  char nazwa[30];
  int poziom;
  int hp;
  int atak;
  int zloto_drop;
};
#endif //TEKSTOWY_RPG_STRUKTURY_H