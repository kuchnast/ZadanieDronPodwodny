#ifndef PRZESZKODA_PROSTOPAD_HH
#define PRZESZKODA_PROSTOPAD_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"

class PrzeszkodaProstopad : public Przeszkoda, public Prostopadloscian
{
//protected:
    //Prostopadloscian obiekt;

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
    PrzeszkodaProstopad(double dl_x, double dl_y, double dl_z, const std::shared_ptr<drawNS::Draw3DAPI> &api, const Wektor3D &srodek = Wektor3D(0, 0, 0), const std::string &kolor = "black") : Przeszkoda(Wektor3D(dl_x, dl_y, dl_z)), Prostopadloscian(dl_x, dl_y, dl_z, api, kolor)
    {
        ZmienPozycje(srodek);
    }

    bool CzyKolizja(const Dron &Ob) const override;

    void RysujPrzeszkode() override;

    void KasujPrzeszkode() override;
};



#endif