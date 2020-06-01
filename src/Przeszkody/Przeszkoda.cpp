#include <iostream>
#include "Przeszkoda.hh"

void Przeszkoda::UstawWektorR(const Wektor3D &W)
{
    m_wektor_R = W;
    m_dl_R = W.dlugosc();
}

const Wektor3D &Przeszkoda::ZwrocWektorR() const
{
    return m_wektor_R;
}

double Przeszkoda::ZwrocDlR() const
{
    return m_dl_R;
}