#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

string enkriptuj(string, string);
string dekriptuj(string, string);
string generisiSifru();

int main() {

	bool nastavi;
	string poruka;					//Poruka koju korisnik unosi, ili dekriptovana poruka.
	string sifra;
	string enkrPoruka;
	fstream sifraStream;
	sifraStream.open("fajlovi/sifra.txt");
	srand(time(0));

	//Do while petlja izvrsava se jednom, a onda nudi korisniku opciju da ponovi program.
	do {
		cout << "Unesite Poruku" << endl;
		getline(cin, poruka);

		cout << "Da li je poruka tekst koji treba sifrovati, ili sifrovani tekst koji treba dešifrovati? Treba Sifrovati - 0, Treba Desifrovati - 1" << endl;
		bool izbor;
		cin >> izbor;

		cout << "Kako zelite unijeti sifru - Ručnim unosom (0), Ucitavanjem iz fajla (1), ili generisanjem sifre (2)(nije preporuceno radi sigurnosti)" << endl;
		int izborS;
		cin >> izborS;

		switch (izborS) {
		case 0:
			cout << "Unesite Sifru" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, sifra);
			break;

		case 1:
			getline(sifraStream, sifra);
			break;

		case 2:
			sifra = generisiSifru();
			sifraStream << sifra;
			break;
		}

		switch (izbor) {
		case 0:					//Enkripcija
			cout << "Poruka koju program enkriptuje je: " << poruka << endl;
			cout << "Enkriptovana poruka je: " << enkriptuj(poruka, sifra);

			break;

		case 1:					//Dekripcija
			cout << "Enkriptovana Poruka koju ce program dekriptovati je: " << poruka << endl;
			cout << "Dekriptovana poruka je : " << dekriptuj(poruka, sifra);
			break;
		}

		cout << endl << "Da li zelite poceti ponovo? Ne - 0, Da - 1" << endl;
		cin >> nastavi;

		cin.clear();
		cin.ignore(10000, '\n');
	} while (nastavi == 1);

	sifraStream.close();
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