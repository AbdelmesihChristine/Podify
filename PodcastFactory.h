#ifndef PODCASTFACTORY_H
#define PODCASTFACTORY_H

#include <iostream>
#include <string>
#include "Podcast.h"
#include "Search.h"
#include "Episode.h"

/**
 * @brief A Factory class to create Podcast, Episode, and Search objects, 
 *        decoupling object creation logic from the rest of the application.
 */
class PodcastFactory {
public:
    // create an Episode
    Episode* createEpisode(const std::string& pod, const std::string& host, const std::string& title);

    // create a Podcast
    Podcast* createPodcast(const std::string& title, const std::string& host);

    // create a Search object
    Search* hostSearch(const std::string& host);
    Search* categorySearch(const std::string& category);
    Search* hostCatSearch(const std::string& artist, const std::string& category);
};

#endif