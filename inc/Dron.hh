#ifndef DRON_HH
#define DRON_HH

#include <iostream>

#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Wektor3D.hh"
#include "Sruba.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class Dron {

protected:
    Prostopadloscian m_kadlub;
    Sruba m_p_sruba;
    Sruba m_l_sruba;
    std::string m_kolor;

public:

    Dron() = delete;

    Dron(double rozmiar, Wektor3D srodek, const std::string & kolor = "black");

    std::array<int, 3> Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const;

    void Kasuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::array<int, 3> &obiekty);

    void ZmienPozycje(const Wektor3D &wektor_przesuniecia);

    void Obrot(double kat);

    void AnimujRuchWPrzod(double odleglosc, const std::shared_ptr<drawNS::Draw3DAPI> &api);

    void AnimujObrot(double kat, const std::shared_ptr<drawNS::Draw3DAPI> &api);

};


#endif