#include "Podify.h"
#include <cstdlib>

Podify::Podify() {}

Podify::~Podify() {
    // Clean up dynamically allocated Podcasts and Episodes
    for (int i = 0; i < podcasts.getSize(); ++i) {
        Podcast* podcast = podcasts[i];
        for (int j = 0; j < podcast->getSize(); ++j) {
            delete podcast->get(j);
        }
        delete podcast;
    }
}

void Podify::addPodcast(Podcast* podcast) {
    podcasts += podcast;
}

void Podify::addEpisode(Episode* episode, const string& podcastTitle) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(podcastTitle)) {
            podcasts[i]->add(episode);
            return;
        }
    }
    cerr << "Podcast not found: " << podcastTitle << endl;
}

const Array<Podcast*>& Podify::getPodcasts() const {
    return podcasts;
}

Podcast* Podify::getPodcast(int index) {
    if (index < 0 || index >= podcasts.getSize()) {
        cerr << "Podcast index out of bounds" << endl;
        exit(1);
    }
    return podcasts[index];
}

Podcast* Podify::getPodcast(const string& title) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(title)) {
            return podcasts[i];
        }
    }
    cerr << "Podcast not found: " << title << endl;
    exit(1);
}

void Podify::getEpisodes(Search& search, Array<Episode*>& matches) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        Podcast* podcast = podcasts[i];
        for (int j = 0; j < podcast->getSize(); ++j) {
            Episode* episode = podcast->get(j);
            if (search.matches(episode)) {
                matches += episode;
            }
        }
    }
}