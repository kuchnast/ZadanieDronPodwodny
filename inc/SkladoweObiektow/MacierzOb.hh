#ifndef MACIERZ_OB_HH
#define MACIERZ_OB_HH

#include <iostream>

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