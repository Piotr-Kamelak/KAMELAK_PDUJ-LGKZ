#include <iostream>

using namespace std;

class Tab2D
{
public:
	int m; // Liczba wierszy 
	int n; // liczba kolumn
	int z; //zakres liczb
	int** tab;

	Tab2D(int, int);
	void generate(int);
	void simplePrint();
	void indexedPrint();
	void scanPDUJ();
	void scanLGKZ();
};