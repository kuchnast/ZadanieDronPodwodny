#include <iostream>
#include <cmath>

#include "MacierzOb.hh"
#include "MacierzKw.hh"

double MacierzOb::_KatNaRad() const
{
    return m_kat * M_PI / 180;
}

double MacierzOb::_KorygujKat(double kat)
{
    int n;
    m_kat += kat;
    n = m_kat / 360;
    m_kat -= n * 360;

    if(m_kat < 0)
        m_kat += 360;

    return m_kat;
}

void MacierzOb::_ObrotX(double kat)
{
    double s, c;
    _KorygujKat(kat);
    sincos(_KatNaRad(), &s, &c);
    m_macierz[0][0] = 1 ,m_macierz[0][1] = 0, m_macierz[0][2] =  0;
    m_macierz[1][0] = 0 ,m_macierz[1][1] = c, m_macierz[1][2] = -s;
    m_macierz[2][0] = 0 ,m_macierz[2][1] = s, m_macierz[2][2] =  c;
}

void MacierzOb::_ObrotY(double kat)
{
    double s, c;
    _KorygujKat(kat);
    sincos(_KatNaRad(), &s, &c);
    m_macierz[0][0] =  c ,m_macierz[0][1] = 0, m_macierz[0][2] = s;
    m_macierz[1][0] =  0 ,m_macierz[1][1] = 1, m_macierz[1][2] = 0;
    m_macierz[2][0] = -s ,m_macierz[2][1] = 0, m_macierz[2][2] = c;
}

void MacierzOb::_ObrotZ(double kat)
{
    double s, c;
    _KorygujKat(kat);
    sincos(_KatNaRad(), &s, &c);
    m_macierz[0][0] = c ,m_macierz[0][1] = -s, m_macierz[0][2] = 0;
    m_macierz[1][0] = s ,m_macierz[1][1] =  c, m_macierz[1][2] = 0;
    m_macierz[2][0] = 0 ,m_macierz[2][1] =  0, m_macierz[2][2] = 1;
}

MacierzOb::MacierzOb(char os, double kat)
{
 m_kat = 0, m_os = os;

 switch (os)
 {
 case 'x':
    _ObrotX(kat);
    break;

 case 'y':
    _ObrotY(kat);
    break;

 case 'z':
    _ObrotZ(kat);
    break;
 
 default:
     throw(std::invalid_argument("Podano niewłaściwą oś obrotu!"));
     break;
 }
}

void MacierzOb::Obrot(double kat)
{
 switch (m_os)
 {
 case 'x':
    _ObrotX(kat);
    break;

 case 'y':
    _ObrotY(kat);
    break;

 case 'z':
    _ObrotZ(kat);
    break;
 }
}