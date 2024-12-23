#include "Episode.h"

/**
 * @brief Implementation of an Episode, containing references to audio/video data.
 */
Episode::Episode(const std::string& podcastTitle, const std::string& host,
                 const std::string& episodeTitle, const std::string& category,
                 const std::string& audio, const std::string& videoFile)
    : podcastTitle(podcastTitle), host(host), episodeTitle(episodeTitle),
      category(category), audio(audio), videoFile(videoFile) {}

const std::string& Episode::getPodcastTitle() const {
    return podcastTitle;
}

const std::string& Episode::getHost() const {
    return host;
}

const std::string& Episode::getEpisodeTitle() const {
    return episodeTitle;
}

const std::string& Episode::getCategory() const {
    return category;
}

const std::string& Episode::getAudio() const {
    return audio;
}

const std::string& Episode::getVideoFile() const {
    return videoFile;
}

void Episode::print(std::ostream& ost) const {
    ost << "Podcast: " << podcastTitle 
        << ", Host: " << host 
        << ", Category: " << category
        << ", Episode: " << episodeTitle;
}

// Overloaded operator<< to print Episode objects
std::ostream& operator<<(std::ostream& ost, const Episode& episode) {
    episode.print(ost);
    return ost;
}