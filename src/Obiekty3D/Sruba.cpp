#include <iostream>

#include "Sruba.hh"

void Sruba::ObrotSrubyLewo(double kat)
{
    m_orientacja_y.Obrot(-kat);
}

void Sruba::ObrotSrubyPrawo(double kat)
{
    m_orientacja_y.Obrot(kat);
}