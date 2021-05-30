#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "Tablica2D.h"
using namespace std;

void Tab2D::generate(int z)
{
	zakres = z;
	int j = 0;
	while (j < m)
	{
		for (int i = 0; i < n; i++)
		{
			tab[j][i] = rand() % (z + z) - z;
		}
		j++;
	}

}

void Tab2D::simplePrint()
{
	int j = 0;
	while (j < m)
	{
		for (int i = 0; i < n; i++)
		{
			cout << tab[j][i] << " ";

		}
		j++;
		cout << endl;
	}
	
}

void Tab2D::indexedPrint()
{
	int maxLength = (tab[0][0] == 1 || tab[m - 1][n - 1] == 1)
		? to_string(m * n).length() 
		: to_string(zakres).length() + 1; 

	int firstLengthN = 0;

	for (int j = 0; j < m; j++) {
		if (to_string(tab[j][0]).length() > firstLengthN)
			firstLengthN = to_string(tab[j][0]).length();
	}

	for (int j = -2; j < m; j++) 
	{
		for (int i = -2; i < n; i++)
		{
			switch (j)
			{
			case -2:
				switch (i)
				{
				case -2:
					cout << setw(to_string(m - 1).length()) << ' ';
					break;

				case -1:
					cout << setw(1) << ' ';
					break;

				case 0:
					cout << setw(firstLengthN) << i;
					break;

				default:
					cout << setw(maxLength + 1) << i; 
					break;
				}
				break;

			case -1:
				switch (i)
				{
				case -2:
					cout << setw(to_string(m - 1).length()) << ' ';
					break;

				case -1:
					cout << std::setw(1) << '+';
					break;

				case 0:
					cout << setfill('-'); 
					cout << setw(firstLengthN) << '-';
					break;

				default:
					cout << setw(maxLength + 1) << '-';
					break;
				}
				break;

			default:
				cout<< setfill(' '); 
				switch (i)
				{
				case -2:
					cout << setw(to_string(m - 1).length()) << j;
					break;

				case -1:
					cout << setw(1) << '|';
					break;

				case 0:
					cout << setw(firstLengthN) << tab[j][i];
					break;

				default:
					cout << setw(maxLength + 1) << tab[j][i];
					break;
				}
				break;
			}

		}
		cout << std::endl;
	}

	cout << std::endl;
}


void Tab2D::scanPDUJ()
{

	int l = 1;
	int j = m - 1;
	int i = n - 1;

	if (n == 1)
	{
		while (j >= 0)
		{
			tab[j][i] = l;
			l++;
			j--;
		}
	}
	else
		if (m == 1)
		{
			while (i >= 0)
			{
				tab[j][i] = l;
				l++;
				i--;
			}
		}
		else
		{
			for (int tmp = 0; tmp <= n - 1; tmp++)
			{
				j = m - 1;
				i = n - 1;
				tab[j][i - tmp] = l;
				i = i - tmp;
				l++;

				while (i != n - 1)
				{
					tab[j - 1][i + 1] = l;
					i++;
					j--;
					l++;
					if (j == 0)
					{
						break;
					}
				}
			}

			for (int tmp = 1; tmp <= m - 1; tmp++)
			{
				j = m - 1 - tmp;
				i = 0;
				tab[j][i] = l;
				l++;


				while (j != 0)
				{
					tab[j - 1][i + 1] = l;
					j--;
					i++;
					l++;
					if (i == n - 1)
					{
						break;
					}

				}
			}
		}
}

void Tab2D::scanLGKZ()
{

	int l = 1;
	int i = 0;
	int j = 0;

		while (l <= m * n)
		{
			if (j == 0)
			{
				tab[j][i] = l;
				l++;
				while (j != m-1)
				{
					tab[j + 1][i] = l;
					j++;
					l++;
				}
				i++;
			}

			if (j == m-1)
			{
				tab[j][i] = l;
				l++;
				while (j != 0)
				{
					tab[j-1][i] = l;
					j--;
					l++;
				}
				i++;
			}

		}



}

