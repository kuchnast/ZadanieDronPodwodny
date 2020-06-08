#ifndef INTERFEJS_PROGRAMU_HH
#define INTERFEJS_PROGRAMU_HH

#include "KolekcjaObiektow.hh"

enum TypObiektu
{
    TO_DRON,
    TO_PRZESZKODA
};

enum RodzajPrzeszkody
{
    RP_PROSTOPADLOSCIAN
};

/**
 * @brief Funkcja wyświetla menu programu z możliwymi opcjami
 * 
 */
void WyswietlMenuGlowne();

void WyswietlMenuObiektow();

void WyswietlMenuPrzeszkod();

void WyswietlLiczbeWektorow();

bool DronRuchWPrzod(KolekcjaObiektow &K);

bool DronObrot(KolekcjaObiektow &K);

bool DronWznoszenie(KolekcjaObiektow &K);

bool DodajObiekt(KolekcjaObiektow &K);

bool UsunObiekt(KolekcjaObiektow &K);

bool ZmienAktywnegoDrona(KolekcjaObiektow &K);

#endif