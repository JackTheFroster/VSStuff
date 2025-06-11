#include <iostream>
#include <string>

int main() {

    std::locale::global(std::locale("German_germany"));

    int breite = 0;
    int hoehe = 0;
    int laenge = 0;
    int ergebnis;

    std::cout << "Geben Sie die Breite ein: ";
    std::cin >> breite;
    std::cout << std::endl;

    std::cout << "Geben Sie die Höhe ein: ";
    std::cin >> hoehe;
    std::cout << std::endl;

    std::cout << "Geben Sie die Länge ein: ";
    std::cin >> laenge;
    std::cout << std::endl;

    ergebnis = breite * laenge * hoehe;

    std::cout << "Ihr Ergebnis ist: " << ergebnis;
    return 0;

}