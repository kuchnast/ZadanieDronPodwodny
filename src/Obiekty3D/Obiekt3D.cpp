#include <iostream>
#include <vector>

#include "Obiekt3D.hh"
#include "MacierzOb.hh"
#include "Wektor3D.hh"

using std::vector;

void Obiekt3D::ZmienPozycje(const Wektor3D &wektor_przesuniecia)
{
    m_srodek += wektor_przesuniecia;
}

void Obiekt3D::ZmienOrientacjeX(double kat)
{
    m_orientacja_x.Obrot(kat);
}

void Obiekt3D::ZmienOrientacjeY(double kat)
{
    m_orientacja_y.Obrot(kat);
}

void Obiekt3D::ZmienOrientacjeZ(double kat)
{
    m_orientacja_z.Obrot(kat);
}

MacierzKw<double, 3> Obiekt3D::WspolnaOrientacja() const 
{
    return m_orientacja_z * m_orientacja_y * m_orientacja_x;
}

const Wektor3D & Obiekt3D::ZwrocPozycje() const
{
    return m_srodek;
}

const vector<vector<Wektor3D>> & Obiekt3D::ZwrocWierzcholki() const
{
    return m_wierzcholki;
}

void Obiekt3D::ZmienKolor(const std::string &kolor)
{
    m_kolor = kolor;
}