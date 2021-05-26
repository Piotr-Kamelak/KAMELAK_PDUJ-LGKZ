#include <iostream>
#include <cstdlib>
#include "Tablica2D.h"
using namespace std;

Tab2D::Tab2D(int mm, int nn)
{
	m = mm;
	n=nn;

	tab = new int* [mm];
	{
		for (int j = 0; j < mm; j++)
		{
			tab[j] = new int[nn];
		}
	}
}

void Tab2D::generate(int z)
{
	
	int j = 0;
	while (j < m)
	{
		for (int i = 0; i < n; i++)
		{
			tab[j][i] = rand() % (z + z) - z;

		}
		cout << endl;
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
		cout << endl;
		j++;
	}
	
}

void Tab2D::indexedPrint()
{	    //tabelka

	cout << "    ";
	for (int z = 0; z < n; z++)
	{
		if (z <= 9)
		{
			cout << " ";
		}
		if (z <= 99)
		{
			cout << " ";
		}

		cout << z << "  ";
	}

	cout << endl;

	cout << "  ";
	for (int i = 0; i < n * 5; i++)
	{
		cout << "-";

	}
	cout << endl;


	for (int x = 0; x < m; x++)
	{
		if (x > 9)
		{
			cout << x << "|";
		}
		else
			cout << x << " |";


		int  y = 0;
		while (y != n)
		{
			cout << " ";
			if (tab[x][y] <= 9)
			{
				cout << " ";
			}

			if (tab[x][y] <= 99)
			{
				cout << " ";
			}


			if (tab[x][y] <= -1)
			{
				cout << "\b";
			}


			if (tab[x][y] < -9)
			{
				cout << "\b";
			}

			if (tab[x][y] < -99)
			{
				cout << "\b";
			}

			cout << tab[x][y] << " ";

			y++;

		}
		cout << endl;
	}

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

