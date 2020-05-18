#ifndef SRUBA_HH
#define SRUBA_HH

#include <iostream>
#include <vector>

#include "Obiekt3D.hh"
#include "Wektor3D.hh"
#include "Graniastoslup6.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Sruba : public Graniastoslup6
{
protected:

public:
    Sruba() : Graniastoslup6(){m_orientacja_x.Obrot(90);}

    Sruba(double dl_r, double dl_z) : Graniastoslup6(dl_r, dl_z){ m_orientacja_x.Obrot(90);}

    void ObrotSrubyLewo(double kat = 1);

    void ObrotSrubyPrawo(double kat = 1);

};

#endif