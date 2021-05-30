#pragma once
#include <iostream>

using namespace std;

class Tab2D
{
public:
	int m; // Liczba wierszy 
	int n; // liczba kolumn
	int zakres; //zakres liczb
	int** tab;

		Tab2D(int mm, int nn)
		{
			m = mm;
			n = nn;

			tab = new int* [m] {};
			{
				for (int j = 0; j < m; j++)
				{
					tab[j] = new int[n] {};
				}
			}
		}

		~Tab2D()
		{
			delete[] tab;
		}
	
	void generate(int);
	void simplePrint();
	void indexedPrint();
	void scanPDUJ();
	void scanLGKZ();
	

};