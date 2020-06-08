#ifndef DNO_HH
#define DNO_HH

#include <iostream>

#include "Powierzchnia.hh"
#include "Przeszkoda.hh"

using drawNS::Point3D;

/**
 * @brief Klasa modeluje pojęcie dna zbiornika
 * 
 */
class Dno : public Powierzchnia, public Przeszkoda
{
public:
/**
 * @brief Usunięty domyślny konstruktor bezparametryczny nowego obiektu klasy Dno
 * 
 */
    Dno() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy Dno
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
    Dno(const std::shared_ptr<drawNS::Draw3DAPI> &api, double x_min, double x_max, double y_min, double y_max, double z, double odstep = 1, const std::string &kolor = "yellow")
        : Powierzchnia(api, x_min, x_max, y_min, y_max, z, odstep, kolor),
          Przeszkoda(Wektor3D(sqrt(pow(x_min, 2) + pow(x_max, 2)), sqrt(pow(y_min, 2) + pow(y_max, 2)), 0)) {}

/**
 * @brief Konstruktor nowego obiektu klasy Dno umieszczonego w wymiarach zbiornika
 * 
 * 
 * @param api łącze do gnuplota
 * @param Z obiekt zbiornika w którym będzie umieszczona powierzchnia
 * @param odstep odstęp pomiędzy dwiema równoległymi liniami płaszczyzny
 * @param kolor kolor płaszczyzny
 */
    Dno(const std::shared_ptr<drawNS::Draw3DAPI> &api, const Zbiornik &Z, double odstep = 1, const std::string &kolor = "yellow")
        : Dno(api, Z.PrzekazXMin(), Z.PrzekazXMax(), Z.PrzekazYMin(), Z.PrzekazYMax(), Z.PrzekazZMin(), odstep, kolor){}

    bool CzyKolizja(const Dron &Ob) const override;

/**
 * @brief Rysuje Przeszkodę
 * 
 */
    void RysujPrzeszkode() override;

   /**
 * @brief Kasuje Przeszkodę
 * 
 */
    void KasujPrzeszkode() override;
};

#endif