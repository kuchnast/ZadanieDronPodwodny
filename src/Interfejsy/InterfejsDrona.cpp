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

bool InterfejsDrona::AnimujRuchWPrzod(const std::map<std::string, std::shared_ptr<Przeszkoda>> &lista_przeszkod, double odleglosc)
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
        for (const auto & P : lista_przeszkod)
        {
            if(P.second->CzyKolizja(*this))
            {
                ZmienPozycje(-przemieszczenie / 100);
                std::cout << "Kolizja z obiektem " << P.first << ".\n";
                return true;
            }
        }
        m_l_sruba.ObrotSrubyPrawo(5);
        m_p_sruba.ObrotSrubyLewo(5);
        Rysuj();
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        m_api->redraw();
    }

    return false;
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

bool InterfejsDrona::AnimujRuchWPionie(const std::map<std::string, std::shared_ptr<Przeszkoda>> &lista_przeszkod, double odleglosc, double kat)
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
    bool czy_blad = false;

    for (int i = 0; i < 50; ++i)
    {
        ZmienOrientacjeX(kat / 50);
        for (const auto &P : lista_przeszkod)
        {
            if (P.second->CzyKolizja(*this))
            {
                for (int j = 0; j <= i; ++j)
                {
                    ZmienOrientacjeX(-kat / 50);
                    m_l_sruba.ObrotSrubyPrawo(5);
                    m_p_sruba.ObrotSrubyLewo(5);
                    Rysuj();
                    std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
                    m_api->redraw();
                }
                std::cout << "Kolizja z obiektem " << P.first << ".\n";
                return true;
            }
        }
        m_l_sruba.ObrotSrubyPrawo(5);
        m_p_sruba.ObrotSrubyLewo(5);
        Rysuj();
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        m_api->redraw();
    }

    for (int i = 0; i < 100; ++i)
    {
        ZmienPozycje(przemieszczenie_poziom / 100 + przemieszczenie_pion / 100);
        for (const auto &P : lista_przeszkod)
        {
            if (P.second->CzyKolizja(*this))
            {
                ZmienPozycje(-(przemieszczenie_poziom / 100 + przemieszczenie_pion / 100));
                std::cout << "Kolizja z obiektem " << P.first << ".\n";
                czy_blad = true;
                break;
            }
        }
        if(czy_blad)
            break;
        m_l_sruba.ObrotSrubyPrawo(5);
        m_p_sruba.ObrotSrubyLewo(5);
        Rysuj();
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        m_api->redraw();
    }

    for (int i = 0; i < 50; ++i)
    {
        ZmienOrientacjeX(-kat / 50);
        m_l_sruba.ObrotSrubyPrawo(5);
        m_p_sruba.ObrotSrubyLewo(5);
        Rysuj();
        std::this_thread::sleep_for(std::chrono::microseconds(m_czas_animacji * 10));
        m_api->redraw();
    }

    return czy_blad;
}