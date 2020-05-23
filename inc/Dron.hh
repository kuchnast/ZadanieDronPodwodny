#ifndef DRON_HH
#define DRON_HH

#include <iostream>

#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Wektor3D.hh"
#include "MacierzOb.hh"
#include "Sruba.hh"
#include "Obiekt3D.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class Dron{

protected:
    Prostopadloscian m_kadlub;
    Sruba m_p_sruba;
    Sruba m_l_sruba;

public:

    Dron() = delete;

    Dron(double rozmiar, Wektor3D srodek, const std::string & kolor = "black");

    std::array<int, 3> Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const;

    void Kasuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::array<int, 3> &obiekty);
};


#endif