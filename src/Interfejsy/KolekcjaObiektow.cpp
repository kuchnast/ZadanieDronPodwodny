#include <iostream>

#include "KolekcjaObiektow.hh"

using std::cout;
using std::map;
using std::pair;
using std::shared_ptr;
using std::string;

bool KolekcjaObiektow::NowyDron(const std::string &nazwa, double rozmiar, const Wektor3D &srodek, const std::string &kolor_kadluba, const std::string &kolor_srub, uint czas_animacji)
{
    IT_PRZESZKODA it = m_lista_przeszkod.find(nazwa);
    if (it != m_lista_przeszkod.end())
    {
        cout << "Nowy dron nie może mieć takiej samej nazwy jak istniejąca przeszkoda.\n";
        return false;
    }

    pair<IT_DRON, bool> ret;
    shared_ptr<InterfejsDrona> dron = std::make_shared<InterfejsDrona>(rozmiar, m_api, srodek, kolor_kadluba, kolor_srub, czas_animacji);

    
    ret = m_lista_dronow.insert(PARA_DRON(nazwa, dron));

    if (ret.second == false)
    {
        cout << "Istnieje już dron o podanej nazwie.\n";
        return false;
    }

    m_lista_przeszkod.insert(PARA_PRZESZKODA(nazwa, dron));
    (*dron).RysujPrzeszkode();
    m_api->redraw();

    return true;
}

bool KolekcjaObiektow::NowaPrzeszkodaProstopadloscian(const std::string &nazwa, double dl_x, double dl_y, double dl_z, const Wektor3D &srodek, const std::string &kolor)
{
    pair<IT_PRZESZKODA, bool> ret;
    std::shared_ptr<PrzeszkodaProstopad> przeszkoda = std::make_shared<PrzeszkodaProstopad>(dl_x, dl_y, dl_z, m_api, srodek, kolor);

    ret = m_lista_przeszkod.insert(PARA_PRZESZKODA(nazwa, przeszkoda));

    if (ret.second == false)
    {
        cout << "Istnieje już przeszkoda o podanej nazwie.\n";
        return false;
    }

    (*przeszkoda).RysujPrzeszkode();
    m_api->redraw();

    return true;
}

bool KolekcjaObiektow::UsunDrona(const std::string &nazwa)
{
    IT_DRON it = m_lista_dronow.find(nazwa);
    if (it == m_lista_dronow.end())
    {
        cout << "Nie znaleziono drona o podanej nazwie.\n";
        return false;
    }

    (*((*it).second)).KasujPrzeszkode();
    m_lista_dronow.erase(it);

    if (nazwa == m_aktywny_dron)
    {
        m_aktywny_dron.clear();
    }
    else
    {
        IT_PRZESZKODA it_p = m_lista_przeszkod.find(nazwa);
        m_lista_przeszkod.erase(it_p);
    }

    m_api->redraw();
    return true;
}

bool KolekcjaObiektow::UsunPrzeszkode(const std::string &nazwa)
{
    IT_PRZESZKODA it = m_lista_przeszkod.find(nazwa);
    if (it == m_lista_przeszkod.end())
    {
        cout << "Nie znaleziono przeszkody o podanej nazwie.\n";
        return false;
    }
    ((*it).second)->KasujPrzeszkode();
    m_lista_przeszkod.erase(it);

    m_api->redraw();
    return true;
}

InterfejsDrona &KolekcjaObiektow::ZwrocAktywnegoDrona() const
{
    if (m_aktywny_dron.empty())
    {
        throw(std::runtime_error("Brak aktywnego drona."));
    }

    return *(m_lista_dronow.at(m_aktywny_dron));
}

const std::map<std::string, std::shared_ptr<Przeszkoda>> &KolekcjaObiektow::ZwrocListePrzeszkod() const
{
    return m_lista_przeszkod;
}

bool KolekcjaObiektow::ZmienAktywnegoDrona(const std::string &nazwa)
{

    IT_DRON it = m_lista_dronow.find(nazwa);
    if (it == m_lista_dronow.end())
    {
        cout << "Nie znaleziono drona o podanej nazwie.\n";
        return false;
    }

    if (m_aktywny_dron == nazwa)
    {
        cout << "Dron jest obecnie aktywny.\n";
        return true;
    }

    if(m_aktywny_dron.empty())
    {
        m_aktywny_dron = nazwa;
        m_lista_przeszkod.erase(m_aktywny_dron);
        m_lista_dronow[m_aktywny_dron]->ZmienKolor("orange");
        m_lista_dronow[m_aktywny_dron]->RysujPrzeszkode();
        m_api->redraw();
        return true;
    }

    m_lista_przeszkod.erase(nazwa);
    m_lista_dronow[m_aktywny_dron]->ZmienKolor("black");
    m_lista_dronow[m_aktywny_dron]->RysujPrzeszkode();

    m_lista_przeszkod.insert(PARA_PRZESZKODA(m_aktywny_dron, m_lista_dronow[m_aktywny_dron]));

    m_aktywny_dron = nazwa;
    m_lista_dronow[m_aktywny_dron]->ZmienKolor("orange");
    m_lista_dronow[m_aktywny_dron]->RysujPrzeszkode();

    m_api->redraw();
    return true;
}

void KolekcjaObiektow::WyswietlListeDronow() const
{

    if (m_lista_dronow.empty())
    {
        cout << "Brak dronów do wyświetlenia\n";
    }
    else
    {
        int i = 0;
        cout << "===Lista Dronów===\n";
        for (auto &El : m_lista_dronow)
        {
            cout << '(' << i++ << ") " << El.first << (El.first == m_aktywny_dron ? " <== aktywny dron\n" : "\n");
        }
    }
}

void KolekcjaObiektow::WyswietlListePrzeszkod() const
{
    if (m_lista_przeszkod.empty())
    {
        cout << "Brak przeszkód do wyświetlenia\n";
    }
    else
    {
        int i = 0;
        cout << "===Lista Przeszkód===\n";
        for (auto &El : m_lista_przeszkod)
        {
            cout << '(' << i++ << ") " << El.first << '\n';
        }
    }
}