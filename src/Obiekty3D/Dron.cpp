#include <iostream>
#include <vector>

#include "Dron.hh"

using std::vector;

void Dron::Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api)
{
    if(!m_id_obiektow.empty())
        Kasuj(api);

    m_id_obiektow.push_back(m_kadlub.Rysuj(api, m_orientacja, m_srodek));
    m_id_obiektow.push_back(m_l_sruba.Rysuj(api, m_orientacja, m_srodek));
    m_id_obiektow.push_back(m_p_sruba.Rysuj(api, m_orientacja, m_srodek));
}

void Dron::Kasuj(const std::shared_ptr<drawNS::Draw3DAPI> &api)
{
    for(auto id : m_id_obiektow)
        api->erase_shape(id);

    m_id_obiektow.clear();
}

void Dron::ZmienPozycje(const Wektor3D &wektor_przesuniecia)
{
    m_srodek += wektor_przesuniecia;
}

void Dron::Obrot(double kat)
{
    m_orientacja.Obrot(kat);
}