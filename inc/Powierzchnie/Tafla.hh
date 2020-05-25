#ifndef TAFLA_HH
#define TAFLA_HH

#include <iostream>

#include "Powierzchnia.hh"

using drawNS::Point3D;

/**
 * @brief Klasa modeluje pojęcie tafli jako powierzchni z wybrzuszeniami na kształt fal
 * 
 */
class Tafla : public Powierzchnia
{
protected:
    uint m_wysokosc_fali; ///< wysokość fali

public:
/**
 * @brief Usunięty domyślny konstruktor bezparametryczny nowego obiektu klasy Tafla 
 * 
 */
    Tafla() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy Tafla 
 * 
 * @param x_min minimalna wartość na osi x
 * @param x_max maksymalna wartość na osi x
 * @param y_min minimalna wartość na osi y
 * @param y_max maksymalna wartość na osi y
 * @param z wysokość na jakiej powstanie płaszczyzna (końce fal)
 * @param odstep odstęp pomiędzy dwiema równoległymi liniami płaszczyzny
 * @param kolor kolor płaszczyzny
 * @param wysokosc_fali wysokość skoku fali
 */
    Tafla(double x_min, double x_max, double y_min, double y_max, double z, double odstep = 1, const std::string &kolor = "blue", uint wysokosc_fali = 0)
        : Powierzchnia(x_min, x_max, y_min, y_max, z - wysokosc_fali, odstep, kolor), m_wysokosc_fali(wysokosc_fali)
    {
        for (auto &wiersz : m_wierzcholki)
            for (uint y = 0; y < wiersz.size(); y += 2)
                wiersz[y] = Point3D(wiersz[y][0], wiersz[y][1], wiersz[y][2] + m_wysokosc_fali);
    }
};

#endif