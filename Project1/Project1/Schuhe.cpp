#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct schuhe {
	string marke;
	unsigned short EUgroesse;
	string verschluss;
	string farbe;
};
int main()
{
	vector<schuhe> vieleSchuhe;
	schuhe tempSchuh;
	int wahl;
	do {
		cout << "-1- Schuhe hinzufügen\n";
		cout << "-2- Schuhe auflisten\n";
		cout << "-3- Programmende\n";
		cout << "Deine Wahl : ";
		cin >> wahl;
		cin.ignore();
		if (wahl == 1)
		{
			cout << "Marke : ";
			getline(cin, tempSchuh.marke);
			cout << "Größe (EU) : ";
			cin >> tempSchuh.EUgroesse;
			cin.ignore();
			cout << "Verschluss : ";
			getline(cin, tempSchuh.verschluss);
			cout << "Farbe : ";
			getline(cin, tempSchuh.farbe);
			vieleSchuhe.push_back(tempSchuh);
		}
		else if (wahl == 2)
		{
			cout << "\nDie Schuhsammlung deiner Freundin:\n\n";
			for (size_t i = 0; i < vieleSchuhe.size(); ++i)
			{
				cout << vieleSchuhe[i].marke << endl;
				cout << vieleSchuhe[i].EUgroesse << endl;
				cout << vieleSchuhe[i].verschluss << endl;
				cout << vieleSchuhe[i].farbe << "\n\n";
			}
		}
	} while (wahl != 3);
	return 0;
}