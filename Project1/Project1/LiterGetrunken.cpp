#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<double> drunk;
	double now;
	do {
		cout << "Wieviel Liter getrunken (-1 = Ende): ";
		cin >> now;
		if (now != -1)
		drunk.push_back(now);
	} while (now != -1);
	double gesamt = 0.0;
	for (size_t i = 0; i < drunk.size(); i++)
	{
		gesamt += drunk[i];
	}
	cout << "Getrunken : " << gesamt << " Liter\n";
	return 0;
}