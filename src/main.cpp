/** \mainpage Strona główna
 *
 * \section intro_sec Informacje
 *
 * Program rysuje drona w układzie trzech zmiennych oraz pozwala na jego przemieszczanie.
 */

#include <iostream>

#include "Dr3D_gnuplot_api.hh"
#include "Zbiornik.hh"
#include "Tafla.hh"
#include "Dno.hh"
#include "PrzeszkodaProstopad.hh"
#include "InterfejsDrona.hh"
#include "KolekcjaObiektow.hh"
#include "InterfejsProgramu.hh"

using drawNS::APIGnuPlot3D;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
  try
  {
    char znak;
    Zbiornik zbiornik(-100, 100, -100, 100, -100, 100);
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(zbiornik.PrzekazXMin(), zbiornik.PrzekazXMax(), zbiornik.PrzekazYMin(), zbiornik.PrzekazYMax(), zbiornik.PrzekazZMin(), zbiornik.PrzekazZMax(), -1));
    Dno dno(api, zbiornik, 20, "yellow");       //obiekt dna zbiornika
    Tafla tafla(api, zbiornik, 20, 20, "blue"); //obiekt tafli z falami
    KolekcjaObiektow kolekcja_obiektow(api);    

    kolekcja_obiektow.NowyDron("Dron_testowy", 15);
    kolekcja_obiektow.ZmienAktywnegoDrona("Dron_testowy");

    //rysuje stałe obiekty sceny
    dno.Rysuj();
    tafla.Rysuj();
    api->redraw();

    WyswietlMenuGlowne();
    do
    {
      cout << "Podaj opcje: ";
      cin >> znak;
      switch (znak)
      {
      case 'r':
      {
        if(!DronRuchWPrzod(kolekcja_obiektow))
          cout << "Operacja nie powiodła się.\n";
        break;
      }

      case 'o':
      {
        if(!DronObrot(kolekcja_obiektow))
          cout << "Operacja nie powiodła się.\n";
        break;
      }

      case 'w':
      {
        if(!DronWznoszenie(kolekcja_obiektow))
          cout << "Operacja nie powiodła się.\n";
        break;
      }

      case 'd':
      {
        if(!DodajObiekt(kolekcja_obiektow))
          cout << "Operacja nie powiodła się.\n";
        break;
      }

      case 'u':
      {
        if(!UsunObiekt(kolekcja_obiektow))
          cout << "Operacja nie powiodła się.\n";
        break;
      }

      case 'z':
      {
        if(!ZmienAktywnegoDrona(kolekcja_obiektow))
          cout << "Operacja nie powiodła się.\n";
        break;
      }

      case 'm':
      {
        WyswietlMenuGlowne();
        break;
      }

      case 'k':
      {
        cout << "Kończenie pracy programu.\n";
        break;
      }

      default:
      {
        cout << "Nieznana opcja.\n";
        break;
      }
      }
    } while (znak != 'k');
  }
  catch (const std::invalid_argument &e)
  {
    cerr << e.what() << "\nKończenie pracy programu." << endl;
  }
  catch (...)
  {
    cerr << "Nieznany wyjątek.\nKończenie pracy programu." << endl;
  }

  return 0;
}
