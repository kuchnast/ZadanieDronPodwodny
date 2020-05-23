#ifndef INTERFEJS_DRONA_HH
#define INTERFEJS_DRONA_HH

#include <iostream>

#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Wektor3D.hh"
#include "MacierzOb.hh"
#include "Sruba.hh"
#include "Obiekt3D.hh"
#include "Dron.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class InterfejsDrona : public Dron
{
protected:
    Wektor3D m_srodek;
    MacierzOb m_orientacja = MacierzOb('z');

    std::string m_kolor_dron, m_kolor_sruby;
public:

    InterfejsDrona() = delete;

    InterfejsDrona(double rozmiar, Wektor3D srodek, const std::string & kolor = "black");

    std::array<int, 3> Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const;

    void Kasuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::array<int, 3> &obiekty);

    void ZmienPozycje(const Wektor3D &wektor_przesuniecia);

    void Obrot(double kat);

    void AnimujRuchWPrzod(double odleglosc, const std::shared_ptr<drawNS::Draw3DAPI> &api);

    void AnimujObrot(double kat, const std::shared_ptr<drawNS::Draw3DAPI> &api);


};




#endif