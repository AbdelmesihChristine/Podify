#include "Podcast.h"
#include <cstdlib>

/**
 * @brief Implementation of a Podcast, containing an Array of Episodes.
 */
Podcast::Podcast(const std::string& title, const std::string& host)
    : title(title), host(host) {}

bool Podcast::equals(const std::string& title) const {
    return this->title == title;
}

Episode* Podcast::get(int index) {
    if (index < 0 || index >= episodes.getSize()) {
        std::cerr << "Index out of bounds" << std::endl;
        exit(1);
    }
    return episodes[index];
}

int Podcast::getSize() const {
    return episodes.getSize();
}

void Podcast::print(std::ostream& ost) const {
    ost << "Podcast Title: " << title << ", Host: " << host;
}

void Podcast::printWithEpisodes(std::ostream& ost) const {
    print(ost);
    ost << std::endl << "Episodes:" << std::endl;
    for (int i = 0; i < episodes.getSize(); ++i) {
        ost << "  " << i + 1 << ": " << *episodes[i] << std::endl;
    }
}

void Podcast::add(Episode* episode) {
    episodes += episode;
}

// Overloaded operator<< to print Podcast objects
std::ostream& operator<<(std::ostream& ost, const Podcast& podcast) {
    podcast.print(ost);
    return ost;
}