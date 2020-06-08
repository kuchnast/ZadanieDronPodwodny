#include <iostream>

#include "Wektor3D.hh"

int Wektor3D::m_l_wektorow = 0;

Wektor3D::Wektor3D(const Wektor3D &W)
{
    m_tab[0] = W[0];
    m_tab[1] = W[1];
    m_tab[2] = W[2];
    ++m_l_wektorow;
}

Wektor3D::Wektor3D(double l1, double l2, double l3)
{
    m_tab[0] = l1;
    m_tab[1] = l2;
    m_tab[2] = l3;
    ++m_l_wektorow;
}

Wektor3D::~Wektor3D()
{
    --m_l_wektorow;
}

int Wektor3D::ZwrocLiczbeWektorow()
{
    return m_l_wektorow;
}