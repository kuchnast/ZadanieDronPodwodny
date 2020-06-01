#include <iostream>

#include "FabrykaObiektow.hh"

std::shared_ptr<Obiekt3D> FabrykaObiektow::NowyObiekt(TypObiektu Typ, Wektor3D polozenie)
{
    switch (Typ)
    {
    case TO_DRON:
        return std::make_shared<Dron>(15, m_api, polozenie, "black", "orange");
        break;

    case TO_PRZESZKODA:
        return std::make_shared<PrzeszkodaProstopad>(50, 50, 50, m_api, Wektor3D(50, 50, 50), "black");
        break;
    }

    return std::make_shared<Dron>(15, m_api, polozenie, "black", "orange");
}