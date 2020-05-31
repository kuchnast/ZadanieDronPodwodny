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

void InterfejsDrona::AnimujRuchWPrzod(double odleglosc)
{
    if (abs(odleglosc) < 0.00001)
        throw(std::invalid_argument("Podano błędną wartość odległości."));

    if (odleglosc < 0)
    {
        AnimujObrot(180);
        odleglosc = -odleglosc;
    }

    Wektor3D przemieszczenie = m_orientacja_z * Wektor3D(0, odleglosc, 0);

    for (int i = 0; i < 100; ++i)
    {
        ZmienPozycje(przemieszczenie / 100);
        m_l_sruba.ObrotSrubyPrawo(5);
        m_p_sruba.ObrotSrubyLewo(5);
        Rysuj();
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        m_api->redraw();
    }
}

void InterfejsDrona::AnimujObrot(double kat)
{
    if (abs(kat) < 0.00001)
        throw(std::invalid_argument("Podano błędną wartość kąta."));

    for (int i = 0; i < 100; ++i)
    {
        ZmienOrientacjeZ(kat / 100);
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
        Rysuj();
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        m_api->redraw();
    }
}

void InterfejsDrona::AnimujRuchWPionie(double odleglosc, double kat)
{
    if (abs(odleglosc) < 0.00001)
        throw(std::invalid_argument("Podano błędną wartość wysokości."));

    if (abs(kat) < 0.00001 || abs(kat) >= 90)
        throw(std::invalid_argument("Podano błędną wartość kąta."));

    if (odleglosc < 0)
    {
        AnimujObrot(180);
        odleglosc = -odleglosc;
    }

    Wektor3D przemieszczenie_pion = Wektor3D(0, 0, sin(kat * M_PI / 180) * odleglosc);
    Wektor3D przemieszczenie_poziom = m_orientacja_z * Wektor3D(0, cos(kat * M_PI / 180) * odleglosc, 0);

    for (int i = 0; i < 100; ++i)
    {
        ZmienPozycje(przemieszczenie_poziom / 100 + przemieszczenie_pion / 100);
        m_l_sruba.ObrotSrubyPrawo(5);
        m_p_sruba.ObrotSrubyLewo(5);
        if(i < 50)
            ZmienOrientacjeX(kat / 50);
        else
            ZmienOrientacjeX(-kat / 50);

        Rysuj();
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        m_api->redraw();
    }
}