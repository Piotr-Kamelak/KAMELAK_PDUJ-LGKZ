
#include <iostream>
#include "Tablica2D.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << "Generacja tablic wg parametrów użytkownika.\n";
    cout << "Parametry m n z oznaczają odpowiednio:\n";
    cout << "liczbę wierszy, kolumn, zakres generacji [-z..z).\n";
    cout << "Dowolny parametr <= 0 powoduje koniec programu.\n\n";

    while (true)
    {
        // Konwersacja
        int m, n, z;
        cout << "m n z = ";
        cin >> m >> n >> z;
        if (!cin || m <= 0 || n <= 0 || z <= 0 ) break;
        Tab2D T(m, n);

        T.generate(z);
        cout << "\nTablica bez wyrównania kolumn\n\n";
        T.simplePrint();

        cout << "Tablica z indeksowaniem\n\n";
        T.indexedPrint();
        
        cout << "Tablica ze skanowaniem PDUJ\n\n";
        T.scanPDUJ();
        T.indexedPrint();
        
        cout << "Tablica ze skanowaniem LGKZ\n\n";
        T.scanLGKZ();
        T.indexedPrint();
        
    }
    if (!cin) cout << "\nBłąd w danych\n";
    cout << "\nKoniec programu\n";
    return 0;
}

