#include <iostream>
#include <string>

using namespace std;

class Persoana {
	char nume[20], prenume[20];
	int varsta;
public:
	Persoana() {}
	Persoana(char n[20], char p[20], int v)
	{
		strcpy_s(nume, n);
		strcpy_s(prenume, p);
		varsta = v;
	}
	void afisare()
	{
		cout << "nume: " << nume << endl << "prenume: " << prenume << endl << "varsta: " << varsta << endl;
	}
	char *retrunare_nume()
	{
		return Persoana::nume;
	}
};

class Student : public Persoana {
private:
	char nivel_studiu[20];
	bool camin;
public:
	Student(char n[20], char p[20],int v,char nivel[20], bool cam):Persoana(n,p,v)
	{
		strcpy_s(nivel_studiu, nivel);
		camin = cam;
	}
	void afisare_student();
};

void Student::afisare_student() {
	afisare();
	cout << "nivel: " << nivel_studiu << endl << "camin: " << camin << endl;
}

class Student_licenta : public Student {
private:
	int an_studiu;
public:
	Student_licenta(char n[20], char p[20], int v, char nivel[20], bool cam, int an):Student(n,p,v,nivel,cam)
	{
		an_studiu = an;
	}
	void afisare_licenta();
};

void Student_licenta::afisare_licenta() {
	afisare_student();
	cout << "an de studiu: " << an_studiu << endl;
}

class Student_master : public Student {
private:
	bool serviciu;
public:
	Student_master(char n[20], char p[20], int v, char nivel[20], bool cam, bool serv) :Student(n, p, v, nivel, cam)
	{
		serviciu=serv;
	}
	void afisare_master();
};

void Student_master::afisare_master() {
	afisare_student();
	cout << "este angajat: " << serviciu << endl;
}

class Doctorand : public Student {
private:
	int ani;
public:
	Doctorand(char n[20], char p[20], int v, char nivel[20], bool cam, int anii) :Student(n, p, v, nivel, cam)
	{
		ani = anii;
	}
	void afisare_doc();
};

void Doctorand::afisare_doc() {
	afisare_student();
	cout << "ani petrecuti in scoala: " << ani << endl;
}

class Angajat : public Persoana {
private:
	char profesie[20];
	int salariu;
public:
	Angajat() {}
	Angajat(char n[20], char p[20], int v, char profes[20], int sal):Persoana(n,p,v)
	{
		strcpy_s(profesie, profes);
		salariu = sal;
	}
	void afisare_angajat();
};

class Profesor : public Angajat {
private:
	char mat[20];
public:
	Profesor() {}
	Profesor(char n[20], char p[20], int v, char profes[20], int sal, char m[20]):Angajat(n,p,v,profes,sal)
	{
		strcpy_s(mat, m);
	}
	void afisare_prof();
};

void Angajat::afisare_angajat() {
	afisare();
	cout << "profesia: " << profesie << endl;
	cout << "salariu: " << salariu << endl;
}

void Profesor::afisare_prof() {
	afisare_angajat();
	cout << "materia pe care o preda: " << mat << endl;
}

class Inginer : public Angajat {
private:
	char ramura[20];
public:
	Inginer(char n[20], char p[20], int v, char profes[20], int sal, char ram[20]) :Angajat(n, p, v, profes, sal)
	{
		strcpy_s(ramura, ram);
	}
	void afisare_inginer();
};

void Inginer::afisare_inginer() {
	afisare_angajat();
	cout << "ramura: " << ramura << endl;
}

int main()
{
	Profesor prof[20];
	int nr = 0;
	int opt;
	int gasit,negasit;
	char nume_cautat[20];
	do {
		cout << endl << "Dati optiunea dorita: " << endl;
		cout << "0. Iesire" << endl;
		cout << "1. Afisare profi" << endl;
		cout << "2. Adaugare prof" << endl;
		cout << "3. Cautare prof dupa nume" << endl;
		cout << "4. Stergere prof dupa nume" << endl;
		cin >> opt;
		switch (opt) {
		case 0:
			break;
		case 1:
			for (int i = 0; i < nr; i++)
			{
				prof[i].afisare_prof();
				cout << endl;
			}
			break;
		case 2:
			char nume[20], prenume[20], profesie[20], mat[20];
			int varsta, salariu;
			cout << "Nume: " << endl;
			cin.get();
			cin.get(nume, 20);
			cout << "Prenume: " << endl;
			cin.get();
			cin.get(prenume, 20);
			cout << "Varsta: " << endl;
			cin >> varsta;
			cout << "Profesie: " << endl;
			cin.get();
			cin.get(profesie, 20);
			cout << "Salariu: " << endl;
			cin >> salariu;
			cout << "Materie: " << endl;
			cin.get();
			cin.get(mat, 20);
			prof[nr] = Profesor(nume, prenume, varsta, profesie, salariu, mat);
			nr++;
			break;
		case 3:
			gasit = 0;
			cout << "Dati numele persoanei cautate: ";
			cin.get();
			cin.get(nume_cautat, 20);
			for (int i = 0; i < nr; i++)
				if (strcmp(nume_cautat, prof[i].retrunare_nume())==0)
				{
					gasit = 1;  break;
				}
			if (gasit == 0)
				cout << "Profesorul nu se afla in lista!" << endl;
			else
				cout << "Profesorul a fost gasit! " << endl;
			break;
		case 4: 
			negasit = 1;
			cout << "Dati numele persoanei pe care doriti sa o stergeti: " << endl;
			char nume_sters[20];
			cin.get();
			cin.get(nume_sters, 20);
			for(int i=0;i<nr;i++)
				if (strcmp(nume_sters, prof[i].retrunare_nume()) == 0)
				{
					for (int j = i; j < nr - 1; j++)
						prof[j] = prof[j + 1];
					nr--;
					negasit = 0;
				}
			if (negasit == 1) cout << "Numele nu exista!" <<endl;
			break;
		default: cout << "optiune gresita!" << endl;
			break;
		}

	} while (opt != 0);

	system("pause");
	return 0;
}