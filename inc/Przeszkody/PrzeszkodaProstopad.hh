#ifndef PRZESZKODA_PROSTOPAD_HH
#define PRZESZKODA_PROSTOPAD_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"

/**
 * @brief Klasa modeluje pojęcie przeszkody prostopadłościennej
 * 
 */
class PrzeszkodaProstopad : public Przeszkoda, public Prostopadloscian
{
public:

/**
 * @brief Konstruktor nowego obiektu klasy PrzeszkodaProstopad
 * 
 * @param dl_x długość prostopadłościanu
 * @param dl_y szerokość prostopadłościanu
 * @param dl_z wysokość prostopadłościanu
 * @param api łącze do gnuplota
 * @param srodek środek położenia obiektu
 * @param kolor nazwa koloru obiektu
 */
    PrzeszkodaProstopad(double dl_x, double dl_y, double dl_z, const std::shared_ptr<drawNS::Draw3DAPI> &api, const Wektor3D &srodek = Wektor3D(0, 0, 0), const std::string &kolor = "black") : Przeszkoda(Wektor3D(dl_x / 2, dl_y / 2, dl_z / 2)), Prostopadloscian(dl_x, dl_y, dl_z, api, kolor)
    {
        ZmienPozycje(srodek);
    }

/**
 * @brief Sprawdza czy nastąpiłą kolizja obiektu z dronem
 * 
 * @param Ob obiekt drona
 * @return true jeżeli jest kolizja
 * @return false jeżeli brak kolizji
 */
    bool CzyKolizja(const Dron &Ob) const override;

/**
 * @brief Rysuje przeszkodę
 * 
 */
    void RysujPrzeszkode() override;

/**
 * @brief Kasuje przeszkodę
 * 
 */
    void KasujPrzeszkode() override;
};



#endif