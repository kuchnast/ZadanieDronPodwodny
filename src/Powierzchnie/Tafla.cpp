#include <iostream>
#include "Tafla.hh"
#include "Dron.hh"

bool Tafla::CzyKolizja(const Dron &Ob) const 
{
    Wektor3D srodek_tafli = ZwrocPozycje();
    Wektor3D srodek_dron = Ob.ZwrocPozycje();

    std::cout << "Tafla: " << srodek_tafli << "  " << srodek_dron << "   " << srodek_tafli[2] << " > " << srodek_dron[2] << "\n";

    if (srodek_tafli[2] > srodek_dron[2])
    {
        return false;
    }

    return true;
}

void Tafla::RysujPrzeszkode()
{
    Rysuj();
}

void Tafla::KasujPrzeszkode()
{
    Kasuj();
}