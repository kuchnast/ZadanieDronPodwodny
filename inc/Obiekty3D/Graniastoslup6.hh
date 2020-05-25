#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH

#include <iostream>
#include <vector>

#include "Obiekt3D.hh"

using drawNS::Point3D;
using std::vector;

/**
 * @brief Klasa modeluje pojęcie obiektu 3D będącego graniastosłupem sześciokątnym prawidłowym
 * 
 */
class Graniastoslup6 : public Obiekt3D
{

protected:

/**
 * @brief Buduje wierzchołki graniastosłupa sześciokątnego uwzględniając orientacje oraz środek obiektu
 * 
 * @return vector<vector<Point3D>> dynamiczna tablica tablic wierzchołków górnej i dolnej podstawy
 */
    vector<vector<Point3D>> _Zbuduj() const;

/**
 * @brief Buduje wierzchołki graniastosłupa sześciokątnego uwzględniając orientacje oraz środek obiektu i orientacje oraz środek układu 
 * 
 * @return vector<vector<Point3D>> dynamiczna tablica tablic wierzchołków górnej i dolnej podstawy przekształconych według zewnętrznego układu
 */
    vector<vector<Point3D>> _Zbuduj(const MacierzOb &orientacja, const Wektor3D &srodek) const;

public:
/**
 * @brief Konstruktor nowego obiektu klasy Graniastoslup6
 * @exception std::invalid_argument podano długości boków mniejsze lub równe 0 
 * 
 * @param dl_r długość boku podstawy
 * @param dl_z wysokość
 * @param kolor nazwa koloru obiektu
 */
    Graniastoslup6(double dl_r, double dl_z, const std::string &kolor = "black");

/**
 * @brief Rysuje graniastosłup sześciokątny z wyliczonych wierzchołków o ustalonym kolorze
 * 
 * @param api łącze do gnuplota
 * @return int identyfikator narysowanego obiektu
 */
    int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const override;

/**
 * @brief Rysuje graniastosłup sześciokątny z wyliczonych wierzchołków o ustalonym kolorze, względem innego układu o podanej macierzy orientacji i środku
 * 
 * @param api łącze do gnuplota
 * @param orientacja macierz obrotu układu nadrzędnego
 * @param srodek wektor środka w układnie nadrzędnym
 * @return int identyfikator narysowanego obiektu
 */
    int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const MacierzOb &orientacja, const Wektor3D &srodek) const;
};

#endif