
#include <iostream>
#include <vector>
#include <string>
#include "CAUniverse.h"

int main()
{
    std::cout << "What is the length of the universe?\n";
    int length;
    std::cin >> length;
    std::cout << "Which rule should be used?\n";
    int rule;
    std::cin >> rule;
    CAUniverse CA((int8_t) rule, std::vector<int8_t>(length,0));
    std::cout << "Which cells should be alive?\n";
    std::string input;
    std::cin >> input;
    while(input != "next") {
        CA.set((int32_t) std::stoi(input), 1);
        std::cin >> input;
    }
    std::cout << "How many steps should be simulated?\n";
    int count;
    std::cin >> count;
    for (int j = 0; j < count; j++) {
        CA.nextStep();
        for (int k = 0; k < length; k++) {
            if (CA.get(k) == 0) {
                std::cout << " ";
            }
            else {
                std::cout << (char)219;
            }
        }
        std::cout << "\n";
    }
}