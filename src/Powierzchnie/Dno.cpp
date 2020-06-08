#include <iostream>
#include "Dno.hh"
#include "Dron.hh"

bool Dno::CzyKolizja(const Dron &Ob) const
{
    Wektor3D srodek_dna = ZwrocPozycje();
    Wektor3D srodek_dron = Ob.ZwrocPozycje();

    if (srodek_dron[2] - srodek_dna[2] > Ob.ZwrocWektorR()[0])
    {
        return false;
    }

    return true;
}

void Dno::RysujPrzeszkode()
{
    Rysuj();
}

void Dno::KasujPrzeszkode()
{
    Kasuj();
}