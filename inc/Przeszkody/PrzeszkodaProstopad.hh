#ifndef PRZESZKODA_PROSTOPAD_HH
#define PRZESZKODA_PROSTOPAD_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Prostopadloscian.hh"
#include "DetekcjaKolizji.hh"
#include "Przeszkoda.hh"

class PrzeszkodaProstopad : public Prostopadloscian, public DetekcjaKolizji, public Przeszkoda
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
    PrzeszkodaProstopad(double dl_x, double dl_y, double dl_z, const std::shared_ptr<drawNS::Draw3DAPI> &api, const Wektor3D & srodek = Wektor3D(0, 0, 0), const std::string &kolor = "black") : Prostopadloscian(dl_x, dl_y, dl_z, api, kolor) , Przeszkoda(Wektor3D(dl_x/2, dl_y/2, dl_z/2))
    {
        m_srodek = srodek;
    }

    bool CzyKolizja(const Dron &Ob) const override;
};



#endif