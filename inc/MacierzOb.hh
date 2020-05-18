#ifndef MACIERZ_OB_HH
#define MACIERZ_OB_HH

#include <iostream>

#include "MacierzKw.hh"
#include "Wektor3D.hh"

/**
 * @brief Klasa modeluje pojęcie macierzy obrotu w układzie 3D
 * 
 */
class MacierzOb : public MacierzKw<double, 3>
{
 private:


 protected:

  double m_kat;
  char m_os;

  double _KatNaRad() const;

  double _KorygujKat(double kat);

  void _ObrotX(double kat);

  void _ObrotY(double kat);

  void _ObrotZ(double kat);

 public:

  MacierzOb() = delete;

  explicit MacierzOb(char os, double kat = 0);

  void Obrot(double kat);

};

#endif