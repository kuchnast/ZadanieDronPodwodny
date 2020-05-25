/** \mainpage Strona główna
 *
 * \section intro_sec Informacje
 *
 * Program rysuje drona w układzie trzech zmiennych oraz pozwala na jego przemieszczanie.
 */

#include <iostream>

#include "Dr3D_gnuplot_api.hh"
#include "InterfejsDrona.hh"
#include "Powierzchnia.hh"
#include "Tafla.hh"

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
  cout << "d - zadaj zmianę wysokości i ruch na wprost" << endl;
  cout << "m - wyswietl menu" << endl
       << endl;
  cout << "k - koniec dzialania programu" << endl;
}

int main()
{
  try
  {
    const double x_min = -100, x_max = 100, y_min = -100, y_max = 100, z_min = -100, z_max = 100; //wymiary zbiornika

    InterfejsDrona dron(15, Wektor3D(0, 0, 0), "black", "orange", 1000); //obiekt drona
    Powierzchnia dno(x_min, x_max, y_min, y_max, z_min, 20, "yellow");   //obiekt dna zbiornika
    Tafla tafla(x_min, x_max, y_min, y_max, z_max, 20, "blue", 5);       //obiekt tafli z falami

    char znak;

    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(x_min, x_max, y_min, y_max, z_min, z_max, -1));

    //rysuje stałe obiekty sceny
    dno.Rysuj(api);
    tafla.Rysuj(api);
    dron.Rysuj(api);
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
          dron.AnimujRuchWPrzod(api, odleglosc);
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
          dron.AnimujObrot(api, kat);
        }
        catch (const std::invalid_argument &e)
        {
          cerr << e.what() << " Pominięcie instrukcji." << endl;
        }

        break;
      }
      case 'w':
      {
        double wysokosc;
        cout << "\tPodaj wysokość: ";
        cin >> wysokosc;
        if (!cin.good())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Podano błędną wartość odległości!\n";
          break;
        }

        try
        {
          dron.AnimujRuchWPionie(api, wysokosc);
        }
        catch (const std::invalid_argument &e)
        {
          cerr << e.what() << " Pominięcie instrukcji." << endl;
        }

        break;
      }
      case 'd':
      {
        double wysokosc, odleglosc;
        cout << "\tPodaj wysokość: ";
        cin >> wysokosc;
        if (!cin.good())
        {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Podano błędną wartość odległości!\n";
          break;
        }

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
          dron.AnimujRuchWPionieIWPrzod(api, wysokosc, odleglosc);
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
