#include <iostream>
#include <math.h>
#include "PrzeszkodaProstopad.hh"
#include "Dron.hh"

bool PrzeszkodaProstopad::CzyKolizja(const Dron &Ob) const
{
    Wektor3D srodek_prost = ZwrocPozycje();
    Wektor3D srodek_dron = Ob.ZwrocPozycje();

    if ((srodek_dron - srodek_prost).dlugosc() > ((*this).ZwrocDlugoscR() + Ob.ZwrocDlugoscR())) //odległość środków obiektów większa od długości promieni obiektów
    {
        return false;
    }

    Wektor3D wek_prost = ZwrocWektorR();
    Wektor3D wek_dron = Ob.OrientacjaZ() * Ob.ZwrocWektorR();
    int kolizja_xyz = 0;

    for (int i = 0; i < 3; ++i)
    {
        if(wek_dron[i] < 0)
            wek_dron[i] = -wek_dron[i];

        if (srodek_dron[i] - wek_dron[i] >= srodek_prost[i] - wek_prost[i] && srodek_dron[i] - wek_dron[i] <= srodek_prost[i] + wek_prost[i])
        {
            ++kolizja_xyz;
            continue;
        }

        if (srodek_dron[i] + wek_dron[i] >= srodek_prost[i] - wek_prost[i] && srodek_dron[i] + wek_dron[i] <= srodek_prost[i] + wek_prost[i])
        {
            ++kolizja_xyz;
            continue;
        }

        if (srodek_prost[i] - wek_prost[i] >= srodek_dron[i] - wek_dron[i] && srodek_prost[i] - wek_prost[i] <= srodek_dron[i] + wek_dron[i])
        {
            ++kolizja_xyz;
            continue;
        }

        if (srodek_prost[i] + wek_prost[i] >= srodek_dron[i] - wek_dron[i] && srodek_prost[i] + wek_prost[i] <= srodek_dron[i] + wek_dron[i])
        {
            ++kolizja_xyz;
            continue;
        }

    }

    return (kolizja_xyz == 3) ? true : false;
}

void PrzeszkodaProstopad::RysujPrzeszkode()
{
    Rysuj();
}

void PrzeszkodaProstopad::KasujPrzeszkode()
{
    Kasuj();
}