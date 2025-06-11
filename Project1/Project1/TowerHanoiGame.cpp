#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

std::vector<int> A, B, C;

// Turmanzeige
void zeigeTürme() {
    auto maxHeight = std::max({ A.size(), B.size(), C.size() });
    std::cout << "\nAktueller Zustand:\n";
    for (int i = maxHeight - 1; i >= 0; --i) {
        auto printLevel = [&](std::vector<int>& tower) {
            if (i < tower.size()) std::cout << " " << tower[i] << " ";
            else std::cout << " | ";
            };
        printLevel(A); std::cout << "   ";
        printLevel(B); std::cout << "   ";
        printLevel(C); std::cout << "\n";
    }
    std::cout << " A     B     C \n";
    std::cout << "----------------\n";
}

// Turm-Buchstaben in Referenzen umwandeln
std::vector<int>& getTurm(char c) {
    switch (std::toupper(c)) {
    case 'A': return A;
    case 'B': return B;
    case 'C': return C;
    default: throw std::invalid_argument("Ungültiger Turm");
    }
}

// Regelprüfung + Bewegung
bool versucheZug(char vonChar, char nachChar) {
    auto& von = getTurm(vonChar);
    auto& nach = getTurm(nachChar);

    if (von.empty()) {
        std::cout << "Fehler: Kein Element auf Turm " << vonChar << "\n";
        return false;
    }
    if (!nach.empty() && von.back() > nach.back()) {
        std::cout << "Fehler: Größere Scheibe darf nicht auf kleinere!\n";
        return false;
    }

    int scheibe = von.back();
    von.pop_back();
    nach.push_back(scheibe);
    std::cout << "Bewege Scheibe " << scheibe << " von " << std::toupper(vonChar)
        << " nach " << std::toupper(nachChar) << "\n";
    return true;
}

bool spielBeendet(int anzahl) {
    return C.size() == anzahl && std::is_sorted(C.rbegin(), C.rend());
}

int main() {

    std::locale::global(std::locale("German_germany"));

    int anzahl;
    std::cout << "Wie viele Scheiben? ";
    std::cin >> anzahl;

    for (int i = anzahl; i >= 1; --i) A.push_back(i);

    zeigeTürme();

    while (!spielBeendet(anzahl)) {
        char von, nach;
        std::cout << "\nZug eingeben (z.B. A C): ";
        std::cin >> von >> nach;

        try {
            if (versucheZug(von, nach)) {
                zeigeTürme();
            }
        }
        catch (...) {
            std::cout << "Ungültiger Eingabewert.\n";
        }
    }

    std::cout << "\nGlückwunsch! Du hast das Rätsel gelöst!\n";
    return 0;
}