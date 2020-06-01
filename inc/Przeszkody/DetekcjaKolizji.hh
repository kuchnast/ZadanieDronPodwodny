#ifndef DETEKCJA_KOLIZJI_HH
#define DETEKCJA_KOLIZJI_HH

#include <iostream>
#include "Dron.hh"

class DetekcjaKolizji
{
public:
    virtual bool CzyKolizja(const Dron &Ob) const = 0;
};


#endif