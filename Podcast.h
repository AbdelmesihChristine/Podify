#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Episode.h"

/**
 * @brief A Podcast contains a list (Array) of Episode pointers.
 */
class Podcast {
public:
    Podcast(const std::string& title, const std::string& host);

    bool equals(const std::string& title) const;
    Episode* get(int index);
    int getSize() const;

    void print(std::ostream& ost) const;
    void printWithEpisodes(std::ostream& ost) const;
    void add(Episode* episode);

    friend std::ostream& operator<<(std::ostream& ost, const Podcast& podcast);

private:
    std::string title;
    std::string host;
    Array<Episode*> episodes;
};

#endif // PODCAST_H