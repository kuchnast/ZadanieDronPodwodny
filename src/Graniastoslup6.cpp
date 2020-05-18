#include <iostream>
#include <vector>
#include <math.h>

#include "Obiekt3D.hh"
#include "Wektor3D.hh"
#include "MacierzOb.hh"
#include "Graniastoslup6.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
    

Graniastoslup6::Graniastoslup6(double dl_r, double dl_z)
{   
    vector<Wektor3D> temp;
    temp.reserve(12);

    double x = cos(M_PI/6) * dl_r;
    double y = sin(M_PI/6) * dl_r;

    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
        {
            if(j){
                    temp.push_back(Wektor3D(0, -dl_r, i ? -dl_z/2 : dl_z/2));
                    temp.push_back(Wektor3D(-x, -y, i ? -dl_z/2 : dl_z/2));
                    temp.push_back(Wektor3D(-x, y, i ? -dl_z/2 : dl_z/2));
            }
            else{
                    temp.push_back(Wektor3D(0, dl_r, i ? -dl_z/2 : dl_z/2));
                    temp.push_back(Wektor3D(x, y, i ? -dl_z/2 : dl_z/2));
                    temp.push_back(Wektor3D(x, -y, i ? -dl_z/2 : dl_z/2));
            }
        }
            

    m_wierzcholki = temp;
}

vector<Point3D> Graniastoslup6::ZbudujGora() const
{
    vector<Point3D> t;

    for(int i = 0; i < 6; ++i)
        t.push_back(Point3D(WspolnaOrientacja() * m_wierzcholki[i] + m_srodek));

    return t;
}

vector<Point3D> Graniastoslup6::ZbudujDol() const
{
    vector<Point3D> b;

    for(int i = 0; i < 6; ++i)
        b.push_back(Point3D(WspolnaOrientacja() * m_wierzcholki[i + 6] + m_srodek));

    return b;
}

int Graniastoslup6::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string & kolor) const
{
   return api->draw_polyhedron(vector<vector<Point3D>>{ZbudujGora(), ZbudujDol()}, kolor);
}

int Graniastoslup6::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string & kolor, const vector<Point3D> &gora, const vector<Point3D> &dol) const
{
    return api->draw_polyhedron(vector<vector<Point3D>>{gora, dol}, kolor);
}