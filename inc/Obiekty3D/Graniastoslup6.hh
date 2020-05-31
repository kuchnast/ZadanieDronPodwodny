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
 * @param api łącze do gnuplota
 * @param dl_r długość boku podstawy
 * @param dl_z wysokość
 * @param kolor nazwa koloru obiektu
 */
    Graniastoslup6(double dl_r, double dl_z, const std::shared_ptr<drawNS::Draw3DAPI> &api, const std::string &kolor = "black") : Obiekt3D(api, kolor)
    {
        if (dl_r <= 0 || dl_z <= 0)
            throw(std::invalid_argument("Podano nieprawidłowe długości boków graniastosłupa sześciokątnego."));

        m_wierzcholki.reserve(2);

        double x = cos(M_PI / 6) * dl_r;
        double y = sin(M_PI / 6) * dl_r;

        for (int i = 0; i < 2; ++i)
        {
            vector<Wektor3D> temp;
            temp.reserve(6);
            for (int j = 0; j < 2; ++j)
            {
                if (j)
                {
                    temp.push_back(Wektor3D(0, -dl_r, i ? -dl_z / 2 : dl_z / 2));
                    temp.push_back(Wektor3D(-x, -y, i ? -dl_z / 2 : dl_z / 2));
                    temp.push_back(Wektor3D(-x, y, i ? -dl_z / 2 : dl_z / 2));
                }
                else
                {
                    temp.push_back(Wektor3D(0, dl_r, i ? -dl_z / 2 : dl_z / 2));
                    temp.push_back(Wektor3D(x, y, i ? -dl_z / 2 : dl_z / 2));
                    temp.push_back(Wektor3D(x, -y, i ? -dl_z / 2 : dl_z / 2));
                }
            }
            m_wierzcholki.push_back(temp);
        }
    }

/**
 * @brief Rysuje graniastosłup sześciokątny z wyliczonych wierzchołków o ustalonym kolorze
 * 
 */
    void Rysuj() override;

/**
 * @brief Kasuje obiekt graniastosłupa ze sceny
 * 
 */
    void Kasuj() override;

/**
 * @brief Rysuje graniastosłup sześciokątny z wyliczonych wierzchołków o ustalonym kolorze, względem innego układu o podanej macierzy orientacji i środku
 * 
 * @param orientacja macierz obrotu układu nadrzędnego
 * @param srodek wektor środka w układnie nadrzędnym
 */
    void Rysuj(const MacierzOb &orientacja, const Wektor3D &srodek);
};

#endif