//
// Created by Mateusz on 03.04.2017.
//

#include <iostream>
#include "TextPool.h"

using namespace pool;
using namespace std;

int main() {
    /*//Inicjalizacja wstępna puli za pomocą listy inicjalizacyjnej
    TextPool pool {"abc", "efg", "hij", "klmn", "oprst"};

    //wstawienie napisu do puli
    auto s1 = pool.Intern("efg");

    //wstawienie kolejnego napisu do puli (w obu przypadkach nie
    //powinien się zmienić rozmiar puli)
    auto s2 = pool.Intern("efg");

    cout << (s1 == s2 ? "True" : "False") << endl; //uchwyty są tymi samymi napisami co do wartości
    cout << pool.StoredStringCount() << endl; // w puli jest wciąż 5 napisów
    cout << (s1.begin() == s2.begin() ? "True" : "False") << endl; //na dodatek uchywyty s1 i s2 pokazują dokładnie na ten sam napis w puli (wskaźniki są identyczne)
     */
    set<string> mapa;
    mapa.insert("Lublin");
    mapa.insert("Łódź");
    mapa.insert("Warszawa");
    mapa.insert("Kraków");

    set<string>::iterator result, it;

    // szuka elementu "Warszawa"
    result = mapa.find("Warszawa");
    if( result!=mapa.end() )
        cout << "Znalazłem! " << *result<< '\n';

    // wyświetlenie zawartości
    for( it=mapa.begin(); it!=mapa.end(); ++it)
        cout << *it<< '\n';

    return 0;
}

