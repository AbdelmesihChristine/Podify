#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include "Episode.h"

/**
 * @brief Abstract base class for searching episodes. 
 * 
 * Demonstrates:
 *   - **Multiple Inheritance** in H_Search, C_Search, HorC_Search
 *   - Diamond pattern (shared base class: Search).
 */
class Search {
public:
    virtual bool matches(const Episode* episode) = 0;
    virtual void print(std::ostream& ost) = 0;
    virtual ~Search() {}
    friend std::ostream& operator<<(std::ostream& ost, Search& search);
};

class H_Search : virtual public Search {
protected:
    std::string host;
public:
    H_Search(const std::string& host);
    bool matches(const Episode* episode) override;
    void print(std::ostream& ost) override;
};

class C_Search : virtual public Search {
protected:
    std::string category;
public:
    C_Search(const std::string& category);
    bool matches(const Episode* episode) override;
    void print(std::ostream& ost) override;
};

class HorC_Search : public H_Search, public C_Search {
public:
    HorC_Search(const std::string& host, const std::string& category);
    bool matches(const Episode* episode) override;
    void print(std::ostream& ost) override;
};

#endif // SEARCH_H