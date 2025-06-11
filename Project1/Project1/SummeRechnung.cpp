#include <iostream>
#include <string>

int main(int argc, const char* argv[]) {
    // Umlaute darstellen
    std::locale::global(std::locale("German_germany"));

    // Anzahl der Argumente ausgeben
    std::cout << "Anzahl der Argumente: " << argc - 1 << std::endl; // -1, weil argv[0] der Programmname ist

    // Alle Argumente ausgeben
    std::cout << "Übergebene Argumente:\n";
    for (int i = 1; i < argc; i++) {  // Start bei 1, da argv[0] der Programmname ist
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    // Prüfen, ob mindestens zwei Zahlen übergeben wurden
    if (argc < 3) {
        std::cerr << "Bitte zwei Zahlen als Argumente eingeben!\n";
        return 1;
    }

    // Strings in Zahlen umwandeln
    int zahl1 = std::stoi(argv[1]);  // Erste Zahl
    int zahl2 = std::stoi(argv[2]);  // Zweite Zahl

    // Berechnung
    int summe = zahl1 + zahl2;

    // Ergebnis ausgeben
    std::cout << "Die Summe von " << zahl1 << " und " << zahl2 << " ist " << summe << std::endl;

    return 0;
}