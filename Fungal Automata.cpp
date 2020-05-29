
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
    for (int k = 0; k < length; k++) {
        if (k == 0) {
            rulecase = current[k] * 2 + current[k + 1];
            future[k] = rules[7 - rulecase];
        }
        else if (k == length - 1) {
            rulecase = current[k - 1] * 4 + current[k] * 2;
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
}