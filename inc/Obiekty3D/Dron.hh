#ifndef DRON_HH
#define DRON_HH

#include <iostream>

#include "Obiekt3D.hh"
#include "Prostopadloscian.hh"
#include "Sruba.hh"

using drawNS::Point3D;
using std::vector;

/**
 * @brief Klasa modeluje pojęcie drona złożonego z prostopadłościennego kadłuba oraz dwóch śrub
 * 
 */
class Dron : public Obiekt3D
{

protected:
    Prostopadloscian m_kadlub;                  ///< Prostopadłościan będący kadłubem drona
    Sruba m_p_sruba;                            ///< Prawa śruba drona
    Sruba m_l_sruba;                            ///< Lewa śruba drona

public:
/**
 * @brief Usunięty domyślny konstruktor bezparametryczny nowego obiektu klasy Dron 
 * 
 */
    Dron() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy Dron 
 * 
 * @param rozmiar wysokość drona będąca jednocześnie przelicznikiem kolejnych długości boków i śrub
 * @param api łącze do gnuplota
 * @param srodek wektor położenia środka obiektu
 * @param kolor_kadluba nazwa koloru kadłuba drona
 * @param kolor_srub nazwa koloru śrub drona
 */
    explicit Dron(double rozmiar, const std::shared_ptr<drawNS::Draw3DAPI> &api, const Wektor3D &srodek = Wektor3D(), const std::string &kolor_kadluba = "black", const std::string &kolor_srub = "black")
        : Obiekt3D(api),
          m_kadlub(rozmiar * 2, rozmiar * 2, rozmiar, api, kolor_kadluba),
          m_p_sruba(rozmiar / 2, rozmiar / 4, api, kolor_srub),
          m_l_sruba(rozmiar / 2, rozmiar / 4, api, kolor_srub)

    {
        m_p_sruba.ZmienPozycje(Wektor3D(rozmiar / 2, -1.125 * rozmiar, 0));
        m_l_sruba.ZmienPozycje(Wektor3D(-rozmiar / 2, -1.125 * rozmiar, 0));
        m_srodek = srodek;
        m_id_obiektu = new int;
    };

/**
 * @brief Rysuje obiekty drona przekształcone według wektora położenia środka oraz macierzy orientacji układu
 * Gdy obiekt już jest obecnie narysowany, kasuje stary i dopiero rysuje nowy obiekt.
 * 
 */
    void Rysuj();

/**
 * @brief Kasuje narysowane obiekty drona, jeżeli istnieją
 * 
 */
    void Kasuj();
};

#endif