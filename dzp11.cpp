
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 20

const char* greska[8] = { "Greska prilikom stvaranja grafa",
"Greska prilikom dodavanja cvora",
"Greska prilikom uklanjaja cvora",
"Greska prilikom dodavanja grane",
"Greska prilikom uklanjaja grane",
"Greska prilikom brisanja grafa",
"Graf je prazan",
"Ovaj cvoj ne postoji u grafu"
};

class G {
private: int i;
public:
	G(int i) { this->i = i; }
	friend ostream& operator<<(ostream &it, const G&)
	{
		return cout << "Greska ";
	}
};


class Graph {

private:
	bool** matrica;
	int n;


public:
	Graph(int n) {

		this->matrica = NULL;
		this->n = n;
		this->matrica = new bool*[n];
		for (int i = 0; i < n; i++) {
			matrica[i] = new bool[n];
			for (int j = 0; j < n; j++)
				matrica[i][j] = false;
		}

		if (this->matrica == NULL) printf("%s", greska[0]);//throw new G(0);

	}

	void dodajGranu(int i, int j)
	{
		if (i >= n || j >= n) {
			printf("%s", greska[3]);//throw new G(3);  
		}
		matrica[i][j] = true;
		matrica[j][i] = true;
	}

	void ukloniGranu(int i, int j) {

		if (i >= n || j >= n) {
			printf("%s", greska[4]);// throw new G(4); ; 
		}
		matrica[i][j] = false;
		matrica[j][i] = false;

	}

	bool susedi(int i, int j) {
		if (matrica[i][j])return true;
		else return false;
	}

	void toString() {

		if (matrica == NULL) {
			printf("%s", greska[6]); //throw new G(6); ;
		}


		for (int i = 0; i < n; i++) {
			cout << i << " : ";
			for (int j = 0; j < n; j++)
				cout << matrica[i][j] << " ";
			cout << "\n";

		}
		cout << "\n";

	}

	~Graph() {

		for (int i = 0; i < n; i++)
			delete[] matrica[i];
		delete[] matrica;

	}

	bool Prazna(Graph m) {
		if (m.matrica == NULL) return true;
		else return false;
	}

	void dodajCvor()
	{
		/*
		this->n = this->n + 1;
		matrica[n-1]=new bool[n];

		for (int i = 0; i < n - 1; i++)
		{
		//matrica[i][n - 1] = new bool;
		matrica[i][n-1] = false;

		}

		for (int j = 0; j < n - 1; j++)
		matrica[n-1][j] = false;
		*/

		bool** matrica1;
		matrica1 = new bool*[this->n + 1];

		for (int i = 0; i < this->n; i++)
		{
			matrica1[i] = new bool[this->n + 1];
			for (int j = 0; j < this->n; j++)
				matrica1[i][j] = matrica[i][j];

			matrica1[i][this->n] = false;
		}

		matrica1[this->n] = new bool[this->n + 1];

		for (int j = 0; j < this->n + 1; j++)
			matrica1[this->n][j] = false;


		for (int i = 0; i < this->n; i++)
			delete[] this->matrica[i];
		delete[] this->matrica;

		this->matrica = matrica1;
		this->n = this->n + 1;

	}

	void ukloniCvor(int u)
	{

		if (n == 0 || u > n)
		{
			printf("%s", greska[2]);//throw new G(2); 
		}

		int m = this->n;

		bool** matrica1 = new bool*[m - 1];

		for (int i = 0; i < m - 1; i++)
		{
			matrica1[i] = new bool[m - 1];


			for (int j = 0; j < m - 1; j++)
			{
				/*if (i < u && j < u) {
				matrica1[i][j] = matrica[i][j];
				}
				else if (u == i || u == j) {
				//one of the rows/columns to be deletd
				//basically skip
				}
				else if (i < u && j > u) {
				matrica1[i][j - 1] = matrica[i][j];
				}
				else if (i > u && j < u) {
				matrica1[i - 1][j] = matrica[i][j];
				}
				else {
				matrica1[i - 1][j - 1] = matrica[i][j];
				}



				if (i<u && j<u)
				{
				matrica1[i][j] = matrica[i][j];
				}
				else {
				matrica1[j][i] = matrica[j][i + 1];
				matrica1[i][j] = matrica[i+1][j];
				}
				*/
				if (i < u && j < u)
					matrica1[i][j] = matrica[i][j];
				else if (i < u && j >= u)
					matrica1[i][j] = matrica[i][j + 1];

				else if (i >= u && j < u)
					matrica1[i][j] = matrica[i + 1][j];

				else if (i >= u && j >= u)
					matrica1[i][j] = matrica[i + 1][j + 1];
			}
		}

		for (int i = 0; i < this->n; i++)
			delete[] this->matrica[i];
		delete[] this->matrica;


		this->matrica = matrica1;
		this->n = this->n - 1;

	}

	void deleteIt()
	{
		this->~Graph();

	}

	int vratiDimenziju() {

		return this->n;

	}
};

int main()
{

	int kraj = 0, i;
	int m;


	printf("Unesite broj cvorova grafa: ");
	scanf("%d", &m);

	Graph g(m);


	while (!kraj)
	{
		printf("\n\n1. Stvaranje grafa\n2. Umetanje novog cvora\n3. Uklanjanje cvora iz grafa\n4. Dodavanje grane\n5. Uklanjanje grane\n6. Ispis reprezentacije grafa\n7. Brisanje grafa iz memorije\n8. Izlaz iz programa\n\nIzaberite zeljenu stavku.\n");
		scanf("%d", &i);

		switch (i)
		{
		case 1: {//Stvaranje grafa

			printf("Unesite broj cvorova grafa: ");
			scanf("%d", &m);
			
			Graph g(m);
			

			break;
		}
		case 2: {//Umetanje novog cvora

			g.dodajCvor();

			break;
		}
		case 3: {//Uklanjanje cvora iz grafa
			printf("\nKoji cvor zelite da uklonite, unesite broj 0-%d\n", g.vratiDimenziju() - 1);

			int e;
			scanf("%d", &e);

			g.ukloniCvor(e);

			break;
		}
		case 4: {//Dodavanje grane
			printf("\nKoju granu zelite da dodate, unesite njene cvorove\n");

			int i, j;
			scanf("%d", &i);
			scanf("%d", &j);

			g.dodajGranu(i, j);

			break;
		}
		case 5: {//Uklanjanje grane
			printf("\nKoju granu zelite da uklonite, unesite njene cvorove\n");

			int i, j;
			scanf("%d", &i);
			scanf("%d", &j);

			g.ukloniGranu(i, j);

			break;
		}
		case 6: {//Ispis reprezentacije grafa

			printf("\nIspis matrice grafa\n");
			g.toString();

			break;

		}
		case 7: {//Brisanje grafa iz memorije

			g.deleteIt();

			break;

		}
		case 8: {//Izlaz iz programa


			kraj = 1;

			break;

		}
		default: {
			printf("Pogresan unos\n\n");
			break; }
		}
	}

}
