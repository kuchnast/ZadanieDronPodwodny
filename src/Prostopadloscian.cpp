#include <iostream>
#include <vector>

#include "Obiekt3D.hh"
#include "Wektor3D.hh"
#include "MacierzOb.hh"
#include "Prostopadloscian.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

Prostopadloscian::Prostopadloscian(double dl_x, double dl_y, double dl_z)
{
    vector<Wektor3D> temp;
    temp.reserve(8);

    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
        {
            if(j)
                for(int k = 1; k >= 0; --k)
                    temp.push_back(Wektor3D(k ? -dl_x/2 : dl_x/2, j ? -dl_y/2 : dl_y/2, i ? -dl_z/2 : dl_z/2));
            else
                for(int k = 0; k < 2; ++k)
                    temp.push_back(Wektor3D(k ? -dl_x/2 : dl_x/2, j ? -dl_y/2 : dl_y/2, i ? -dl_z/2 : dl_z/2));
        }
            

    m_wierzcholki = temp;
}

int Prostopadloscian::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string & kolor) const
{
    vector<Point3D> t, b;

    for(int i = 0; i < 4; ++i)
    {
        t.push_back(Point3D(WspolnaOrientacja() * m_wierzcholki[i] + m_srodek));
        b.push_back(Point3D(WspolnaOrientacja() * m_wierzcholki[i + 4] + m_srodek));
    }

    return api->draw_polyhedron(vector<vector<Point3D>>{t,b}, kolor);
}