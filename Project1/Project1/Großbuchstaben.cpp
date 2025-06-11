#include <iostream>
#include <cstring>
#include <locale>
using namespace std;

int main()
{
	char machgross[25];
	char backupme[10];
	locale loc;
	cout << "Gib was ein: ";
	cin.getline(machgross, 25);
	cout << "Deine Eingabe: " << machgross << endl;
	for (size_t i = 0; i < strlen(machgross); i++)
	{
		cout << toupper(machgross[i], loc);
	}
	cout << endl;
	strncpy_s(backupme, machgross, 9);
	backupme[9] = '\0';
	cout << backupme << endl;
	return 0;
}