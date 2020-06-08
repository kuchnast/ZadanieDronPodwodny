#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>

#include "Wektor3D.hh"

class Dron;

/**
 * @brief Klasa modeluje pojęcie przeszkody
 * 
 */
class Przeszkoda
{
private:
    Wektor3D m_wektor_R;    ///< wektor na najbardziej oddalony wierzchołek obiektu
    double m_dl_R;          ///< długość promienia

public:
/**
 * @brief Usunięty domyślny konstruktor nowego obiektu Przeszkoda
 * 
 */
    Przeszkoda() = delete;

/**
 * @brief Konstruktor nowego obiektu Przeszkoda
 * 
 * @param wektor_R wektor na najbardziej oddalony wierzchołek obiektu
 */
    Przeszkoda(Wektor3D wektor_R) : m_wektor_R(wektor_R), m_dl_R(wektor_R.dlugosc()) {}

/**
 * @brief Zwraca wektor promienia
 * 
 * @return const Wektor3D& wektor promienia
 */
    const Wektor3D &ZwrocWektorR() const;

/**
 * @brief Zwraca długość wektora R
 * 
 * @return double długość promienia
 */
    double ZwrocDlugoscR() const;

/**
 * @brief Ustawia wektor R
 * 
 * @param W wektor na najbardziej oddalony wierzchołek obiektu
 */
    void UstawWektorR(const Wektor3D &W);

/**
 * @brief Sprawdza czy nastąpiłą kolizja obiektu z dronem
 * 
 * @param Ob obiekt drona
 * @return true jeżeli jest kolizja
 * @return false jeżeli brak kolizji
 */
    virtual bool CzyKolizja(const Dron &Ob) const = 0;

/**
 * @brief Rysuje Przeszkodę
 * 
 */
    virtual void RysujPrzeszkode() = 0;

/**
 * @brief Kasuje Przeszkodę
 * 
 */
    virtual void KasujPrzeszkode() = 0;
};

#endif