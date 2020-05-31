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
 * @param api łącze do gnuplota
 * @param kolor nazwa koloru obiektu
 */
    Prostopadloscian(double dl_x, double dl_y, double dl_z, const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string &kolor = "black") : Obiekt3D(api, kolor)
    {
        if (dl_x <= 0 || dl_y <= 0 || dl_z <= 0)
            throw(std::invalid_argument("Podano nieprawidłowe długości boków prostopadłościanu."));

        m_wierzcholki.reserve(2);

        for (int i = 0; i < 2; ++i)
        {
            vector<Wektor3D> temp;
            temp.reserve(4);

            for (int j = 0; j < 2; ++j)
            {
                if (j)
                    for (int k = 1; k >= 0; --k)
                        temp.push_back(Wektor3D(k ? -dl_x / 2 : dl_x / 2, j ? -dl_y / 2 : dl_y / 2, i ? -dl_z / 2 : dl_z / 2));
                else
                    for (int k = 0; k < 2; ++k)
                        temp.push_back(Wektor3D(k ? -dl_x / 2 : dl_x / 2, j ? -dl_y / 2 : dl_y / 2, i ? -dl_z / 2 : dl_z / 2));
            }
            m_wierzcholki.push_back(temp);
        }
    }

/**
 * @brief Rysuje prostopadłościan z wyliczonych wierzchołków o ustalonym kolorze
 * 
 */
    void Rysuj() override;

/**
 * @brief Kasuje obiekt prostopadłościanu ze sceny
 * 
 */
    void Kasuj() override;

/**
 * @brief Rysuje prostopadłościan z wyliczonych wierzchołków o ustalonym kolorze, względem innego układu o podanej macierzy orientacji i środku
 * 
 * @param orientacja macierz obrotu układu nadrzędnego
 * @param srodek wektor środka w układnie nadrzędnym
 */
    void Rysuj(const MacierzOb &orientacja, const Wektor3D &srodek);
};

#endif