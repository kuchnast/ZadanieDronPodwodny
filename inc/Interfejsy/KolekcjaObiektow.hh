#ifndef KOLEKCJA_OBIEKTOW_HH
#define KOLEKCJA_OBIEKTOW_HH

#include <iostream>
#include <map>
#include <utility>

#include "PrzeszkodaProstopad.hh"
#include "Tafla.hh"
#include "Dno.hh"
#include "InterfejsDrona.hh"
/**
 * @brief Para obiektów typów string i inteligentny wskaźnik na Interfejs Drona
 * 
 */
typedef std::pair<std::string, std::shared_ptr<InterfejsDrona>> PARA_DRON;

/**
 * @brief Iterator na element kontenera obiektów typów string i inteligentny wskaźnik na Interfejs Drona
 * 
 */
typedef std::map<std::string, std::shared_ptr<InterfejsDrona>>::iterator IT_DRON;

/**
 * @brief Para obiektów typów string i inteligentny wskaźnik na Przeszkoda
 * 
 */
typedef std::pair<std::string, std::shared_ptr<Przeszkoda>> PARA_PRZESZKODA;

/**
 * @brief Iterator na element kontenera obiektów typów string i inteligentny wskaźnik na Przeszkoda
 * 
 */
typedef std::map<std::string, std::shared_ptr<Przeszkoda>>::iterator IT_PRZESZKODA;


/**
 * @brief Klasa modeluje pojęcie kolekcji obiektów zbiornika
 * 
 */
class KolekcjaObiektow
{
protected:
    std::map<std::string, std::shared_ptr<InterfejsDrona>> m_lista_dronow;  ///< kontener interfejsów dronów i ich nazw
    std::map<std::string, std::shared_ptr<Przeszkoda>> m_lista_przeszkod;   ///< kontener przeszkód i ich nazw

    std::string m_aktywny_dron;                                             ///< nazwa aktywnego drona
    std::shared_ptr<drawNS::Draw3DAPI> m_api;                               ///< łącze do gnuplota

public:
/**
 * @brief Konstruktor nowego obiektu Kolekcja Obiektow
 * 
 * @param api łącze do gnuplota
 */
    explicit KolekcjaObiektow(const std::shared_ptr<drawNS::Draw3DAPI> &api) : m_api(api) {}

/**
 * @brief Tworzy nowy obiekt drona i rysuje go w zbiorniku
 * 
 * @param nazwa nazwa drona
 * @param rozmiar rozmiar drona
 * @param srodek położenie drona
 * @param kolor_kadluba kolor kadłuba
 * @param kolor_srub kolor śrub
 * @param czas_animacji minimalny czas animacji
 * @return true jeżeli utworzono poprawnie obiekt
 * @return false w przypadku błędu lub gdy obiekt o podanej nazwie już istnieje
 */
    bool NowyDron(const std::string &nazwa, double rozmiar, const Wektor3D &srodek = Wektor3D(), const std::string &kolor_kadluba = "black", const std::string &kolor_srub = "black", uint czas_animacji = 2000);

/**
 * @brief Tworzy nowy obiekt przeszkody prostopadłościennej i umieszcza ją w zbiorniku
 * 
 * @param nazwa nazwa obiektu
 * @param dl_x długość
 * @param dl_y szerokość
 * @param dl_z wysokość
 * @param srodek położenie
 * @param kolor kolor obiektu
 * @return true jeżeli utworzono poprawnie obiekt
 * @return false w przypadku błędu lub gdy obiekt o podanej nazwie już istnieje
 */
    bool NowaPrzeszkodaProstopadloscian(const std::string &nazwa, double dl_x, double dl_y, double dl_z, const Wektor3D &srodek = Wektor3D(), const std::string &kolor = "black");

/**
 * @brief Tworzy nowy obiekt tafli i umieszcza go w zbiorniku
 * 
 * @param nazwa nazwa obiektu
 * @param Z zbiornik
 * @param odstep wielkość przerwy w siatce
 * @param wysokosc_fali wysokość fali
 * @param kolor kolor obiektu
 * @return true jeżeli utworzono poprawnie obiekt
 * @return false w przypadku błędu lub gdy obiekt o podanej nazwie już istnieje
 */
    bool NowaPrzeszkodaTafla(const std::string &nazwa, const Zbiornik &Z, double odstep = 1, uint wysokosc_fali = 5, const std::string &kolor = "blue");

/**
 * @brief Tworzy nowy obiekt dna i umieszcza go w zbiorniku
 * 
 * @param nazwa nazwa obiektu
 * @param Z zbiornik
 * @param odstep wielkość przerwy w siatce
 * @param kolor kolor obiektu
 * @return true jeżeli utworzono poprawnie obiekt
 * @return false w przypadku błędu lub gdy obiekt o podanej nazwie już istnieje
 */
    bool NowaPrzeszkodaDno(const std::string &nazwa, const Zbiornik &Z, double odstep = 1, const std::string &kolor = "yellow");

/**
 * @brief Usuwa drona ze zbiornika
 *        W przypadku usunięcia aktywnego drona, przed możliwością ruchu trzeba będzie ustawić nowego
 * 
 * @param nazwa nazwa obiektu do usunięcia
 * @return true jeżeli poprawnie usunięto 
 * @return false jeżeli błąd lub obiekt o podanej nazwie nie istnieje
 */
    bool UsunDrona(const std::string &nazwa);
    
/**
 * @brief Usuwa przeszkode ze zbiornika
 *        
 * @param nazwa nazwa obiektu do usunięcia
 * @return true jeżeli poprawnie usunięto 
 * @return false jeżeli błąd lub obiekt o podanej nazwie nie istnieje
 */
    bool UsunPrzeszkode(const std::string &nazwa);

/**
 * @brief Zwraca Interfejs aktywnego drona, jeżeli jest ustawiony
 * @exception std::runtime_error brak aktywnego drona
 * 
 * @return InterfejsDrona& interfejs aktywnego drona
 */
    InterfejsDrona &ZwrocAktywnegoDrona() const;

/**
 * @brief Zwraca kontener przeszkód w zbiorniku
 * 
 * @return const std::map<std::string, std::shared_ptr<Przeszkoda>>& kontener przeszkód w zbiorniku
 */
    const std::map<std::string, std::shared_ptr<Przeszkoda>> & ZwrocListePrzeszkod() const;

/**
 * @brief Pozwala zmienić aktywnego drona na innego w zbiorniku
 *        Dodatkowo aktywny dron zmienia kolor na pomarańczowy, a nieaktywne na czarny
 * 
 * @param nazwa nazwa drona
 * @return true jeżeli poprawnie zmieniono drona lub dron jest już aktywny
 * @return false jeżeli błąd lub brak drona o takiej nazwie
 */
    bool ZmienAktywnegoDrona(const std::string &nazwa);

/**
 * @brief Wyświetla listę dronów w zbiorniku i ich nazwy, zaznacza aktywnego
 * 
 */
    void WyswietlListeDronow() const;

/**
 * @brief Wyświetla listę przeszkód oraz ich nazwy
 * 
 */
    void WyswietlListePrzeszkod() const;
};

#endif
