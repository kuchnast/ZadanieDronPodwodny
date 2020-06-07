#include <iostream>

#include "InterfejsProgramu.hh"
#include "InterfejsDrona.hh"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

void WyswietlMenuGlowne()
{
    cout << "=============MENU=============\n";
    cout << "r - zadaj ruch na wprost\n";
    cout << "o - zadaj zmianę orientacji\n";
    cout << "w - zadaj zmianę wysokości\n\n";

    cout << "d - dodaj obiekt\n";
    cout << "u - usuń obiekt\n\n";

    cout << "z - przełącz się na innego drona\n";

    cout << "m - wyswietl menu\n";
    cout << "k - koniec dzialania programu\n";
    cout << "=============MENU=============\n";
}

void WyswietlMenuObiektow()
{
    cout << "Typy obiektów:\n";
    cout << "\t(" << TO_DRON << ") Dron\n";
    cout << "\t(" << TO_PRZESZKODA << ") Przeszkoda\n";
}

void WyswietlMenuPrzeszkod()
{
    cout << "Rodzaje przeszkód:\n";
    cout << "\t(" << RP_PROSTOPADLOSCIAN << ") Prostopadłościan\n";
}

bool DronRuchWPrzod(KolekcjaObiektow &K)
{
    double odleglosc;
    cout << "Podaj odległość: ";
    cin >> odleglosc;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Podano błędną wartość odległości!\n";
        return false;
    }

    try
    {
        if ((K.ZwrocAktywnegoDrona()).AnimujRuchWPrzod(K.ZwrocListePrzeszkod(), odleglosc))
        {
            cout << "Wykryto kolizję z innym obiektem. Przerwanie ruchu.\n";
            return false;
        }
    }
    catch (const std::invalid_argument &e)
    {
        cerr << e.what() << " Pominięcie instrukcji.\n";
        return false;
    }
    catch (const std::runtime_error &e)
    {
        cerr << e.what() << " Należy ustawić aktywnego drona, aby wykonać ruch\n";
    }

    return true;
}

bool DronObrot(KolekcjaObiektow &K)
{
    double kat;
    cout << "Podaj kąt obrotu: ";
    cin >> kat;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Podano błędną wartość kąta!\n";
        return false;
    }

    try
    {
        (K.ZwrocAktywnegoDrona()).AnimujObrot(K.ZwrocListePrzeszkod(), kat);
    }
    catch (const std::invalid_argument &e)
    {
        cerr << e.what() << " Pominięcie instrukcji.\n";
        return false;
    }
    catch (const std::runtime_error &e)
    {
        cerr << e.what() << " Należy ustawić aktywnego drona, aby wykonać ruch\n";
    }

        return true;
}

bool DronWznoszenie(KolekcjaObiektow &K)
{
    double kat, odleglosc;
    cout << "Podaj odległość: ";
    cin >> odleglosc;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Podano błędną wartość odległości!\n";
        return false;
    }

    cout << "Podaj kąt wznoszenia: ";
    cin >> kat;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Podano błędną wartość kąta!\n";
        return false;
    }

    try
    {
        if ((K.ZwrocAktywnegoDrona()).AnimujRuchWPionie(K.ZwrocListePrzeszkod(), odleglosc, kat))
        {
            cout << "Wykryto kolizję z innym obiektem. Przerwanie ruchu.\n";
            return false;
        }
    }
    catch (const std::invalid_argument &e)
    {
        cerr << e.what() << " Pominięcie instrukcji.\n";
        return false;
    }
    catch (const std::runtime_error &e)
    {
        cerr << e.what() << " Należy ustawić aktywnego drona, aby wykonać ruch\n";
    }

    return true;
}

bool DodajObiekt(KolekcjaObiektow &K)
{
    uint opcja;
    Wektor3D srodek;
    std::string nazwa;

    WyswietlMenuObiektow();
    cout << "Twój wybór: ";
    cin >> opcja;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Podano błędną opcję!\n";
        return false;
    }

    cout << "Podaj współrzędne położenia środka obiektu: ";
    cin >> srodek;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Podano błędne współrzędne środka!\n";
        return false;
    }

    cout << "Podaj nazwę obiektu: ";
    cin >> nazwa;

    switch (opcja)
    {
    case TO_DRON:
    {
        return K.NowyDron(nazwa, 15, srodek);
        break;
    }
    case TO_PRZESZKODA:
    {
        WyswietlMenuPrzeszkod();
        cout << "Twój wybór: ";
        cin >> opcja;
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Podano błędną opcję!\n";
            return false;
        }

        switch (opcja)
        {
        case RP_PROSTOPADLOSCIAN:
        {
            Wektor3D rozmiar;
            cout << "Podaj wymiary obiektu (dl, sz, wys): ";
            cin >> rozmiar;
            if (!cin.good())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Podano błędne wymiary obiektu!\n";
                return false;
            }
            return K.NowaPrzeszkodaProstopadloscian(nazwa, rozmiar[0], rozmiar[1], rozmiar[2], srodek);
            break;
        }
        default:
        {
            cout << "Podano błędną opcję!\n";
            return false;
        }
        }

        break;
    }
    default:
    {
        cout << "Podano błędną opcję!\n";
        return false;
    }
    }

    return true;
}

bool UsunObiekt(KolekcjaObiektow &K)
{
    uint opcja;
    std::string nazwa;

    WyswietlMenuObiektow();
    cout << "Twój wybór: ";
    cin >> opcja;
    if (!cin.good())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Podano błędną opcję!\n";
        return false;
    }

    switch (opcja)
    {
    case TO_DRON:
    {
        K.WyswietlListeDronow();
        cout << "Podaj nazwę drona do usunięcia: ";
        cin >> nazwa;

        return K.UsunDrona(nazwa);
        break;
    }
    case TO_PRZESZKODA:
    {
        K.WyswietlListePrzeszkod();
        cout << "Podaj nazwę przeszkody do usunięcia: ";
        cin >> nazwa;

        return K.UsunPrzeszkode(nazwa);
        break;
    }
    default:
    {
        cout << "Podano błędną opcję!\n";
        return false;
    }
    }

    return true;
}

bool ZmienAktywnegoDrona(KolekcjaObiektow &K)
{
    std::string nazwa;

    K.WyswietlListeDronow();
    cin >> nazwa;
    return K.ZmienAktywnegoDrona(nazwa);
}