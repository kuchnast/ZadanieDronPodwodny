#include "Przeszkoda.hh"

const Wektor3D &Przeszkoda::ZwrocWektorR() const
{
    return m_wektor_R;
}

double Przeszkoda::ZwrocDlugoscR() const
{
    return m_dl_R;
}

void Przeszkoda::UstawWektorR(const Wektor3D &W)
{
    m_wektor_R = W, m_dl_R = W.dlugosc();
}
