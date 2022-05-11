#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int varsta;
	char nume[20], prenume[20], adresa[20], tel[20];

	cout << "Dati urmatoarle informatii despre persoana: nume, prenume, varsta, adresa, telefonul";
	cin.ignore();

	cin.getline(nume, 20);
	cin.getline(prenume, 20);
	cin >> varsta;
	cin.ignore();
	cin.getline(adresa, 20);
	cin.getline(tel, 20);

	cout << "Informatiile despre persoana X date de dvs. sunt:"<<endl;
	cout << "nume: " << nume << endl << "prenume: " << prenume << endl;
	cout << "varsta: " << varsta << endl << "adresa: " << adresa << endl << "telefonul: " << tel << endl ;

	system("pause");
	return 0;
}