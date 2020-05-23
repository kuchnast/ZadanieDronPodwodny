#ifndef TAFLA_HH
#define TAFLA_HH

#include <iostream>
#include <vector>

#include "Wektor3D.hh"
#include "Powierzchnia.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;

class Tafla : public Powierzchnia
{
protected:
    uint m_wysokosc_fali;

public:
    Tafla() = delete;

    Tafla(double x_min, double x_max, double y_min, double y_max, double z, double odstep = 1, uint wysokosc_fali = 0) 
        : Powierzchnia(x_min, x_max, y_min, y_max, z, odstep), m_wysokosc_fali(wysokosc_fali)
        {
            for(auto & wiersz : m_wierzcholki)
                for(uint y = 0; y < wiersz.size(); y += 2)
                    wiersz[y] = Point3D(wiersz[y][0], wiersz[y][1], wiersz[y][2] + m_wysokosc_fali);
        }
};


#endif