#include <iostream>
#include <vector>

#include "Prostopadloscian.hh"

using drawNS::Point3D;
using std::vector;

Prostopadloscian::Prostopadloscian(double dl_x, double dl_y, double dl_z, const std::string &kolor)
{
    if(dl_x <= 0 || dl_y <= 0 || dl_z <= 0)
        throw(std::invalid_argument("Podano nieprawidłowe długości boków prostopadłościanu."));

    m_kolor = kolor;
    m_wierzcholki.reserve(2);

    for (int i = 0; i < 2; ++i)
    {
        vector<Wektor3D> temp;
        temp.reserve(4);

        for (int j = 0; j < 2; ++j)
        {
            if (j)
                for (int k = 1; k >= 0; --k)
                    temp.push_back(Wektor3D(k ? -dl_x / 2 : dl_x / 2, j ? -dl_y / 2 : dl_y / 2, i ? -dl_z / 2 : dl_z / 2));
            else
                for (int k = 0; k < 2; ++k)
                    temp.push_back(Wektor3D(k ? -dl_x / 2 : dl_x / 2, j ? -dl_y / 2 : dl_y / 2, i ? -dl_z / 2 : dl_z / 2));
        }
        m_wierzcholki.push_back(temp);
    }
}

vector<vector<Point3D>> Prostopadloscian::_Zbuduj() const
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

vector<vector<Point3D>> Prostopadloscian::_Zbuduj(const MacierzOb &orientacja, const Wektor3D &srodek) const
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

int Prostopadloscian::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const
{
    return api->draw_polyhedron(_Zbuduj(), m_kolor);
}

int Prostopadloscian::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const MacierzOb &orientacja, const Wektor3D &srodek) const
{
    return api->draw_polyhedron(_Zbuduj(orientacja, srodek), m_kolor);
}