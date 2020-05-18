#include <iostream>
#include <vector>
#include <math.h>

#include "Obiekt3D.hh"
#include "Wektor3D.hh"
#include "MacierzOb.hh"
#include "Graniastoslup6.hh"
#include "Sruba.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Sruba::ObrotSrubyLewo(double kat)
{
    m_orientacja_y.Obrot(-kat);
}

void Sruba::ObrotSrubyPrawo(double kat)
{
    m_orientacja_y.Obrot(kat);
}