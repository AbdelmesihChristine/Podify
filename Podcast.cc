#include "Podcast.h"
#include <cstdlib>

Podcast::Podcast(const string& title, const string& host)
    : title(title), host(host) {}

bool Podcast::equals(const string& title) const {
    return this->title == title;
}

Episode* Podcast::get(int index) {
    if (index < 0 || index >= episodes.getSize()) {
        cerr << "Index out of bounds" << endl;
        exit(1);
    }
    return episodes[index];
}

int Podcast::getSize() const {
    return episodes.getSize();
}

void Podcast::print(ostream& ost) const {
    ost << "Podcast Title: " << title << ", Host: " << host;
}

void Podcast::printWithEpisodes(ostream& ost) const {
    print(ost);
    ost << endl << "Episodes:" << endl;
    for (int i = 0; i < episodes.getSize(); ++i) {
        ost << "  " << i + 1 << ": " << *episodes[i] << endl;
    }
}

void Podcast::add(Episode* episode) {
    episodes += episode;
}

ostream& operator<<(ostream& ost, const Podcast& podcast) {
    podcast.print(ost);
    return ost;
}