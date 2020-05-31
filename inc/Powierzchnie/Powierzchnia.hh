#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include <iostream>
#include <vector>

#include "Obiekt3D.hh"
#include "Zbiornik.hh"

using std::vector;
using drawNS::Point3D;

/**
 * @brief Klasa modeluje pojęcie płaszczyzny w poziomie
 * 
 */
class Powierzchnia : public Obiekt3D
{
protected:
/**
 * @brief Buduje tablice punktów tworzących powierzchnię
 * 
 * @return vector<vector<Point3D>> tablica punktów powierzchni
 */
    vector<vector<Point3D>> _Zbuduj() const;

public:
/**
 * @brief Usunięty domyślny konstruktor bezparametryczny nowego obiektu klasy Powierzchnia 
 * 
 */
    Powierzchnia() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy Powierzchnia 
 * 
 * @exception std::invalid_argument nieprawidłowe wartości parametrów w wywołąniu konstruktora
 * 
 * @param api łącze do gnuplota
 * @param x_min minimalna wartość na osi x
 * @param x_max maksymalna wartość na osi x
 * @param y_min minimalna wartość na osi y
 * @param y_max maksymalna wartość na osi y
 * @param z wysokość na jakiej powstanie płaszczyzna
 * @param odstep odstęp pomiędzy dwiema równoległymi liniami płaszczyzny
 * @param kolor kolor płaszczyzny
 */
    Powierzchnia(const std::shared_ptr<drawNS::Draw3DAPI> &api, double x_min, double x_max, double y_min, double y_max, double z, double odstep = 1, const std::string &kolor = "black"): Obiekt3D(api, kolor)
    {
        if (x_min > x_max || y_min > y_max || odstep <= 0)
            throw(std::invalid_argument("Nieprawidłowe parametry tworzenia powierzchni."));

        int liczba_x = ((x_max - x_min) / odstep) + 1, liczba_y = ((y_max - y_min) / odstep) + 1;

        m_wierzcholki.reserve(liczba_x);
        for (int i = 0; i < liczba_x; ++i)
            m_wierzcholki[i].reserve(liczba_y);

        for (int x = 0; x < liczba_x; ++x)
        {
            vector<Wektor3D> temp;
            temp.reserve(liczba_y);

            for (int y = 0; y < liczba_y; ++y)
                temp.push_back(Wektor3D(x_min + x * odstep, y_min + y * odstep, z));

            m_wierzcholki.push_back(temp);
        }
    }

/**
 * @brief Konstruktor nowego obiektu klasy Powierzchnia o wielkości zbiornika na odpowiedniej wysokości
 * 
 * @exception std::invalid_argument gdy wysokość powierzchni znajduje się poza wysokością zbiornika
 * 
 * @param api łącze do gnuplota
 * @param Z obiekt zbiornika w którym rysowana będzie powierzchnia
 * @param z wysokość na jakiej rysujemy powierzchnię
 * @param odstep odstęp między wierzchołkami
 * @param kolor kolor powierzchni
 */
    Powierzchnia(const std::shared_ptr<drawNS::Draw3DAPI> &api, const Zbiornik &Z, double z, double odstep = 1, const std::string &kolor = "black") 
    : Powierzchnia(api, Z.PrzekazXMin(), Z.PrzekazXMax(), Z.PrzekazYMin(), Z.PrzekazYMax(), z, odstep, kolor)
    {
        if(z > Z.PrzekazZMax() || z < Z.PrzekazZMin())
            throw(std::invalid_argument("Wysokość powierzchni poza wymiarami zbiornika."));
    }

/**
 * @brief Rysuje płaszczyzne z wektorów wierzchołków
 * 
 */
    void Rysuj() override;

/**
 * @brief Kasuje powierzchnię
 * 
 */
    void Kasuj() override;
};


#endif