#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

string enkriptuj(string, string);
string dekriptuj(string, string);
string generisiSifru();

int main() {

	bool nastavi;
	string poruka;					//Poruka koju korisnik unosi, ili dekriptovana poruka.
	string sifra;
	string enkrPoruka;
	srand(time(0));

	//Do while petlja izvrsava se jednom, a onda nudi korisniku opciju da ponovi program.
	do {
		cout << "Unesite Poruku" << endl;
		getline(cin, poruka);
		cout << "Unesite Sifru" << endl;
		getline(cin, sifra);

		cout << "Enkripcija - 0, Dekripcija - 1" << endl;
		bool izbor;
		cin >> izbor;

		switch (izbor) {
		case 0:					//Enkripcija
			cout << "Poruka koju program enkriptuje je: " << poruka << endl;
			cout << enkriptuj(poruka, sifra);

			break;

		case 1:					//Dekripcija
			cout << "Enkriptovana Poruka koju ce program dekriptovati je: " << poruka << endl;
			cout << dekriptuj(poruka, sifra);
			break;
		}

		cout << "Da li zelite poceti ponovo? Ne - 0, Da - 1" << endl;
		cin >> nastavi;

		cin.clear();
		cin.ignore(10000, '\n');
	} while (nastavi == 1);


	return 0;
}

string enkriptuj(string poruka, string sifra) {
	string pom;
	int n = poruka.length();
	if (n <= sifra.length()) {
		for (int i = 0; i < n; i++) {
			pom += char((int)poruka[i] + (int)sifra[i]);
		}
	}
	else {
		cout << "Greska" << endl;
	}
	return pom;
}

string dekriptuj(string poruka, string sifra) {
	string pom;
	int n = poruka.length();
	if (n <= sifra.length()) {
		for (int i = 0; i < n; i++) {
			pom += char((int)poruka[i] - (int)sifra[i]);
		}
	} else {
		cout << "Greska" << endl;
	}
	return pom;
}

string generisiSifru() {
	string pom;
	int duzina;
	cout << "UPOZORENJE: Sifre generisane programom nisu, i ne mogu biti apsolutno nasumicne, pa zato nisu sigurne" << endl;
	cout << "Koliko karaktera treba sifra biti duga? ";
	cin >> duzina;

	for (int i = 0; i < duzina; i++) {
		pom += char(rand()%126);
	}

	return pom;
}