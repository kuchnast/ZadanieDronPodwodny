#ifndef OBIEKT_3D_HH
#define OBIEKT_3D_HH

#include <iostream>
#include <vector>

#include "Wektor3D.hh"
#include "MacierzOb.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;

class Obiekt3D
{
protected:
    MacierzOb m_orientacja_x = MacierzOb('x');
    MacierzOb m_orientacja_y = MacierzOb('y');
    MacierzOb m_orientacja_z = MacierzOb('z');
    Wektor3D m_srodek;
    vector<Wektor3D> m_wierzcholki;

public:
    Obiekt3D() = default;

    virtual int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string & kolor) const = 0;

    void ZmienPozycje(const Wektor3D &wektor_przesuniecia);

    void ZmienOrientacjeX(double kat);

    void ZmienOrientacjeY(double kat);

    void ZmienOrientacjeZ(double kat);

    MacierzKw<double, 3> WspolnaOrientacja() const;

    const Wektor3D & ZwrocPozycje() const;

    const vector<Wektor3D> & ZwrocWierzcholki() const;

    friend std::ostream & operator<<(std::ostream &Strm, const Obiekt3D &O);
};

#endif