#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include <vector>

#include "Obiekt3D.hh"

using drawNS::Point3D;
using std::vector;

/**
 * @brief Klasa modeluje pojęcie obiektu 3D będącego prostopadłościanem
 * 
 */
class Prostopadloscian : public Obiekt3D
{
protected:

/**
 * @brief Buduje wierzchołki prostopadłościanu uwzględniając orientacje oraz środek obiektu
 * 
 * @return vector<vector<Point3D>> dynamiczna tablica tablic wierzchołków górnej i dolnej podstawy
 */
    vector<vector<Point3D>> _Zbuduj() const;

/**
 * @brief Buduje wierzchołki prostopadłościanu uwzględniając orientacje oraz środek obiektu i orientacje oraz środek układu 
 * 
 * @return vector<vector<Point3D>> dynamiczna tablica tablic wierzchołków górnej i dolnej podstawy przekształconych według zewnętrznego układu
 */
    vector<vector<Point3D>> _Zbuduj(const MacierzOb &orientacja, const Wektor3D &srodek) const;

public:
/**
 * @brief Usunięcie domyślnego konstruktora bezparametrycznego nowego obiektu klasy Prostopadloscian 
 * 
 */
    Prostopadloscian() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy Prostopadloscian
 * Wylicza on wierzchołki dolnej i górnej podstawy prostopadłościanu o podanych wymiarach
 * @exception std::invalid_argument podano długości boków mniejsze lub równe 0
 * 
 * @param dl_x długość prostopadłościanu
 * @param dl_y szerokość prostopadłościanu
 * @param dl_z wysokość prostopadłościanu
 * @param kolor nazwa koloru obiektu
 */
    Prostopadloscian(double dl_x, double dl_y, double dl_z, const std::string &kolor = "black");

/**
 * @brief Rysuje prostopadłościan z wyliczonych wierzchołków o ustalonym kolorze
 * 
 * @param api łącze do gnuplota
 * @return int identyfikator narysowanego obiektu
 */
    int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const override;

/**
 * @brief Rysuje prostopadłościan z wyliczonych wierzchołków o ustalonym kolorze, względem innego układu o podanej macierzy orientacji i środku
 * 
 * @param api łącze do gnuplota
 * @param orientacja macierz obrotu układu nadrzędnego
 * @param srodek wektor środka w układnie nadrzędnym
 * @return int identyfikator narysowanego obiektu
 */
    int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api, const MacierzOb &orientacja, const Wektor3D &srodek) const;
};

#endif