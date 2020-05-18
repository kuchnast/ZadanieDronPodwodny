#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include <vector>

#include "Obiekt3D.hh"
#include "Wektor3D.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Prostopadloscian : public Obiekt3D
{

protected:
    
    

public:
    Prostopadloscian() : Prostopadloscian(2, 2, 2) {}

    Prostopadloscian(double dl_x, double dl_y, double dl_z);

    int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string & kolor) const override;
};



#endif