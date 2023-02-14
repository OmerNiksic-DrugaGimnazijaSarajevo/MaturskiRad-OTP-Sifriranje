#include <iostream>
#include <vector>
#include <string>

using namespace std;

string enkriptuj(string, string);

int main() {

	bool nastavi;
	string poruka;					//Poruka koju korisnik unosi, ili dekriptovana poruka.
	string sifra;
	string enkrPoruka;

	//Do while petlja izvrsava se jednom, a onda nudi korisniku opciju da ponovi program.
	do {
		cout << "Unesite Poruku" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
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
			break;
		}

		cout << "Da li zelite poceti ponovo? Ne - 0, Da - 1" << endl;
		cin >> nastavi;
	} while (nastavi == 1);


	return 0;
}

string enkriptuj(string poruka, string sifra) {
	string pom;
	if (poruka.length() <= sifra.length()) {
		for (int i = 0; i < poruka.length(); i++) {
			cout << poruka[i] << " ";
		}
	}
	else {
		cout << "Greska" << endl;
	}
	return pom;
}