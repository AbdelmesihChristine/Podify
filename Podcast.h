#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Episode.h"

using namespace std;

class Podcast {
public:
    Podcast(const string& title, const string& host);
    bool equals(const string& title) const;
    Episode* get(int index);
    int getSize() const;
    void print(ostream& ost) const;
    void printWithEpisodes(ostream& ost) const;
    void add(Episode* episode);
    friend ostream& operator<<(ostream& ost, const Podcast& podcast);

private:
    string title;
    string host;
    Array<Episode*> episodes;
};

#endif // PODCAST_H