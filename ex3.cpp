//Sa se realizeze o clasa de baza denumita Mamifer si doua clase derivate denumite :
//Cangur si Urs.Programul va trebui să permita adaugarea unor inregistrari și afisarea acestora.

#include <iostream>
#include <string>

using namespace std;

class Mamifer {
private:
	int varsta, greutate;
	string familie, specie;
public:
	void mami()
	{
		cout << endl << endl << "Dati urmatoarele date despre mamifer: " << endl;
		cout << "Varsta: " << endl;
		cin >> varsta;
		cout << "Greuate: " << endl;
		cin >> greutate;
		cout << "Familia: " << endl;
		cin.ignore();
		cin >> familie;
		cout << "Specia: " << endl;
		cin.ignore();
		cin >> specie;
	}
	void afisare();
};

void Mamifer::afisare() 
{
	cout << endl << "Datele mamiferului sunt: " << endl;
	cout << "Varsta: " << varsta << endl;
	cout << "Greutate: " << greutate << endl;
	cout << "Familia: " << familie << endl;
	cout << "Specia: " << specie << endl;
}

class Cangur : public Mamifer
{
private:
	int sare;
public:
	void cat_sare();
	void afisare_cangur();
};

void Cangur::cat_sare() {

	cout << "Cat de sus sare cangurul?" << endl;
	cin >> sare;
}

void Cangur::afisare_cangur()
{
	cout << "Cangurul sare: " << sare;
}

class Urs : public Mamifer {
private: 
	string pacalit;
public:
	void vulpe();
	void afisare_urs();
};

void Urs::vulpe() 
{
	cout << "A fost ursul pacalit de vulpe? ";
	cin >> pacalit;
}

void Urs::afisare_urs()
{
	cout << "Ursul a fost pacalit e vulpe: " << pacalit;
}

int main()
{
	Cangur c;
	Urs u;
	c.mami();
	c.cat_sare();
	c.afisare();
	c.afisare_cangur();
	u.mami();
	u.vulpe();
	u.afisare();
	u.afisare_urs();
	system("pause");
	return 0;
}