#ifndef WEKTOR_3D_HH
#define WEKTOR_3D_HH

#include <iostream>

#include "Wektor.hh"

/**
 * @brief Klasa modelująca pojęcie wektora w układzie 3 zmiennych
 * 
 */
class Wektor3D : public Wektor<double, 3>
{

public:
    
    Wektor3D(): Wektor<double, 3>(){};

    Wektor3D(double l[3]): Wektor<double, 3>(l){};

    Wektor3D(double l1, double l2, double l3)
    {
        m_tab[0] = l1; m_tab[1] = l2; m_tab[2] =l3;
    };

    Wektor3D(const Wektor<double, 3> &W) : Wektor(W){};
};


#endif