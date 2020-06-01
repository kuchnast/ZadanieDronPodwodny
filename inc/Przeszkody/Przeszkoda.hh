#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
#include "Wektor3D.hh"

class Przeszkoda
{
private:
    Wektor3D m_wektor_R;
    double m_dl_R;

public:
    Przeszkoda() : m_wektor_R(0, 0, 0), m_dl_R(0) {}

    Przeszkoda(const Wektor3D &W) : m_wektor_R(W), m_dl_R(W.dlugosc()) {}

    void UstawWektorR(const Wektor3D &W);

    const Wektor3D &ZwrocWektorR() const;

    double ZwrocDlR() const;
};

#endif