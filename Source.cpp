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
	friend ostream& operator<<(ostream &it, const G&) 
	{ return it << "Nastala je greska prilikom pravljenja Grafa!"; } 
};
class GD {
	friend ostream& operator<<(ostream &it, const GD&)
	{
		return it << "Nastala je greska prilikom brisanja Grafa!";
	}
};
class GS {
	friend ostream& operator<<(ostream &it, const GS&)
	{
		return it << "Nastala je greska prilikom dodavanja cvora!";
	}
};
class GB {
	friend ostream& operator<<(ostream &it, const GB&)
	{
		return it << "Nastala je greska prilikom brisanja cvora!";
	}
};
class GI {
	friend ostream& operator<<(ostream &it, const GI&)
	{
		return it << "Nastala je greska prilikom ispisa Grafa!";
	}
};
class GSG {
	friend ostream& operator<<(ostream &it, const GSG&)
	{
		return it << "Nastala je greska prilikom dodavanja grane!";
	}
};
class GBG {
	friend ostream& operator<<(ostream &it, const GBG&)
	{
		return it << "Nastala je greska prilikom uklanjanja grane!";
	}
};

class Graph {

private:
	bool** matrica;
	int n;
	

public:
	Graph(int n) {

		try
		{
			this->n = n;
			matrica = new bool*[n];
			for (int i = 0; i < n; i++) {
				matrica[i] = new bool[n];
				for (int j = 0; j < n; j++)
					matrica[i][j] = false;
				}
		}
		catch (G gr)
		{
			cout << gr;
		}


		
	}

	void dodajGranu(int i, int j) {
		try
		{
			if (i >= n || j >= n) throw new GSG();
		    matrica[i][j] = true;
			matrica[j][i] = true;
		}
		catch (GSG gr)
		{
			cout << gr;
		}
		
	}

	void ukloniGranu(int i, int j) {

		try
		{
			if(i >= n || j >= n)throw new GBG();
			matrica[i][j] = false;
			matrica[j][i] = false;
		}
		catch (GBG gr)
		{
			cout << gr;
		}
		
	}

	bool susedi(int i, int j) {
		if (matrica[i][j])return true;
		else return false;
	}

	void toString() {
		try
		{
			if(matrica==NULL) printf("\n%s", greska[5]);
				else {
					for (int i = 0; i < n; i++) {
						cout << i << " : ";
						for (int j = 0; j < n; j++)
							cout << matrica[i][j] << " ";
						cout << "\n";
						}
		
		
					}
		}
		catch (GI gr)
		{
			cout << gr;
		}
		
		
		
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
		//try
		//{
		
		this->n = this->n + 1;
		matrica[n-1]=new bool[n];
		
		for (int i = 0; i < n - 1; i++)
		{
			//matrica[i][n - 1] = new bool;
			matrica[i][n-1] = false;

		}
			
		for (int j = 0; j < n - 1; j++)
		matrica[n-1][j] = false;


		/*
			bool** matrica1;
			this->n=this->n +1;
			matrica1 = new bool*[n];

			for (int i = 0; i < n - 1; i++) {
				matrica1[i] = new bool[n];
				for (int j = 0; j < n - 1; j++)
					matrica1[i][j] = matrica[i][j];

				matrica1[i][n - 1] = false;
			}

			matrica1[n - 1] = new bool[n];
			for (int j = 0; j < n; j++)
				matrica1[n - 1][j] = false;

			bool** temp;
			temp = matrica;
			matrica = matrica1;
			for (int i = 0; i < n; i++)
				delete[] temp[i];
			delete[] temp;
*/
		//}
		//catch (GS gr)
		//{
			//cout << gr;
		//}
		

	}

	void ukloniCvor(int u)
	{
		try
		{
			int i, j;
			if (n == 0 || u > n)
				throw new GB();

			for (i = u; i <n; i++)
				for (j = 0; j < n; j++)
				{
					matrica[j][i] = matrica[j][i + 1];  /* kolone levo */
					matrica[i][j] = matrica[i + 1][j];  /* redove ka gore */
				}
			delete matrica[n - 1];
			this->n=this->n -1;


		}
		catch (GB gr)
		{
			cout << gr;
		}
		


	}

	void deleteIt()
	{
		try
		{
			this->~Graph();
			this->matrica = NULL;
			
		}
		catch (GD gr)
		{
			cout << gr;
		}


		
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
		printf("\nKoji cvor zelite da uklonite, unesite broj 0-%d\n",g.vratiDimenziju());

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
		
			g.deleteIt();
			kraj = 1;
			
		break;

	}
	default: {
		printf("Pogresan unos\n\n");
		break; }

	}
}

}
