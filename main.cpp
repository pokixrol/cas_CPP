#include <iostream>
#include "cas.hpp"

using std::cout;
using std::endl;
using std::cin;

int main() {

    cas c1;
    cas c2(1, 2, 3);
    cas c3(c2);

    int d, h, m, s;

    cout << "Objekt c1 vytvoreny vychozim konstruktorem:                               " << c1
         << "    pocet sekund od pulnoci: " << c1.sekundyOdPulnoci() << endl;
    cout << "Objekt c2 vytvoreny konstruktorem s parametry:                            " << c2
         << "    pocet sekund od pulnoci: " << c2.sekundyOdPulnoci() << endl;
    cout << "Objekt c3 vytvoreny kopirovacim konstruktorem na zaklade objektu c2:      " << c3
         << "    pocet sekund od pulnoci: " << c3.sekundyOdPulnoci() << endl;

    cout << "Nastaveni objektu c1 (bude porovnan s objektem c3)" << endl;
    cout << "Zadej hodiny: ";
    cin >> h;
    cout << "Zadej minuty: ";
    cin >> m;
    cout << "Zadej sekundy: ";
    cin >> s;

    c1.setCas(h, m, s);

    cout << "Objekt c1 po zmene:   " << c1 << "    pocet sekund od pulnoci: " << c1.sekundyOdPulnoci() << endl;
    cout << "Porovnani:    c1==c3  c1: " << c1 << "    c3: " << c3 << (c1 == c3 ? " " : " ne") << "rovnaji" << endl;

    cout << "Prevedeni na sekundy u objektu c2" << endl;
    cout << "Zadej pocet sekud: ";
    cin >> s;

    d = c2.sekundyNaCas(s);

    cout << s << " sekund = " << d << " dny a cas " << c2 << endl;

    c1 = c2 + c3;
    cout << "c1 = c2 + c3 = " << c2 << " + " << c3 << " = " << c1 << endl;
    return 0;
}
