#include <iostream>

int main() {

    std::locale::global(std::locale("German_germany"));

    double GM = 0, GF = 0, m = 0, l = 0, t = 0;

    std::cout << "Geben Sie das Körpergewicht der Person in Kilogramm ein: ";
    std::cin >> m;
    std::cout << std::endl;

    std::cout << "Geben Sie die Körpergröße der Person in Zentimeter ein: ";
    std::cin >> l;
    std::cout << std::endl;

    std::cout << "Geben Sie das Alter der Person in Jahren ein: ";
    std::cin >> t;
    std::cout << std::endl;

    GM = 66.47 + 13.7 * m + 5 * l - 6.8 * t;
    GF = 655.1 + 9.6 * m + 1.8 * l - 4.7 * t;

    std::cout << "Der Grundumsatz des Körpers bei einem Mann ist ungefähr " << GM << " Kalorien pro Tag." << std::endl;
    std::cout << "Der Grundumsatz des Körpers bei einer Frau ist ungefähr " << GF << " Kalorien pro Tag." << std::endl;

    return 0;
}
