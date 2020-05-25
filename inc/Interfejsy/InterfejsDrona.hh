#ifndef INTERFEJS_DRONA_HH
#define INTERFEJS_DRONA_HH

#include <iostream>

#include "Dron.hh"

/**
 * @brief Klasa modeluje pojęcie interfejsu pozwalającego na obsługę obiektu drona
 * 
 */
class InterfejsDrona : public Dron
{
protected:
    uint m_czas_animacji; ///< Czas trwania dowolnej animacji w milisekundach

public:

/**
 * @brief Usunięty domyślny konstruktor bezparametryczny nowego obiektu klasy Interfejs Drona 
 * 
 */
    InterfejsDrona() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy Dron 
 * 
 * @param rozmiar wysokość drona będąca jednocześnie przelicznikiem kolejnych długości boków i śrub
 * @param srodek wektor położenia środka obiektu
 * @param kolor_kadluba nazwa koloru kadłuba drona
 * @param kolor_srub nazwa koloru śrub drona
 * @param czas_animacji czas trwania animacji dowolnego ruchu w milisekundach
 */
    InterfejsDrona(double rozmiar, const Wektor3D &srodek = Wektor3D(), const std::string &kolor_kadluba = "black", const std::string &kolor_srub = "black", uint czas_animacji = 2000) : Dron(rozmiar, srodek, kolor_kadluba, kolor_srub), m_czas_animacji(czas_animacji){}

/**
 * @brief Ustawia łączny czas animacji w milisekundach
 * 
 * @param czas_animacji czas animacji w milisekundach
 */
    void UstawCzasAnimacji(uint czas_animacji);

/**
 * @brief Animacja ruchu do przodu na zadaną odległość
 * Podczas animacji ruchu, animowany jest również obrót śrub drona.
 * Gdy podana zostanie ujemna wartość odległości, dron obróci się o 180 stopni i dopiero wykona ruch
 * 
 * @exception std::invalid_argument podano nieprawidłową wartość odległości
 * 
 * @param api łącze do gnuplota
 * @param odleglosc odległość na jaką dokonywane jest przemieszczenie
 */
    void AnimujRuchWPrzod(const std::shared_ptr<drawNS::Draw3DAPI> &api, double odleglosc);

/**
 * @brief Animacja obrotu o zadany kąt
 * Podczas animacji ruchu, animowany jest również obrót śrub drona.
 * 
 * @exception std::invalid_argument podano nieprawidłową wartość kąta
 * 
 * @param api łącze do gnuplota
 * @param kat kąt obrotu w stopniach
 */
    void AnimujObrot(const std::shared_ptr<drawNS::Draw3DAPI> &api, double kat);

/**
 * @brief Animuje wznoszenie się lub opadanie drona
 * 
 * @exception std::invalid_argument podano nieprawidłową wartość wysokości
 * 
 * @param api łącze do gnuplota
 * @param wysokosc wysokość o jaką zmieni się położenie drona
 */
    void AnimujRuchWPionie(const std::shared_ptr<drawNS::Draw3DAPI> &api, double wysokosc);


    void AnimujRuchWPionieIWPrzod(const std::shared_ptr<drawNS::Draw3DAPI> &api, double wysokosc, double odleglosc);
};

#endif