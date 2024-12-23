#include "Podify.h"
#include <cstdlib>

/**
 * @brief The Podify class aggregates all Podcasts and their Episodes, 
 *        allowing for additions and searching of episodes.
 */
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

void Podify::addEpisode(Episode* episode, const std::string& podcastTitle) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(podcastTitle)) {
            podcasts[i]->add(episode);
            return;
        }
    }
    std::cerr << "Podcast not found: " << podcastTitle << std::endl;
}

const Array<Podcast*>& Podify::getPodcasts() const {
    return podcasts;
}

Podcast* Podify::getPodcast(int index) {
    if (index < 0 || index >= podcasts.getSize()) {
        std::cerr << "Podcast index out of bounds" << std::endl;
        exit(1);
    }
    return podcasts[index];
}

Podcast* Podify::getPodcast(const std::string& title) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        if (podcasts[i]->equals(title)) {
            return podcasts[i];
        }
    }
    std::cerr << "Podcast not found: " << title << std::endl;
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