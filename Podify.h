#ifndef PODIFY_H
#define PODIFY_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Podcast.h"
#include "Episode.h"
#include "Search.h"

/**
 * @brief The core data model, holding all available Podcasts. 
 *        It uses the Array<T> template for storage.
 */
class Podify {
public:
    Podify();
    ~Podify();
    void addPodcast(Podcast* podcast);
    void addEpisode(Episode* episode, const std::string& podcastTitle);
    const Array<Podcast*>& getPodcasts() const;
    Podcast* getPodcast(int index);
    Podcast* getPodcast(const std::string& title);
    void getEpisodes(Search& search, Array<Episode*>& matches);

private:
    Array<Podcast*> podcasts;
};

#endif // PODIFY_H