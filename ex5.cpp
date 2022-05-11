#include<iostream>
#include <string.h>

using namespace std;

class Student
{
	char nume[20], pren[20];
	int grupa, cod_postal;
public:
	Student(){}
	Student(char n[20], char p[20],int gr, int cod);
	~Student();
	void citire_date();
	void afisare_date();
};

Student::Student(char n[20], char p[20], int gr, int cod)
{
	strcpy_s(nume, n);
	strcpy_s(pren, p);
	grupa = gr;
	cod_postal = cod;
}

Student::~Student()
{
	delete[]nume;
	delete[]pren;
}

void Student::citire_date()
{
	cout << "Nume:";
	cin >> nume;
	cout << "Prenume:";
	cin >> pren;
	cout << "Grupa:";
	cin >> grupa;
	cout << "Cod postal: ";
	cin >> cod_postal;
}

void Student::afisare_date()
{
	cout << "Nume :" << nume << endl;
	cout << "Prenume:" << pren << endl;
	cout << "Grupa:" << grupa << endl;
	cout << "Cod postal :" << cod_postal;
}

int main()
{
	Student s;

	s.citire_date();
	s.afisare_date();

	system("pause");
	return 0;
}
