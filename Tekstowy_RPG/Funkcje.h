//
// Created by bati2 on 5.06.2026.
//

#ifndef TEKSTOWY_RPG_FUNKCJE_H
#define TEKSTOWY_RPG_FUNKCJE_H

void wybierz_klase(struct Postac *g);
void Statystyki_bohatera(struct Postac *g);
void wejsce_do_karczmy(struct Postac *g);
void wejsce_do_sklepu(struct Postac *g, struct Przedmiot *p);
void wyswietl_ekwipunek(struct Postac *g);
void opcje_ekwipunek(struct Postac *g, struct Przedmiot *p);
void wejdz_do_lochow(struct Postac *g);
#endif