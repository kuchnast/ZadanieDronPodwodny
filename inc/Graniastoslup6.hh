#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#include <iostream>
#include <vector>

#include "Obiekt3D.hh"
#include "Wektor3D.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Graniastoslup6 : public Obiekt3D
{

protected:
    
    

public:
    Graniastoslup6() : Graniastoslup6(1, 1) {}

    Graniastoslup6(double dl_r, double dl_z);

    int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string & kolor) const override;
};



#endif