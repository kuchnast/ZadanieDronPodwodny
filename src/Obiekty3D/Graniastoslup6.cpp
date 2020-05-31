#include <iostream>
#include <vector>
#include <math.h>

#include "Graniastoslup6.hh"

using drawNS::Point3D;
using std::vector;

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

void Graniastoslup6::Rysuj()
{
    if (m_id_obiektu != nullptr)
        Kasuj();

    m_id_obiektu = new int;
    *m_id_obiektu = m_api->draw_polyhedron(_Zbuduj(), m_kolor);
}

void Graniastoslup6::Kasuj()
{
    if (m_id_obiektu != nullptr)
    {
        m_api->erase_shape(*m_id_obiektu);
        delete m_id_obiektu;
        m_id_obiektu = nullptr;
    }
}

void Graniastoslup6::Rysuj(const MacierzOb &orientacja, const Wektor3D &srodek)
{
    if (m_id_obiektu != nullptr)
        Kasuj();

    m_id_obiektu = new int;
    *m_id_obiektu = m_api->draw_polyhedron(_Zbuduj(orientacja, srodek), m_kolor);
}