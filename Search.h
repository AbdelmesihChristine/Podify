#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include "Episode.h"

using namespace std;

class Search {
public:
    virtual bool matches(const Episode* episode) = 0;
    virtual void print(ostream& ost) = 0;
    virtual ~Search() {}
    friend ostream& operator<<(ostream& ost, Search& search);
};

class H_Search : virtual public Search {
protected:
    string host;
public:
    H_Search(const string& host);
    bool matches(const Episode* episode) override;
    void print(ostream& ost) override;
};

class C_Search : virtual public Search {
protected:
    string category;
public:
    C_Search(const string& category);
    bool matches(const Episode* episode) override;
    void print(ostream& ost) override;
};

class HorC_Search : public H_Search, public C_Search {
public:
    HorC_Search(const string& host, const string& category);
    bool matches(const Episode* episode) override;
    void print(ostream& ost) override;
};

#endif // SEARCH_H