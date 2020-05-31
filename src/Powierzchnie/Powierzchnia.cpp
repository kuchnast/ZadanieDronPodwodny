#include <iostream>
#include <vector>
#include <math.h>

#include "Powierzchnia.hh"

using std::vector;
using drawNS::Point3D;

vector<vector<Point3D>> Powierzchnia::_Zbuduj() const
{
    vector<vector<Point3D>> nowe_wierzcholki;
    nowe_wierzcholki.reserve(m_wierzcholki.size());

    for (const auto &tab : m_wierzcholki)
    {
        vector<Point3D> temp;
        temp.reserve(tab.size());

        for (const auto &wektor : tab)
            temp.push_back(Point3D(WspolnaOrientacja() * wektor));

        nowe_wierzcholki.push_back(temp);
    }

    return nowe_wierzcholki;
}

void Powierzchnia::Rysuj()
{
    if (m_id_obiektu != nullptr)
        Kasuj();

    m_id_obiektu = new int;
    *m_id_obiektu = m_api->draw_polyhedron(_Zbuduj(), m_kolor);
}

void Powierzchnia::Kasuj()
{
    if (m_id_obiektu != nullptr)
    {
        m_api->erase_shape(*m_id_obiektu);
        delete m_id_obiektu;
    }
}