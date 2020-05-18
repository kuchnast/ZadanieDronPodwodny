#include <iostream>
#include <vector>

#include "Obiekt3D.hh"
#include "MacierzOb.hh"
#include "Wektor3D.hh"


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

std::ostream & operator<<(std::ostream &Strm, const Obiekt3D &O)
{
    Strm << "===Obiekt3D===\n" <<
    "Macierz orientacji x:\n" << O.m_orientacja_x <<
    "Macierz orientacji y:\n" << O.m_orientacja_y <<
    "Macierz orientacji z:\n" << O.m_orientacja_z <<
    "Środek: " << O.m_srodek << std::endl <<
    "Wierzchołki:\n";
    for(unsigned int i = 0; i < O.m_wierzcholki.size(); ++i)
        Strm << "(" << O.m_wierzcholki[i] << ")\n";
    Strm << "=!=Obiekt3D=!=\n";

    return Strm;
}