#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
int monotony(std::string ch) {
    std::istringstream iss(ch);
    std::string word1;
    std::string word2;
    iss >> word1;
    int s = 0;
    while (iss >> word2) {
        if (stoi(word2) > stoi(word1)) {
            s++;
        }
        else s--;
        word1 = word2;
    }
    return s < 0;
}
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
        int signeplus=monotony(line);
        std::istringstream iss(line);
        std::string word2;
        iss >> word2;
        bool v = true;
        bool tested = false;
        int fautes = 0;
        int intword1 = stoi(word2);
        int first = 0;
        int word2reserve;
        while (iss >> word2) {
            int intword2 = stoi(word2);
            if (first==1 && fautes==1 && !((signeplus && (word2reserve - intword2 != 1 && word2reserve - intword2 != 2 && word2reserve - intword2 != 3)) || (!signeplus && (word2reserve - intword2 != -1 && word2reserve - intword2 != -2 && word2reserve - intword2 != -3))))
            {
                intword1 = word2reserve;
            }
            if ((signeplus && (intword1 - intword2 != 1 && intword1 - intword2 != 2 && intword1 - intword2 != 3)) || (!signeplus && (intword1 - intword2 != -1 && intword1 - intword2 != -2 && intword1 - intword2 != -3)))
            {
                v = false;
                fautes++;
                if (first==0)
                {
                    word2reserve = intword2;
                }
            }
            else intword1 = intword2;   
            first++;
        }
        if (v ||  fautes==1) s++;
    }
    std::cout << s << std::endl;
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
