#ifndef DRON_HH
#define DRON_HH

#include <iostream>

#include "Prostopadloscian.hh"
#include "Sruba.hh"

using drawNS::Point3D;
using std::vector;

/**
 * @brief Klasa modeluje pojęcie drona złożonego z prostopadłościennego kadłuba oraz dwóch śrub
 * 
 */
class Dron
{

protected:
    Prostopadloscian m_kadlub;                  ///< Prostopadłościan będący kadłubem drona
    Sruba m_p_sruba;                            ///< Prawa śruba drona
    Sruba m_l_sruba;                            ///< Lewa śruba drona
    Wektor3D m_srodek;                          ///< Wektor położenia środka układu
    MacierzOb m_orientacja = MacierzOb('z');    ///< Macierz obrotu względem osi z
    vector<int> m_id_obiektow;                  ///< Tablica na identyfikatory rysowanych obiektów

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
 * @param srodek wektor położenia środka obiektu
 * @param kolor_kadluba nazwa koloru kadłuba drona
 * @param kolor_srub nazwa koloru śrub drona
 */
    explicit Dron(double rozmiar, const Wektor3D &srodek = Wektor3D(), const std::string &kolor_kadluba = "black", const std::string &kolor_srub = "black")
        : m_kadlub(rozmiar * 2, rozmiar * 2, rozmiar, kolor_kadluba),
          m_p_sruba(rozmiar / 2, rozmiar / 4, kolor_srub),
          m_l_sruba(rozmiar / 2, rozmiar / 4, kolor_srub),
          m_srodek(srodek)
    {
        m_p_sruba.ZmienPozycje(Wektor3D(rozmiar / 2, -1.125 * rozmiar, 0));
        m_l_sruba.ZmienPozycje(Wektor3D(-rozmiar / 2, -1.125 * rozmiar, 0));
        m_id_obiektow.reserve(3);
    };

/**
 * @brief Rysuje obiekty drona przekształcone według wektora położenia środka oraz macierzy orientacji układu
 * Gdy obiekt już jest obecnie narysowany, kasuje stary i dopiero rysuje nowy obiekt.
 * 
 * @param api łącze do gnuplota
 */
    void Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api);

/**
 * @brief Kasuje narysowane obiekty drona, jeżeli istnieją
 * 
 * @param api łącze do gnuplota
 */
    void Kasuj(const std::shared_ptr<drawNS::Draw3DAPI> &api);

/**
 * @brief Zmienia pozycje drona poprzez zmianę położenia środka obiektu o podany wektor
 * 
 * @param wektor_przesuniecia wektor przesunięcia o który zostanie przemieszczony dron
 */
    void ZmienPozycje(const Wektor3D &wektor_przesuniecia);

/**
 * @brief Dokonaj zmiany macierzy obrotu w kierunku osi z o podany kąt
 * 
 * @param kat kąt w stopniach
 */
    void Obrot(double kat);
};

#endif