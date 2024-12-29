#include "Episode.h"

Episode::Episode(const string& podcastTitle, const string& host, const string& episodeTitle,
                 const string& category, const string& audio, const string& videoFile)
    : podcastTitle(podcastTitle), host(host), episodeTitle(episodeTitle),
      category(category), audio(audio), videoFile(videoFile) {}

const string& Episode::getPodcastTitle() const {
    return podcastTitle;
}

const string& Episode::getHost() const {
    return host;
}

const string& Episode::getEpisodeTitle() const {
    return episodeTitle;
}

const string& Episode::getCategory() const {
    return category;
}

const string& Episode::getAudio() const {
    return audio;
}

const string& Episode::getVideoFile() const {
    return videoFile;
}

void Episode::print(ostream& ost) const {
    ost << "Podcast: " << podcastTitle << ", Host: " << host << ", Category: " << category
        << ", Episode: " << episodeTitle;
}

ostream& operator<<(ostream& ost, const Episode& episode) {
    episode.print(ost);
    return ost;
}