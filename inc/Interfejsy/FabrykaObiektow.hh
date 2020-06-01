#ifndef FABRYKA_OBIEKTOW_HH
#define Fa

#include <iostream>

#include "Obiekt3D.hh"
#include "PrzeszkodaProstopad.hh"
#include "Dron.hh"

enum TypObiektu
{
    TO_DRON,
    TO_PRZESZKODA
};

class FabrykaObiektow
{
protected:
    std::shared_ptr<drawNS::Draw3DAPI> m_api;

public:
    explicit FabrykaObiektow(const std::shared_ptr<drawNS::Draw3DAPI> &api) : m_api(api){}

    std::shared_ptr<Obiekt3D> NowyObiekt(TypObiektu Typ, Wektor3D polozenie = Wektor3D(0, 0, 0));
};

#endif