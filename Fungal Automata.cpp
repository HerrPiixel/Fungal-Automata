// Fungal Automata.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>
#include <string>

int length;
int rule;
std::vector<int> current;
std::vector<int> future;
std::vector<int> rules(8, 0);

void nextStep()
{
    int rulecase = 0;
    //for (int onetest2 = 0; onetest2 < length; onetest2++) {
        //std::cout << current[onetest2];
    //}
    for (int k = 0; k < length; k++) {
        if (k == 0) {
            rulecase = current[k] * 2 + current[k + 1];
            future[k] = rules[7 - rulecase];
        }
        else if (k == length - 1) {
            rulecase = current[k - 1] * 4 + current[k] * 2;
            //std::cout << "last cell:" << 7 - rulecase;
            future[k] = rules[7 - rulecase];
        }
        else {
            rulecase = current[k - 1] * 4 + current[k] * 2 + current[k + 1];
            future[k] = rules[7 - rulecase];
        }
        if (future[k] == 1) {
            std::cout << char(219);
        }
        else {
            std::cout << " ";
        }
    }
    current = future;
    std::cout << "\n";
}

int main()
{
    std::cout << "input lenght\n";
    std::cin >> length;
    current = std::vector<int>(length, 0);
    future = std::vector<int>(length, 0);
    std::cout << "input rule\n";
    std::cin >> rule;
    int ruleDiv = rule;
    int div = 128;
    for (int i = 0; i < 8; i++) {
        rules[i] = ruleDiv / div;
        ruleDiv = ruleDiv - rules[i] * div;
        div = div / 2;
    }
    for (int ruletest = 0; ruletest < 8; ruletest++) {
        std::cout << rules[ruletest];
    }
    std::cout << "add ones\n";
    std::string input;
    std::cin >> input;
    while(input != "next") {
        current[std::stoi(input)] = 1;
        std::cin >> input;
    }
    for (int onetest = 0; onetest < length; onetest++) {
        std::cout << current[onetest];
    }
    std::cout << "how many steps?\n";
    int count;
    std::cin >> count;
    for (int j = 0; j < count; j++) {
        nextStep();
    }
    //std::cout << char(219) << " " << char(219) << char(176) << char(178)  << "\n";
    //std::cout << "  " << char(219) << "\n";
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
