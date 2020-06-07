#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>

#include "Wektor3D.hh"

class Dron;

class Przeszkoda
{
private:
    Wektor3D m_wektor_R;
    double m_dl_R;

public:
    Przeszkoda() = delete;

    Przeszkoda(Wektor3D wektor_R) : m_wektor_R(wektor_R), m_dl_R(wektor_R.dlugosc()) {}

    const Wektor3D &ZwrocWektorR() const;

    double ZwrocDlugoscR() const;

    void UstawWektorR(const Wektor3D &W);
    
    virtual bool CzyKolizja(const Dron &Ob) const = 0;

/**
 * @brief Rysuje Przeszkodę
 * 
 */
    virtual void RysujPrzeszkode() = 0;

/**
 * @brief Kasuje Przeszkodę
 * 
 */
    virtual void KasujPrzeszkode() = 0;
};

#endif