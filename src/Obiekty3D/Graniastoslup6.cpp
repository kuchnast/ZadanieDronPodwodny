#include <iostream>
#include <vector>
#include <math.h>

#include "Graniastoslup6.hh"

using drawNS::Point3D;
using std::vector;

Graniastoslup6::Graniastoslup6(double dl_r, double dl_z, const std::string &kolor)
{
    if (dl_r <= 0 || dl_z <= 0)
        throw(std::invalid_argument("Podano nieprawidłowe długości boków graniastosłupa sześciokątnego."));

    m_kolor = kolor;
    m_wierzcholki.reserve(2);

    double x = cos(M_PI / 6) * dl_r;
    double y = sin(M_PI / 6) * dl_r;

    for (int i = 0; i < 2; ++i){
        vector<Wektor3D> temp;
        temp.reserve(6);
        for (int j = 0; j < 2; ++j)
        {
            if (j)
            {
                temp.push_back(Wektor3D(0, -dl_r, i ? -dl_z / 2 : dl_z / 2));
                temp.push_back(Wektor3D(-x, -y, i ? -dl_z / 2 : dl_z / 2));
                temp.push_back(Wektor3D(-x, y, i ? -dl_z / 2 : dl_z / 2));
            }
            else
            {
                temp.push_back(Wektor3D(0, dl_r, i ? -dl_z / 2 : dl_z / 2));
                temp.push_back(Wektor3D(x, y, i ? -dl_z / 2 : dl_z / 2));
                temp.push_back(Wektor3D(x, -y, i ? -dl_z / 2 : dl_z / 2));
            }
        }
        m_wierzcholki.push_back(temp);
    }
}

vector<vector<Point3D>> Graniastoslup6::_Zbuduj() const
{
    vector<vector<Point3D>> nowe_wierzcholki;
    nowe_wierzcholki.reserve(m_wierzcholki.size());

    for (const auto &tab : m_wierzcholki)
    {
        vector<Point3D> temp;
        temp.reserve(tab.size());

        for (const auto &wektor : tab)
            temp.push_back(Point3D(WspolnaOrientacja() * wektor + m_srodek));

        nowe_wierzcholki.push_back(temp);
    }

    return nowe_wierzcholki;
}

vector<vector<Point3D>> Graniastoslup6::_Zbuduj(const MacierzOb &orientacja, const Wektor3D &srodek) const
{
    vector<vector<Point3D>> nowe_wierzcholki;
    nowe_wierzcholki.reserve(m_wierzcholki.size());

    for (const auto &tab : m_wierzcholki)
    {
        vector<Point3D> temp;
        temp.reserve(tab.size());

        for (const auto &wektor : tab)
            temp.push_back(Point3D(orientacja * (WspolnaOrientacja() * wektor + m_srodek) + srodek));

        nowe_wierzcholki.push_back(temp);
    }

    return nowe_wierzcholki;
}

int Graniastoslup6::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const
{
    return api->draw_polyhedron(_Zbuduj(), m_kolor);
}

int Graniastoslup6::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const MacierzOb &orientacja, const Wektor3D &srodek) const
{
    return api->draw_polyhedron(_Zbuduj(orientacja, srodek), m_kolor);
}