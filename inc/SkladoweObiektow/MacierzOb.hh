#ifndef MACIERZ_OB_HH
#define MACIERZ_OB_HH

#include <iostream>
#include <math.h>

#include "MacierzKw.hh"

/**
 * @brief Klasa modeluje pojęcie macierzy obrotu w układzie 3D
 * 
 */
class MacierzOb : public MacierzKw<double, 3>
{
 private:

  double m_kat; ///< kąt obrotu obecnej macierzy
  char m_os;    ///< oś wobec której wykonujemy obrót

/**
 * @brief Zamienia kąt w stopniach na radiany
 * 
 * @return double wartość kąta w radianach
 */
  double _KatNaRad() const;

/**
 * @brief Koryguje kąt w stopniach na wartość z przedziału od 0 do 360
 * 
 * @param kat wartość kąta w stopniach
 * @return double skorygowany kąt w stopniach
 */
  double _KorygujKat(double kat);

/**
 * @brief Buduje macierz obrotu wokół osi x
 * 
 * @param kat kąt w stopniach
 */
  void _ObrotX(double kat);

/**
 * @brief Buduje macierz obrotu wokół osi y
 * 
 * @param kat kąt w stopniach
 */
  void _ObrotY(double kat);

/**
 * @brief Buduje macierz obrotu wokół osi z
 * 
 * @param kat kąt w stopniach
 */
  void _ObrotZ(double kat);

 public:

/**
 * @brief Usunięcie domyślnego konstruktora bezparametrycznego nowego obiektu klasy MacierzOb 
 * 
 */
  MacierzOb() = delete;

/**
 * @brief Konstruktor nowego obiektu klasy MacierzOb
 * 
 * @param M Macierz kwadratowa 3x3, o odpowiedzniej budowie
 */
  explicit MacierzOb(const MacierzKw &M, char os = 'w', double kat = 0) : MacierzKw(M)
  {
    if(abs((M * M.transponuj()).wyznacznik() - 1) >= 0.0001)
      throw(std::invalid_argument("Macierz niezgodna z własnościami macierzy ortagonalnej."));

    m_os = os;
    m_kat = kat;
  }

  /**
 * @brief Konstruktor nowego obiektu klasy Macierz Ob
 * @exception std::invalid_argument podano nieprawidłowe oznaczenie osi
 * 
 * @param os oznaczenie osi w której będą dokonywane przekształcenia ('x', 'y' lub 'z')
 * @param kat kąt według którego powstanie pierwotna macierz obrotu
 */
  explicit MacierzOb(char os, double kat = 0);

/**
 * @brief Dokonuje obrotu wokół osi ustalonej podczas tworzenia obiektu
 * 
 * @param kat wartość kąta o który zostanie wykonany obrót
 */
  void Obrot(double kat);

};

#endif