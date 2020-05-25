#ifndef WEKTOR_3D_HH
#define WEKTOR_3D_HH

#include <iostream>

#include "Wektor.hh"
#include "Draw3D_api_interface.hh"

/**
 * @brief Klasa modelująca pojęcie wektora w układzie 3 zmiennych
 * 
 */
class Wektor3D : public Wektor<double, 3>
{

public:

/**
 * @brief Konstruktor nowego obiektu klasy Wektor3D
 * Nowy obiekt zainicjalizowany jest zerami 
 * 
 */
    Wektor3D() : Wektor<double, 3>() {}

/**
 * @brief Konstruktor nowego obiektu klasy Wektor3D z obiektu klasy Point3D
 * 
 * @param P obiekt klasy Point3D
 */
    Wektor3D(const drawNS::Point3D &P) : Wektor3D(P[0], P[1], P[2]) {}

/**
 * @brief Konstruktor nowego obiektu klasy Wektor3D z tablicy trzech wartości
 * 
 * @param l tablica zawierająca trzy elementy typu double
 */
    Wektor3D(double l[3]) : Wektor<double, 3>(l) {}

/**
 * @brief Konstruktor nowego obiektu klasy Wektor3D z trzech wartości
 * 
 * @param l1 pierwsza wartość - x
 * @param l2 druga wartość - y
 * @param l3 trzecia wartość - z
 */
    Wektor3D(double l1, double l2, double l3){
        m_tab[0] = l1;
        m_tab[1] = l2;
        m_tab[2] = l3;
    };

/**
 * @brief Konstruktor nowego obiektu klasy Wektor3D z obiektu szablonu klasy Wektor
 * 
 * @param W obiekt klasy Wektor
 */
    Wektor3D(const Wektor<double, 3> &W) : Wektor(W) {}
};

#endif