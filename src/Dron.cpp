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

Dron::Dron(double rozmiar, Wektor3D srodek, const std::string & kolor)
{
    if(rozmiar <= 0)
        throw(std::invalid_argument("Podano błędny rozmiar drona."));

    m_kadlub = Prostopadloscian(rozmiar * 2, rozmiar * 2, rozmiar);
    m_p_sruba = Sruba(rozmiar / 2, rozmiar / 4);
    m_l_sruba = Sruba(rozmiar / 2, rozmiar / 4);

    m_p_sruba.ZmienPozycje(Wektor3D(rozmiar / 2, -1.125 * rozmiar, 0));
    m_l_sruba.ZmienPozycje(Wektor3D(-rozmiar / 2, -1.125 * rozmiar, 0));

    m_kolor = kolor;
}

std::array<int, 3> Dron::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const
{
    std::array<int, 3> indeksy;

    indeksy[0] = m_kadlub.Rysuj(api, m_kolor);
    indeksy[1] = m_l_sruba.Rysuj(api, m_kolor);
    indeksy[2] = m_p_sruba.Rysuj(api, m_kolor);

    return indeksy;
}

void Dron::Kasuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::array<int, 3> &obiekty)
{
    for(auto nr : obiekty)
        api->erase_shape(nr);
}

 void Dron::ZmienPozycje(const Wektor3D &wektor_przesuniecia)
 {
    m_kadlub.ZmienPozycje(wektor_przesuniecia);
    m_l_sruba.ZmienPozycje(wektor_przesuniecia);
    m_p_sruba.ZmienPozycje(wektor_przesuniecia);
 }

void Dron::Obrot(double kat)
{
    m_kadlub.ZmienOrientacjeZ(kat);
    m_l_sruba.ZmienOrientacjeZ(kat);
    m_p_sruba.ZmienOrientacjeZ(kat);
}

void Dron::AnimujRuchWPrzod(double odleglosc, const std::shared_ptr<drawNS::Draw3DAPI> &api)
{
    std::array<int, 3> obiekty;

    if(odleglosc <= 0)
        throw(std::invalid_argument("Podano błędną wartość odległości."));

    Wektor3D przemieszczenie = m_kadlub.WspolnaOrientacja() * Wektor3D(0, odleglosc, 0);

    for(double i = 0; i < odleglosc; i += odleglosc/1000)
    {
        ZmienPozycje(przemieszczenie/1000);
        obiekty = Rysuj(api);
        api->redraw();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
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
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        Kasuj(api, obiekty);
        m_l_sruba.ObrotSrubyPrawo();
        m_p_sruba.ObrotSrubyLewo();
    }

}