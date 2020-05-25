#ifndef OBIEKT_3D_HH
#define OBIEKT_3D_HH

#include <iostream>
#include <vector>

#include "Wektor3D.hh"
#include "MacierzOb.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;

/**
 * @brief Klasa modeluje pojęcie obiektu 3D
 * 
 * Obiekt ten składa się ze środka według którego budowane są pozostałe punkty, znajdujące się w wektorze wierzchołków.
 * Posiada on trzy macierze orientacji umożliwiające obrót obiektu w każdym z trzech kierunków.
 * 
 */
class Obiekt3D
{
protected:
    MacierzOb m_orientacja_x = MacierzOb('x');  ///< macierz obrotu wokół osi x
    MacierzOb m_orientacja_y = MacierzOb('y');  ///< macierz obrotu wokół osi y
    MacierzOb m_orientacja_z = MacierzOb('z');  ///< macierz obrotu wokół osi z
    Wektor3D m_srodek;                          ///< wektor środka obiektu względem układu 
    vector<vector<Wektor3D>> m_wierzcholki;     ///< dynamiczna podwójna tablica wierzchołków zawierająca tablice wierzchołków podstaw obiektów
    std::string m_kolor;                        ///< nazwa koloru obiektu

public:

/**
 * @brief Konstruktor nowego obiektu klasy Obiekt3D
 * Utworzony obiekt ma domyślne orientacje we wszystkich kierunkach oraz środek w początku układu współrzędnych.
 * 
 * @param kolor nazwa koloru obiektu
 */
    explicit Obiekt3D(const std::string &kolor = "black") : m_kolor(kolor) {}

/**
 * @brief Rysuje Obiekt3D o podanym kolorze
 * 
 * @param api łącze do gnuplota
 * @return int identyfikator utworzonego obiektu
 */
    virtual int Rysuj(const std::shared_ptr<drawNS::Draw3DAPI> &api) const = 0;

/**
 * @brief Zmienia pozycje Obiektu3D poprzez zmianę położenia środka obiektu
 * 
 * @param wektor_przesuniecia wektor o jaki zostanie przesunięty obiekt
 */
    void ZmienPozycje(const Wektor3D &wektor_przesuniecia);

/**
 * @brief Dokonaj zmiany macierzy obrotu w kierunku osi x o podany kąt
 * 
 * @param kat kąt w stopniach
 */
    void ZmienOrientacjeX(double kat);

/**
 * @brief Dokonaj zmiany macierzy obrotu w kierunku osi y o podany kąt
 * 
 * @param kat kąt w stopniach
 */
    void ZmienOrientacjeY(double kat);

/**
 * @brief Dokonaj zmiany macierzy obrotu w kierunku osi z o podany kąt
 * 
 * @param kat kąt w stopniach
 */
    void ZmienOrientacjeZ(double kat);

/**
 * @brief Składa 3 macierze elementarne na wspólną macierz obrotu
 * 
 * @return MacierzKw<double, 3> wspólna macierz obrotu obiektu
 */
    MacierzKw<double, 3> WspolnaOrientacja() const;

/**
 * @brief Zwraca wektor będący pozycją środka obiektu względem układu
 * 
 * @return const Wektor3D& wektor środka obiektu
 */
    const Wektor3D &ZwrocPozycje() const;

/**
 * @brief Zwraca dynamiczną tablicę zawierającą wierzchołki obiektu
 * 
 * @return const vector<Wektor3D>& tablica zawierająca wierzchołki obiektu
 */
    const vector<vector<Wektor3D>> &ZwrocWierzcholki() const;

/**
 * @brief Zmienia kolor obiektu
 * 
 * @param kolor nazwa koloru
 */
    void ZmienKolor(const std::string &kolor);
};

#endif