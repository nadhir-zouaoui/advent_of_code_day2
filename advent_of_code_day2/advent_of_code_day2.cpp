// advent_of_code_day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

int main()
{
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cout << "failed to open" << std::endl;
        return 1;
    }
    std::string line;
    int s = 0;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string word2;
        std::string signe;
        iss >> word2;
        bool v = true;
        bool tested = false;
        int intword1 = stoi(word2);
        while (iss >> word2 && v) {
            int intword2 = stoi(word2);
            if (tested == false) {
                if (intword1 - intword2 >= 0) {
                    signe = "positif";
                }
                else { signe = "negatif"; }
                tested = true;
            }
            if((signe == "positif" && (intword1 - intword2!=1 && intword1 - intword2 != 2 && intword1 - intword2 != 3)) || (signe == "negatif" && (intword1 - intword2 != -1 && intword1 - intword2 != -2 && intword1 - intword2 != -3)))
            {
                v = false;
            }
            intword1 = intword2;
        }
        if (v) s++;
    }
    std::cout <<s<<std::endl;
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
