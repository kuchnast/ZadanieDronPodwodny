#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>

#include "InterfejsDrona.hh"

using drawNS::Point3D;
using std::vector;

void InterfejsDrona::UstawCzasAnimacji(uint czas_animacji)
{
    m_czas_animacji = czas_animacji;
}

void InterfejsDrona::AnimujRuchWPrzod(const std::shared_ptr<drawNS::Draw3DAPI> &api, double odleglosc)
{
    if (abs(odleglosc) < 0.00001)
        throw(std::invalid_argument("Podano błędną wartość odległości."));

    if (odleglosc < 0)
    {
        AnimujObrot(api, 180);
        odleglosc = -odleglosc;
    }

    Wektor3D przemieszczenie = m_orientacja * Wektor3D(0, odleglosc, 0);

    for (int i = 0; i < 100; ++i)
    {
        ZmienPozycje(przemieszczenie / 100);
        m_l_sruba.ObrotSrubyPrawo(5);
        m_p_sruba.ObrotSrubyLewo(5);
        Rysuj(api);
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        api->redraw();
    }
}

void InterfejsDrona::AnimujObrot(const std::shared_ptr<drawNS::Draw3DAPI> &api, double kat)
{
    if (abs(kat) < 0.00001)
        throw(std::invalid_argument("Podano błędną wartość kąta."));

    for (int i = 0; i < 100; ++i)
    {
        Obrot(kat / 100);
        if (kat > 0)
        {
            m_l_sruba.ObrotSrubyPrawo(5);
            m_p_sruba.ObrotSrubyPrawo(5);
        }
        else
        {
            m_l_sruba.ObrotSrubyLewo(5);
            m_p_sruba.ObrotSrubyLewo(5);
        }
        Rysuj(api);
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        api->redraw();
    }
}

void InterfejsDrona::AnimujRuchWPionie(const std::shared_ptr<drawNS::Draw3DAPI> &api, double wysokosc)
{
    if (abs(wysokosc) < 0.00001)
        throw(std::invalid_argument("Podano błędną wartość wysokości."));

    Wektor3D przemieszczenie = Wektor3D(0, 0, wysokosc);

    for (int i = 0; i < 100; ++i)
    {
        ZmienPozycje(przemieszczenie / 100);
        Rysuj(api);
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        api->redraw();
    }
}