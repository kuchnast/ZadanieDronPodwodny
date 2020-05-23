/** \mainpage Strona główna
 *
 * \section intro_sec Informacje
 *
 * Program rysuje drona w układzie trzech zmiennych oraz pozwala na jego przemieszczanie.
 */

#include <iostream>
#include <chrono>
#include <array>

#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Dron.hh"
#include "Powierzchnia.hh"
#include "Tafla.hh"

using std::vector;
using std::array;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void WyswietlMenu()
{
    cout << "=============MENU=============" << endl;
    cout << "r - zadaj ruch na wprost" << endl;
    cout << "o - zadaj zmiane orientacji" << endl;
    cout << "m - wyswietl menu" << endl << endl;
    cout << "k - koniec dzialania programu" << endl;
}

int main()
{
  const double x_min = -100, 
               x_max = 100, 
               y_min = -100, 
               y_max = 100, 
               z_min = -100, 
               z_max = 100;

  WyswietlMenu();

 std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(x_min, x_max, y_min, y_max, z_min, z_max, -1)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
 Dron dron(10, Wektor3D(0,0,0), "green");
 Powierzchnia dno(x_min, x_max, y_min, y_max, z_min, 20);
 Tafla tafla(x_min, x_max, y_min, y_max, z_max - 5, 20, 5);
 char znak;

 std::array<int, 3> temp = dron.Rysuj(api);
 dno.Rysuj(api, "yellow");
 tafla.Rysuj(api, "blue");
 api->redraw();
 for(auto t: temp)
  api->erase_shape(t);

 do
 {
   cout << "Podaj opcje: ";
   cin >> znak;
   switch (znak)
   {
    case 'r':{
      double odleglosc;
      cout << "\tPodaj odległość: ";
      cin >> odleglosc;
      if(!cin.good()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Podano błędną wartość odległości!\n";
      }
      
      dron.AnimujRuchWPrzod(odleglosc, api);
      break;
    }
    case 'o':{
      double kat;
      cout << "\tPodaj kąt obrotu: ";
      cin >> kat;
      if(!cin.good()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Podano błędną wartość kąta!\n";
      }

      dron.AnimujObrot(kat, api);

      break;
    }
    case 'm':{
      WyswietlMenu();
      break;
    }
    case 'k': {
      cout << "Kończenie pracy programu.\n";
      break;
    }
    default: {
      cout << "Nieznana opcja.\n";
      break;
    }
   }
 }
 while(znak != 'k');

 return 0;
}

