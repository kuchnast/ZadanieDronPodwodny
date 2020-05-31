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
 * @param api łącze do gnuplota
 * @param x_min minimalna wartość na osi x
 * @param x_max maksymalna wartość na osi x
 * @param y_min minimalna wartość na osi y
 * @param y_max maksymalna wartość na osi y
 * @param z wysokość na jakiej powstanie płaszczyzna (końce fal)
 * @param odstep odstęp pomiędzy dwiema równoległymi liniami płaszczyzny
 * @param wysokosc_fali wysokość skoku fali
 * @param kolor kolor płaszczyzny
 */
    Tafla(const std::shared_ptr<drawNS::Draw3DAPI> &api, double x_min, double x_max, double y_min, double y_max, double z, double odstep = 1, uint wysokosc_fali = 5, const std::string &kolor = "blue")
        : Powierzchnia(api, x_min, x_max, y_min, y_max, z - wysokosc_fali, odstep, kolor), m_wysokosc_fali(wysokosc_fali)
    {
        for (auto &wiersz : m_wierzcholki)
            for (uint y = 0; y < wiersz.size(); y += 2)
                wiersz[y] = Wektor3D(wiersz[y][0], wiersz[y][1], wiersz[y][2] + m_wysokosc_fali);
    }

/**
 * @brief Konstruktor nowego obiektu klasy Tafla umieszczonego w wymiarach zbiornika
 * 
 * @exception std::invalid_argument gdy wysokość tafli znajduje się poza wysokością zbiornika
 * 
 * @param api łącze do gnuplota
 * @param Z obiekt zbiornika w którym będzie umieszczona powierzchnia
 * @param odstep odstęp pomiędzy dwiema równoległymi liniami płaszczyzny
 * @param wysokosc_fali wysokość skoku fali
 * @param kolor kolor płaszczyzny
 */
    Tafla(const std::shared_ptr<drawNS::Draw3DAPI> &api, const Zbiornik &Z, double odstep = 1, uint wysokosc_fali = 5, const std::string &kolor = "blue")
        : Tafla(api, Z.PrzekazXMin(), Z.PrzekazXMax(), Z.PrzekazYMin(), Z.PrzekazYMax(), Z.PrzekazZMax(), odstep, wysokosc_fali, kolor){}
};

#endif