#ifndef INTERFEJS_PROGRAMU_HH
#define INTERFEJS_PROGRAMU_HH

#include "KolekcjaObiektow.hh"

/**
 * @brief Typy obiektów możliwych do utworzenia
 * 
 */
enum TypObiektu
{
    TO_DRON,
    TO_PRZESZKODA
};

/**
 * @brief Rodzaje przeszkód możliwych do utworzenia
 * 
 */
enum RodzajPrzeszkody
{
    RP_PROSTOPADLOSCIAN
};

/**
 * @brief Wyświetla menu programu z możliwymi opcjami
 * 
 */
void WyswietlMenuGlowne();

/**
 * @brief Wyświetla menu obiektów możliwych do utworzenia
 * 
 */
void WyswietlMenuObiektow();

/**
 * @brief Wyświetla menu przeszkód możliwych do utworzenia
 * 
 */
void WyswietlMenuPrzeszkod();

/**
 * @brief Wyświetla liczbę obecnie przechowywanych wektorów
 * 
 */
void WyswietlLiczbeWektorow();

/**
 * @brief Ruch do przodu aktywnym dronem
 * 
 * @param K kolekcja obiektów zbiornika
 * @return true jeżeli poprawnie wykonano ruch
 * @return false jeżeli kolizja lub błąd
 */
bool DronRuchWPrzod(KolekcjaObiektow &K);

/**
 * @brief Obrót aktywnym dronem
 * 
 * @param K kolekcja obiektów zbiornika
 * @return true jeżeli poprawnie wykonano ruch
 * @return false jeżeli kolizja lub błąd
 */
bool DronObrot(KolekcjaObiektow &K);

/**
 * @brief Ruch w pionie aktywnym dronem
 * 
 * @param K kolekcja obiektów zbiornika
 * @return true jeżeli poprawnie wykonano ruch
 * @return false jeżeli kolizja lub błąd
 */
bool DronWznoszenie(KolekcjaObiektow &K);

/**
 * @brief Wyświetla menu obiektów i dodaje obiekt do zbiornika
 * 
 * @param K kolekcja obiektów zbiornika
 * @return true jeżeli poprawnie dodano obiekt
 * @return false jeżeli błąd
 */
bool DodajObiekt(KolekcjaObiektow &K);

/**
 * @brief Wyświetla menu obiektów i usuwa obiekt ze zbiornika
 * 
 * @param K kolekcja obiektów zbiornika
 * @return true jeżeli poprawnie usunięto obiekt
 * @return false jeżeli błąd
 */
bool UsunObiekt(KolekcjaObiektow &K);

/**
 * @brief Wyświetla menu dronów z zaznaczonym aktywnym i pozwala na zmianę aktywnego
 * 
 * @param K kolekcja obiektów zbiornika
 * @return true jeżeli poprawnie zmieniono aktywnego drona
 * @return false jeżeli błąd
 */
bool ZmienAktywnegoDrona(KolekcjaObiektow &K);

#endif