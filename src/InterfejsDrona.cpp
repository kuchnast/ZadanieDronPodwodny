#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>

#include "Obiekt3D.hh"
#include "Wektor3D.hh"
#include "MacierzOb.hh"
#include "Graniastoslup6.hh"
#include "Sruba.hh"
#include "Dron.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

Dron::Dron(double rozmiar, Wektor3D polozenie, const std::string & kolor)
{
    if(rozmiar <= 0)
        throw(std::invalid_argument("Podano błędny rozmiar drona."));

    m_kadlub = Prostopadloscian(rozmiar * 2, rozmiar * 2, rozmiar);
    m_p_sruba = Sruba(rozmiar / 2, rozmiar / 4);
    m_l_sruba = Sruba(rozmiar / 2, rozmiar / 4);

    m_p_sruba.ZmienPozycje(Wektor3D(rozmiar / 2, -1.125 * rozmiar, 0));
    m_l_sruba.ZmienPozycje(Wektor3D(-rozmiar / 2, -1.125 * rozmiar, 0));

    m_kolor = kolor;
    m_srodek = polozenie;
}

std::array<int, 3> Dron::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const
{
    std::array<int, 3> indeksy;
    std::vector<Point3D> temp_dol, temp_gora;

    temp_dol = m_kadlub.ZbudujDol();
    for(auto & punkt : temp_dol)
        punkt = Point3D(m_orientacja * Wektor3D(punkt[0], punkt[1], punkt[2]) + m_srodek);

    temp_gora = m_kadlub.ZbudujGora();
    for(auto & punkt : temp_gora)
        punkt = Point3D(m_orientacja * Wektor3D(punkt[0], punkt[1], punkt[2]) + m_srodek);

    indeksy[0] = m_kadlub.Rysuj(api, m_kolor, temp_gora, temp_dol);

    temp_dol = m_l_sruba.ZbudujDol();
    for(auto & punkt : temp_dol)
        punkt = Point3D(m_orientacja * Wektor3D(punkt[0], punkt[1], punkt[2]) + m_srodek);

    temp_gora = m_l_sruba.ZbudujGora();
    for(auto & punkt : temp_gora)
        punkt = Point3D(m_orientacja * Wektor3D(punkt[0], punkt[1], punkt[2]) + m_srodek);

    indeksy[1] = m_l_sruba.Rysuj(api, m_kolor, temp_gora, temp_dol);
    
    temp_dol = m_p_sruba.ZbudujDol();
    for(auto & punkt : temp_dol)
        punkt = Point3D(m_orientacja * Wektor3D(punkt[0], punkt[1], punkt[2]) + m_srodek);

    temp_gora = m_p_sruba.ZbudujGora();
    for(auto & punkt : temp_gora)
        punkt = Point3D(m_orientacja * Wektor3D(punkt[0], punkt[1], punkt[2]) + m_srodek);

    indeksy[2] = m_p_sruba.Rysuj(api, m_kolor, temp_gora, temp_dol);

    return indeksy;
}

void Dron::Kasuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::array<int, 3> &obiekty)
{
    for(auto nr : obiekty)
        api->erase_shape(nr);
}

 void Dron::ZmienPozycje(const Wektor3D &wektor_przesuniecia)
 {
    m_srodek += wektor_przesuniecia;
 }

void Dron::Obrot(double kat)
{
    m_orientacja.Obrot(kat);
}

void Dron::AnimujRuchWPrzod(double odleglosc, const std::shared_ptr<drawNS::Draw3DAPI> &api)
{
    std::array<int, 3> obiekty;

    if(odleglosc <= 0)
        throw(std::invalid_argument("Podano błędną wartość odległości."));

    Wektor3D przemieszczenie = m_orientacja * Wektor3D(0, odleglosc, 0);

    for(double i = 0; i < odleglosc; i += odleglosc/1000)
    {
        ZmienPozycje(przemieszczenie/1000);
        obiekty = Rysuj(api);
        api->redraw();
        std::this_thread::sleep_for(std::chrono::nanoseconds(100));
        Kasuj(api, obiekty);
        m_l_sruba.ObrotSrubyPrawo();
        m_p_sruba.ObrotSrubyLewo();
    }

}

void Dron::AnimujObrot(double kat, const std::shared_ptr<drawNS::Draw3DAPI> &api)
{
    std::array<int, 3> obiekty;

    if(abs(kat) <= 0.00001)
        throw(std::invalid_argument("Podano błędną wartość kąta."));

    for(double i = 0; i < 1000; ++i)
    {
        Obrot(kat/1000);
        obiekty = Rysuj(api);
        api->redraw();
        std::this_thread::sleep_for(std::chrono::nanoseconds(100));
        Kasuj(api, obiekty);
        m_l_sruba.ObrotSrubyPrawo();
        m_p_sruba.ObrotSrubyLewo();
    }

}