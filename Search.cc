#include "Search.h"

ostream& operator<<(ostream& ost, Search& search) {
    search.print(ost);
    return ost;
}


H_Search::H_Search(const string& host) : host(host) {}

bool H_Search::matches(const Episode* episode) {
    if (!episode) return false; 
    return episode->getHost() == host;
}

void H_Search::print(ostream& ost) {
    ost << "Search for Episodes with host: " << host;
}


C_Search::C_Search(const string& category) : category(category) {}

bool C_Search::matches(const Episode* episode) {
    if (!episode) return false;
    return episode->getCategory() == category;
}

void C_Search::print(ostream& ost) {
    ost << "Search for Episodes with category: " << category;
}


HorC_Search::HorC_Search(const string& host, const string& category)
    : H_Search(host), C_Search(category) {}

bool HorC_Search::matches(const Episode* episode) {
    if (!episode) return false;
    return (episode->getHost() == host) || (episode->getCategory() == category);
}

void HorC_Search::print(ostream& ost) {
    ost << "Search for Episodes with host: " << host << " or category: " << category;
}