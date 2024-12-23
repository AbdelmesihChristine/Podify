#include "Tester.h"

/**
 * @brief Implementation of a small utility class to capture std::cout 
 *        and check for certain strings. Useful for "automation" in tests.
 */
void Tester::pressEnterToContinue(){
    std::cout << "Press enter to continue..." << std::endl;
    char c = std::cin.get();
    while (c != '\n') {
        c = std::cin.get();
    }
}

void Tester::clearInputBuffer(){
    char c = std::cin.get();
    while ( c != '\n') { 
        c = std::cin.get();
    }
}

void Tester::find(const std::vector<int>& keys, const std::string* search, int& error){
    int foundPos = -1;
    error = 0;
    for (auto k : keys){
        foundPos = output.find(search[k]);
        if (foundPos == std::string::npos){
            std::cout << "[Tester] " << search[k] << " not found" << std::endl;
            ++error;
        }
    }
}

void Tester::find(const std::vector<std::string>& toFind, int& error){
    int foundPos = -1;
    error = 0;
    for (auto& tf : toFind){
        foundPos = output.find(tf);
        if (foundPos == std::string::npos){
            std::cout << "[Tester] " << tf << " not found" << std::endl;
            ++error;
        }
    }
}

void Tester::confirmAbsent(const std::vector<int>& keys, const std::string* search, int& error){
    int foundPos = -1;
    error = 0;
    for (auto k : keys){
        foundPos = output.find(search[k]);
        if (foundPos != std::string::npos){
            std::cout << "[Tester] " << search[k] << " found but should not be" << std::endl;
            ++error;
        }
    }
}

void Tester::confirmAbsent(const std::vector<std::string>& absent, int& error){
    int foundPos = -1;
    error = 0;
    for (auto& ab : absent){
        foundPos = output.find(ab);
        if (foundPos != std::string::npos){
            std::cout << "[Tester] " << ab << " found but should not be" << std::endl;
            ++error;
        }
    }
}

void Tester::findInOrder(const std::vector<int>& keys, const std::string* search, int& error){
    int foundPos = -1;
    error = 0;
    for (auto k : keys){
        foundPos = output.find(search[k], foundPos + 1);
        if (foundPos == std::string::npos){
            std::cout << "[Tester] " << search[k] << " not found in order" << std::endl;
            ++error;
        }
    }
}

void Tester::findInOrder(const std::vector<std::string>& toFind, int& error){
    int foundPos = -1;
    error = 0;
    for (auto& tf : toFind){
        foundPos = output.find(tf, foundPos + 1);
        if (foundPos == std::string::npos){
            std::cout << "[Tester] " << tf << " not found in order" << std::endl;
            ++error;
        }
    }
}

void Tester::initCapture(){
    oldCoutStreamBuf = std::cout.rdbuf();
    std::ostringstream temp;
    strCout.swap(temp);
    std::cout.rdbuf(strCout.rdbuf());
}

void Tester::endCapture(){
    std::cout.rdbuf(oldCoutStreamBuf);
    output = strCout.str();
    std::cout << output;
}

void Tester::ran(std::vector<int>& list, int count, int range){
    std::unordered_set<int> s;
    const int range_from = 0;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range - 1);

    while (s.size() < (size_t)count){
        s.insert(distr(generator));
    }
    for (auto el : s){
        list.push_back(el);
    }
}

int Tester::ran(int range_from, int range_to){
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(range_from, range_to - 1);
    return distr(generator);
}

void Tester::recordMark(int, int, int){
    std::cout << "[Tester] called. " << std::endl;
}