#include <iostream>
#include "PrzeszkodaProstopad.hh"


bool PrzeszkodaProstopad::CzyKolizja(const Dron &Ob) const
{
    double odl = ((*this).ZwrocPozycje() - Ob.ZwrocPozycje()).dlugosc();

    if(odl > ((*this).ZwrocDlR() + Ob.ZwrocDlR()))
        return false;

    return true;
}