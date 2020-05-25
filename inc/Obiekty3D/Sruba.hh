#ifndef SRUBA_HH
#define SRUBA_HH

#include <iostream>

#include "Graniastoslup6.hh"

/**
 * @brief Klasa modeluje pojęcie śruby drona złożonej z graniastosłupa sześciokątnego
 * 
 */
class Sruba : public Graniastoslup6
{
public:

/**
 * @brief Usunięty domyślny konstruktor bezparametryczny nowego obiektu klasy Sruba 
 * 
 */
    Sruba() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy Sruba obróconego o 90 stopni względem osi x
 * 
 * @param dl_r długość boku podstawy
 * @param dl_z wysokość
 * @param kolor nazwa koloru obiektu
 */
    Sruba(double dl_r, double dl_z, const std::string &kolor = "black") : Graniastoslup6(dl_r, dl_z, kolor) { m_orientacja_x.Obrot(90); }

/**
 * @brief Zmienia orientacje śruby względem osi y o ujemną wartość podanego kąta
 * 
 * @param kat wartość kąta w stopniach
 */
    void ObrotSrubyLewo(double kat = 1);

/**
 * @brief Zmienia orientacje śruby względem osi y o dodatnią wartość podanego kąta
 * 
 * @param kat wartość kąta w stopniach
 */
    void ObrotSrubyPrawo(double kat = 1);
};

#endif