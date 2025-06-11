#include <iostream>

int main()
{
	double drunk[6] = {0.0};
	for (size_t i = 0; i < sizeof(drunk)/sizeof(double); i++)
	{
		std::cout << "Wie viel Liter getrunken (" << i + 1 << ".): ";
		std::cin >> drunk[i];
	}
	double gesamt = 0.0;
	for (size_t i = 0; i < sizeof(drunk) / sizeof(double); i++)
	{
		gesamt += drunk[i];
	}
	std::cout << "Getrunken : " << gesamt << " Liter\n";
	return 0;
}