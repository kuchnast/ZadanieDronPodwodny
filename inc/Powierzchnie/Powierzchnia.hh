#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include <iostream>
#include <vector>

#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;

/**
 * @brief Klasa modeluje pojęcie płaszczyzny w poziomie
 * 
 */
class Powierzchnia
{
protected:
    vector<vector<Point3D>> m_wierzcholki; ///< dynamiczna tablica tablic wierzchołków płaszczyzny
    std::string m_kolor;                     ///< nazwa koloru płaszczyzny

public:
/**
 * @brief Usunięty domyślny konstruktor bezparametryczny nowego obiektu klasy Powierzchnia 
 * 
 */
    Powierzchnia() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy Powierzchnia 
 * @exception std::invalid_argument nieprawidłowe wartości parametrów w wywołąniu konstruktora
 * 
 * @param x_min minimalna wartość na osi x
 * @param x_max maksymalna wartość na osi x
 * @param y_min minimalna wartość na osi y
 * @param y_max maksymalna wartość na osi y
 * @param z wysokość na jakiej powstanie płaszczyzna
 * @param odstep odstęp pomiędzy dwiema równoległymi liniami płaszczyzny
 * @param kolor kolor płaszczyzny
 */
    Powierzchnia(double x_min, double x_max, double y_min, double y_max, double z, double odstep = 1, const std::string &kolor = "black");

/**
 * @brief Zmienia kolor powierzchni
 * 
 * @param kolor nazwa koloru
 */
    void ZmienKolor(const std::string &kolor);

/**
 * @brief Rysuje płaszczyzne z wektorów wierzchołków
 * 
 * @param api łącze do gnuplota
 * @return int identyfikator obiektu
 */
    int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const;

};


#endif