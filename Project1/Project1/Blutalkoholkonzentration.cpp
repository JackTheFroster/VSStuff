#include <iostream>

int main() {

    std::locale::global(std::locale("German_germany"));

    double V = 0.0, e = 0.0, p = 0.8, m = 0.0, r = 0.0, A = 0.0, c = 0.0;

    std::cout << "Geben Sie die Masse der Person ein: ";
    std::cin >> m;
    std::cout << std::endl;

    std::cout << "Geben Sie den Verteilungsfaktor im K�rper ein: ";
    std::cin >> r;
    std::cout << std::endl;

    std::cout << "Geben Sie das Volumen des Getr�nks in Milliliter ein: ";
    std::cin >> V;
    std::cout << std::endl;

    std::cout << "Geben Sie den Alkoholvolumenanteil in Prozent ein: ";
    std::cin >> e;
    std::cout << std::endl;

    A = V * e * p;
    c = A / (m * r);

    std::cout << "Die Blutalkoholkonzentration im K�rper sind ungef�hr " << c << " Promille." << std::endl;
    return 0;
}
