
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

bool Prazna(bool** matrica) {
	if (matrica == NULL) return true;
	else return false;
}

bool** napraviGraf(int n) {

	bool** matrica = new bool*[n];
	for (int i = 0; i < n; i++) {
		matrica[i] = new bool[n];
		for (int j = 0; j < n; j++)
			matrica[i][j] = false;
	}

	if (Prazna(matrica)) printf("%s", greska[0]);
	return matrica;
}

bool** dodajGranu(bool** matrica, int i, int j, int n)
{
	if (i >= n || j >= n) {
		printf("%s", greska[3]);
	}
	matrica[i][j] = true;
	matrica[j][i] = true;

	return matrica;
}

bool** ukloniGranu(bool** matrica, int i, int j, int n) {

	if (i >= n || j >= n) {
		printf("%s", greska[4]);
	}
	matrica[i][j] = false;
	matrica[j][i] = false;

	return matrica;

}

bool susedi(bool** matrica, int i, int j) {
	if (matrica[i][j] || matrica[i][j])return true;
	else return false;
}

void toString(bool** matrica, int n) {    //promeniti ovo u 1

	if (Prazna(matrica)) {
		printf("%s", greska[6]);
	}
	else {

		for (int i = 0; i < n; i++) {
			printf("%d : ", i);
			for (int j = 0; j < n; j++)
				printf("%d ", matrica[i][j]);
			printf("\n");

		}
		printf("\n");
	}
}

void obrisiGraf(bool** matrica, int n) {

	if (Prazna(matrica)) printf("Greska-ne postoji graf\n");
	else {
		for (int i = 0; i < n; i++)
			delete[] matrica[i];
		delete[] matrica;
		matrica = NULL;
	}
}


bool** dodajCvor(bool** matrica, int n)
{

	bool** matrica1;
	matrica1 = new bool*[n + 1];

	for (int i = 0; i < n; i++)
	{
		matrica1[i] = new bool[n + 1];
		for (int j = 0; j < n; j++)
			matrica1[i][j] = matrica[i][j];

		matrica1[i][n] = false;
	}

	matrica1[n] = new bool[n + 1];

	for (int j = 0; j < n + 1; j++)
		matrica1[n][j] = false;


	for (int i = 0; i < n; i++)
		delete[] matrica[i];
	delete[] matrica;

	matrica = matrica1;
	n = n + 1;

	return matrica;

}
bool** ukloniCvor(bool** matrica, int n, int u)
{

	if (n == 0 || u > n)
	{
		printf("%s", greska[2]);//throw new G(2); 
	}

	int m = n;

	bool** matrica1 = new bool*[m - 1];

	for (int i = 0; i < m - 1; i++)
	{
		matrica1[i] = new bool[m - 1];


		for (int j = 0; j < m - 1; j++)
		{

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

	for (int i = 0; i < n; i++)
		delete[] matrica[i];
	delete[] matrica;



	return matrica1;

}








int n;
bool** matrica;
int main()
{

	int kraj = 0, i;


	//printf("Unesite broj cvorova grafa: ");
	//scanf("%d", &m);
	printf("Unesite broj cvorova grafa: ");
	scanf("%d", &n);

	bool** matrica = napraviGraf(n);


	while (!kraj)
	{
		printf("\n\n1. Stvaranje grafa\n2. Umetanje novog cvora\n3. Uklanjanje cvora iz grafa\n4. Dodavanje grane\n5. Uklanjanje grane\n6. Ispis reprezentacije grafa\n7. Brisanje grafa iz memorije\n8. Izlaz iz programa\n\nIzaberite zeljenu stavku.\n");
		scanf("%d", &i);

		switch (i)
		{
		case 1: {//Stvaranje grafa

			printf("Unesite broj cvorova grafa: ");
			scanf("%d", &n);
			if (Prazna(matrica))printf("Greska-ne postoji graf\n");
			matrica = napraviGraf(n);

			break;
		}
		case 2: {//Umetanje novog cvora

			matrica = dodajCvor(matrica, n);

			break;
		}
		case 3: {//Uklanjanje cvora iz grafa
			printf("\nKoji cvor zelite da uklonite, unesite broj 0-%d\n", n - 1);

			int e;
			scanf("%d", &e);

			matrica = ukloniCvor(matrica, n, e);

			break;
		}
		case 4: {//Dodavanje grane
			printf("\nKoju granu zelite da dodate, unesite njene cvorove\n");

			int i, j;
			scanf("%d", &i);
			scanf("%d", &j);

			matrica = dodajGranu(matrica, i, j, n);
			n++;
			break;
		}
		case 5: {//Uklanjanje grane
			printf("\nKoju granu zelite da uklonite, unesite njene cvorove\n");

			int i, j;
			scanf("%d", &i);
			scanf("%d", &j);

			matrica = ukloniGranu(matrica, i, j, n);
			n--;
			break;
		}
		case 6: {//Ispis reprezentacije grafa

			printf("\nIspis matrice grafa\n");
			toString(matrica, n);

			break;

		}
		case 7: {//Brisanje grafa iz memorije

			obrisiGraf(matrica, n);
			matrica = NULL;

			break;

		}
		case 8: {//Izlaz iz programa

			obrisiGraf(matrica, n);
			matrica = NULL;
			kraj = 1;

			break;

		}
		default: {
			printf("Pogresan unos\n\n");
			break; }
		}
	}

}
