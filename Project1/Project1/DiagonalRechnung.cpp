#include <iostream>
#include <cmath>

int main() {

    std::locale::global(std::locale("German_germany"));

    int width = 17;
    int length = 24;

    std::cout << "Breite: " << width << "cm" << std::endl;
    std::cout << "Länge: " << length << "cm" << std::endl;

    width = std::pow(width, 2);
    length = std::pow(length, 2);

    std::cout << "Breite hoch 2: " << width << "cm" << std::endl;
    std::cout << "Länge hoch 2: " << length << "cm" << std::endl;

    double diagonal = std::sqrt(width + length);

    std::cout << "Diagonale: " << diagonal << "cm" << std::endl;

    return 0;
}
