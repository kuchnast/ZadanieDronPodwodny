#ifndef KOLEKCJA_OBIEKTOW_HH
#define KOLEKCJA_OBIEKTOW_HH

#include <iostream>
#include <map>
#include <utility>

#include "PrzeszkodaProstopad.hh"
#include "InterfejsDrona.hh"

typedef std::pair<std::string, std::shared_ptr<InterfejsDrona>> PARA_DRON;
typedef std::map<std::string, std::shared_ptr<InterfejsDrona>>::iterator IT_DRON;

typedef std::pair<std::string, std::shared_ptr<Przeszkoda>> PARA_PRZESZKODA;
typedef std::map<std::string, std::shared_ptr<Przeszkoda>>::iterator IT_PRZESZKODA;

class KolekcjaObiektow
{
protected:
    std::map<std::string, std::shared_ptr<InterfejsDrona>> m_lista_dronow;
    std::map<std::string, std::shared_ptr<Przeszkoda>> m_lista_przeszkod;

    std::string m_aktywny_dron;
    std::shared_ptr<drawNS::Draw3DAPI> m_api;

public:
    explicit KolekcjaObiektow(const std::shared_ptr<drawNS::Draw3DAPI> &api) : m_api(api) {}

    bool NowyDron(const std::string &nazwa, double rozmiar, const Wektor3D &srodek = Wektor3D(), const std::string &kolor_kadluba = "black", const std::string &kolor_srub = "black", uint czas_animacji = 2000);

    bool NowaPrzeszkodaProstopadloscian(const std::string &nazwa, double dl_x, double dl_y, double dl_z, const Wektor3D &srodek = Wektor3D(), const std::string &kolor = "black");

    bool UsunDrona(const std::string &nazwa);

    bool UsunPrzeszkode(const std::string &nazwa);

    InterfejsDrona &ZwrocAktywnegoDrona() const;

    const std::map<std::string, std::shared_ptr<Przeszkoda>> & ZwrocListePrzeszkod() const;

    bool ZmienAktywnegoDrona(const std::string &nazwa);

    void WyswietlListeDronow() const;

    void WyswietlListePrzeszkod() const;
};

#endif
