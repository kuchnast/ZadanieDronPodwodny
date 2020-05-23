#include <iostream>
#include <vector>
#include <math.h>

#include "Wektor3D.hh"
#include "Powierzchnia.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;

Powierzchnia::Powierzchnia(double x_min, double x_max, double y_min, double y_max, double z, double odstep)
{
    if(x_min > x_max || y_min > y_max || odstep <= 0)
        throw(std::invalid_argument("Nieprawidłowe parametry tworzenia powierzchni."));

    int liczba_x = ((x_max -x_min) / odstep) + 1, liczba_y = ((y_max - y_min) / odstep) + 1;

    m_wierzcholki.reserve(liczba_x);
    for(int i = 0; i < liczba_x; ++i)
        m_wierzcholki[i].reserve(liczba_y);

    for(int x = 0; x < liczba_x; ++x)
    {
        vector<Point3D> temp;
        temp.reserve(liczba_y);

        for(int y = 0; y < liczba_y; ++y)
            temp.push_back(Point3D(x_min + x * odstep, y_min + y * odstep, z));

        m_wierzcholki.push_back(temp);
    }
}

int Powierzchnia::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string & kolor) const
{
    return api->draw_surface(m_wierzcholki, kolor);
}

std::ostream & operator<<(std::ostream &Strm, const Powierzchnia &P)
{
     Strm << "===Powierzchnia===\n" <<
    "Wierzchołki:\n";
    for(uint i = 0; i < P.m_wierzcholki.size(); ++i)
    {
        Strm << "Wiersz["<< i <<"]\n";
        for(uint j = 0; j < P.m_wierzcholki[i].size(); ++j)
        {
            Strm << Wektor3D(P.m_wierzcholki[i][j]) << " ";
        }
        Strm << std::endl;
    }
    Strm << "=!=Powierzchnia=!=\n";

    return Strm;
}