
#include <iostream>
#include <vector>
#include <string>
#include "CAUniverse.h"
#include "ImageCreator.h"
#include "CellularAutomata.h"

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

    //testcode 
    /*
    CellularAutomata ZA(length, rule);
    ZA.setCell(9,1);
    for (int k = 0; k < count; k++)
    {
        ZA.nextStep();
        for (int l = 0; l < length; l++)
        {
            if (ZA.getCell_int(l) == 0) {
                std::cout << " ";
            }
            else
            {
                std::cout << (char)219;
            }
        }
        std::cout << "\n";
    }
    */
    
    //testcode
    /*
    try
    {
        ImageCreator img = ImageCreator(3, 2, "Bild.ppm", true);
        img.set(0,0,255, 0, 0);
        img.set(1,0,0, 255, 0);
        img.set(2,0,0, 0, 255);
        img.set(0,1,255, 255, 0);
        img.set(1,1,255, 255, 255);
        img.set(2,1,0, 0, 0);
        img.close();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
    */
}