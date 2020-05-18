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

void wait4key() {
  do {
    std::cout << "\n Press a key to continue... ";
  } while(std::cin.get() != '\n');
}

int main()
{
 std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,-1)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
 
 Dron xd(20, Wektor3D(0,0,0), "blue");

 xd.AnimujObrot(180, api);

 wait4key(); 

 xd.AnimujRuchWPrzod(20, api);

 wait4key();

 return 0;
}

