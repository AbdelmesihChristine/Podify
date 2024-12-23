#ifndef TESTER_H
#define TESTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <random>
#include <unordered_set>

/**
 * @brief Utility class for capturing output from std::cout and searching 
 *        within it for test verification. Also includes some randomization 
 *        helpers to pick random items for testing.
 */
class Tester {
public:
    void initCapture();
    void endCapture();	
    void clearInputBuffer();
    void pressEnterToContinue();

    void find(const std::vector<int>& keys, const std::string* search, int& error);
    void findInOrder(const std::vector<int>& keys, const std::string* search, int& error);
    void confirmAbsent(const std::vector<int>& keys, const std::string* search, int& error);

    void find(const std::vector<std::string>& toFind, int& error);
    void findInOrder(const std::vector<std::string>& toFind, int& error);
    void confirmAbsent(const std::vector<std::string>& toFind, int& error);

    std::string getOutput() { return output; }

    // generate a set (no duplicates) of "count" random integers in [0..range-1]
    void ran(std::vector<int>& list, int count, int range);

    // generate a single random integer in [range_from..range_to-1]
    int ran(int range_from, int range_to);

    void recordMark(int, int, int=0);

private:
    std::streambuf* oldCoutStreamBuf;
    std::ostringstream strCout;
    std::string output;
};

#endif