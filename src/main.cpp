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
  WyswietlMenu();

 std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,-1)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
 Dron dron(20, Wektor3D(0,0,0), "blue");
 char znak;

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

