#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	bool nastavi;
	vector<int[2]> enkrPoruka;
	string poruka;					//Poruka koju korisnik unosi, ili dekriptovana poruka.

	//Do while petlja izvrsava se jednom, a onda nudi korisniku opciju da ponovi program.
	do{
		cout << "Unesite Poruku" << endl;
		getline(cin, poruka);
		
		cout << "Enkripcija - 0, Dekripcija - 1" << endl;
			bool izbor;
		cin >> izbor;

		switch (izbor) {
		case 0:					//Enkripcija
			cout << "Poruka koju program enkriptuje je: " << poruka << endl;
			break;

		case 1:					//Dekripcija
			cout << "Enkriptovana Poruka koju ce program dekriptovati je: " << poruka << endl;
			break;
		}

		cout << "Da li zelite poceti ponovo? Ne - 0, Da - 1" << endl;
		cin >> nastavi;
	} while (nastavi==1);


	return 0;
}