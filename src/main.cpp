/** \mainpage Strona główna
 *
 * \section intro_sec Informacje
 *
 * Program rysuje drona w układzie trzech zmiennych oraz pozwala na jego przemieszczanie.
 */

#include <iostream>

#include "Dr3D_gnuplot_api.hh"
#include "InterfejsDrona.hh"
#include "Zbiornik.hh"
#include "Tafla.hh"
#include "Dno.hh"

using drawNS::APIGnuPlot3D;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/**
 * @brief Funkcja wyświetla menu z możliwymi opcjami programu
 * 
 */
void WyswietlMenu()
{
  cout << "=============MENU=============" << endl;
  cout << "r - zadaj ruch na wprost" << endl;
  cout << "o - zadaj zmianę orientacji" << endl;
  cout << "w - zadaj zmianę wysokości" << endl;
  cout << "m - wyswietl menu" << endl
       << endl;
  cout << "k - koniec dzialania programu" << endl;
}

int main()
{
  try
  {
    Zbiornik zbiornik(-100, 100, -100, 100, -100, 100);
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(zbiornik.PrzekazXMin(), zbiornik.PrzekazXMax(), zbiornik.PrzekazYMin(), zbiornik.PrzekazYMax(), zbiornik.PrzekazZMin(), zbiornik.PrzekazZMax(), -1));
    InterfejsDrona dron(15, api, Wektor3D(0, 0, 0), "black", "orange", 1000); //obiekt drona
    Dno dno(api, zbiornik, 20, "yellow");                                     //obiekt dna zbiornika
    Tafla tafla(api, zbiornik, 20, 20, "blue");                                //obiekt tafli z falami
    char znak;

    //rysuje stałe obiekty sceny
    dno.Rysuj();
    tafla.Rysuj();
    dron.Rysuj();
    api->redraw();

    WyswietlMenu();
    do
    {
      cout << "Podaj opcje: ";
      cin >> znak;
      switch (znak)
      {
      case 'r':
      {
        double odleglosc;
        cout << "\tPodaj odległość: ";
        cin >> odleglosc;
        if (!cin.good())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Podano błędną wartość odległości!\n";
          break;
        }

        try
        {
          dron.AnimujRuchWPrzod(odleglosc);
        }
        catch (const std::invalid_argument &e)
        {
          cerr << e.what() << " Pominięcie instrukcji." << endl;
        }

        break;
      }

      case 'o':
      {
        double kat;
        cout << "\tPodaj kąt obrotu: ";
        cin >> kat;
        if (!cin.good())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Podano błędną wartość kąta!\n";
          break;
        }

        try
        {
          dron.AnimujObrot(kat);
        }
        catch (const std::invalid_argument &e)
        {
          cerr << e.what() << " Pominięcie instrukcji." << endl;
        }

        break;
      }

      case 'w':
      {
        double kat, odleglosc;
        cout << "\tPodaj odległość: ";
        cin >> odleglosc;
        if (!cin.good())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Podano błędną wartość odległości!\n";
          break;
        }

        cout << "\tPodaj kąt wznoszenia: ";
        cin >> kat;
        if (!cin.good())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Podano błędną wartość kąta!\n";
          break;
        }

        try
        {
          dron.AnimujRuchWPionie(odleglosc, kat);
        }
        catch (const std::invalid_argument &e)
        {
          cerr << e.what() << " Pominięcie instrukcji." << endl;
        }

        break;
      }

      case 'm':
      {
        WyswietlMenu();
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
