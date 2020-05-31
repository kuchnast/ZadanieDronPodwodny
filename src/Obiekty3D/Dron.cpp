#include <iostream>
#include <vector>

#include "Dron.hh"

using std::vector;

void Dron::Rysuj()
{
    if (*m_id_obiektu != 0)
        Kasuj();

    *m_id_obiektu = 1;
    m_kadlub.Rysuj(MacierzOb(WspolnaOrientacja()), m_srodek);
    m_l_sruba.Rysuj(MacierzOb(WspolnaOrientacja()), m_srodek);
    m_p_sruba.Rysuj(MacierzOb(WspolnaOrientacja()), m_srodek);
}

void Dron::Kasuj()
{
    if (*m_id_obiektu != 0)
    {
        m_kadlub.Kasuj();
        m_l_sruba.Kasuj();
        m_p_sruba.Kasuj();
        *m_id_obiektu = 0;
    }
}