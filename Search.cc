#include "Search.h"

/**
 * @brief Diamond Inheritance: 
 *        All three classes (H_Search, C_Search, HorC_Search) derive from 
 *        the same base class "Search." HorC_Search inherits from H_Search 
 *        and C_Search. 
 * 
 * This forms a diamond shape:
 *           Search
 *          /     \
 *     H_Search   C_Search
 *          \     /
 *        HorC_Search
 */

std::ostream& operator<<(std::ostream& ost, Search& search) {
    search.print(ost);
    return ost;
}

/*------------------ H_Search ------------------*/
H_Search::H_Search(const std::string& host) : host(host) {}

bool H_Search::matches(const Episode* episode) {
    if (!episode) return false; 
    return episode->getHost() == host;
}

void H_Search::print(std::ostream& ost) {
    ost << "Search for Episodes with host: " << host;
}

/*------------------ C_Search ------------------*/
C_Search::C_Search(const std::string& category) : category(category) {}

bool C_Search::matches(const Episode* episode) {
    if (!episode) return false;
    return episode->getCategory() == category;
}

void C_Search::print(std::ostream& ost) {
    ost << "Search for Episodes with category: " << category;
}

/*------------------ HorC_Search ------------------*/
HorC_Search::HorC_Search(const std::string& host, const std::string& category)
    : H_Search(host), C_Search(category) {}

bool HorC_Search::matches(const Episode* episode) {
    if (!episode) return false;
    // Match episodes by host OR category
    return (episode->getHost() == host) || (episode->getCategory() == category);
}

void HorC_Search::print(std::ostream& ost) {
    ost << "Search for Episodes with host: " << host 
        << " or category: " << category;
}