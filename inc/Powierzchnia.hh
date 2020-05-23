#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include <iostream>
#include <vector>

#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;

class Powierzchnia
{
protected:
    vector<vector<Point3D>> m_wierzcholki;

public:
    Powierzchnia() = delete;

    Powierzchnia(double x_min, double x_max, double y_min, double y_max, double z, double odstep = 1);

    int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string & kolor) const;

    friend std::ostream & operator<<(std::ostream &Strm, const Powierzchnia &P);

};


#endif