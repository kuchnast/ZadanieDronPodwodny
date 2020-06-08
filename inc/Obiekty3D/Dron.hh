#ifndef DRON_HH
#define DRON_HH

#include <iostream>

#include "Obiekt3D.hh"
#include "Prostopadloscian.hh"
#include "Sruba.hh"
#include "Przeszkoda.hh"

using drawNS::Point3D;
using std::vector;

/**
 * @brief Klasa modeluje pojęcie drona złożonego z prostopadłościennego kadłuba oraz dwóch śrub
 * 
 */
class Dron : public Obiekt3D, public Przeszkoda
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
          Przeszkoda(Wektor3D(rozmiar * 2, rozmiar * 2.25, rozmiar)),
          m_kadlub(rozmiar * 2, rozmiar * 2, rozmiar, api, kolor_kadluba),
          m_p_sruba(rozmiar / 2, rozmiar / 4, api, kolor_srub),
          m_l_sruba(rozmiar / 2, rozmiar / 4, api, kolor_srub)

    {
        m_p_sruba.ZmienPozycje(Wektor3D(rozmiar / 2, -1.125 * rozmiar, 0));
        m_l_sruba.ZmienPozycje(Wektor3D(-rozmiar / 2, -1.125 * rozmiar, 0));
        m_srodek = srodek;
        UstawWektorR(Wektor3D(1.6 * rozmiar, 1.6 * rozmiar, 1.6 * rozmiar));
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

/**
 * @brief Sprawdza czy wystąpiła kolizja z innym dronem
 * 
 * @param Ob dron z którym szukamy kolizji
 * @return true jeżeli występuje kolizja
 * @return false jeżeli brak kolizji
 */
    bool CzyKolizja(const Dron &Ob) const override;

    void RysujPrzeszkode() override;

    void KasujPrzeszkode() override;

/**
 * @brief Zmienia kolor obiektu
 * 
 * @param kolor nazwa koloru
 */
    void ZmienKolor(const std::string &kolor);

    const MacierzKw<double, 3> & OrientacjaZ() const;
};

#endif