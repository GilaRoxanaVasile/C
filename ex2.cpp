//Să se realizeze două clase : Clasa Șofer, Clasa Mașină.Clasa Șofer va conține următoarele variabile : nume șofer, cnp, vârstă, adresă;
//Clasa Mașină va conține următoarele variabile : producător, model, an fabricație, șofer.Se vor crea pentru cele două clase funcții de citire și de afișare.

#include <iostream>
#include <cstring>

using namespace std;

class sofer 
{
private:
	int varsta;
	char nume[20], cnp[20], adresa[30];

public:
	void citire_sofer()
	{
		cout << "dati urmatoarele informatii despre sofer: nume, varsta, cnp, adresa";
		cin.ignore();
		cin.getline(nume, 20);
		cin >> varsta;
		cin.ignore();
		cin.getline(cnp, 20);
		cin.getline(adresa, 30);
	}
	void afisare_sofer()
	{
		cout << endl << "Datele soferului sunt: " << endl;
		cout << "nume: " << nume << endl << "cnp: " << cnp << endl << "varsta: " << varsta << endl << "adresa: " << adresa << endl;
	}

};

class masina
{
private:
	int an_fabricatie;
	char producator[20], model[20];
	sofer sofer;

public:
	void citire_masina() 
	{
		cout << "dati informatiile despre masina: producator, an fabricatie, model, sofer";
		cin.ignore();
		cin.getline(producator, 20);
		cin >> an_fabricatie;
		cin.ignore();
		cin.getline(model, 20);
		sofer.citire_sofer();
	}
	void afisare_masina()
	{
		cout << endl << "Datele masinii sunt: " << endl;
		cout << "producator: " << producator << endl << "an fabricatie: " << an_fabricatie << endl << "model: " << model << endl;
		sofer.afisare_sofer();
	}

};

int main()
{
	masina masina;

	masina.citire_masina();
	masina.afisare_masina();

	system("pause");
	return 0;
}