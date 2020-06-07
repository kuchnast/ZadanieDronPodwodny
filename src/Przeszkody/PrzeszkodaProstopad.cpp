#include <iostream>
#include "PrzeszkodaProstopad.hh"
#include "Dron.hh"

 
bool PrzeszkodaProstopad::CzyKolizja(const Dron &Ob) const
{
    double odl = (ZwrocPozycje() + Ob.ZwrocPozycje()).dlugosc();

    if (odl > ((*this).ZwrocDlugoscR() + Ob.ZwrocDlugoscR()))
        return false;

    Wektor3D wek_prost = (*this).ZwrocWektorR();

    for (int i = 0; i < 3; ++i)
    {
        if (odl <= (wek_prost[i] + Ob.ZwrocDlugoscR()))
            return true;
    }

    return false;
}

void PrzeszkodaProstopad::RysujPrzeszkode()
{
    Rysuj();
}

void PrzeszkodaProstopad::KasujPrzeszkode()
{
    Kasuj();
}