#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

/**
 * @brief Represents a single episode in a podcast, holding both audio
 *        and optional video data.
 */
class Episode {
public:
    Episode(const std::string& podcastTitle, const std::string& host,
            const std::string& episodeTitle, const std::string& category,
            const std::string& audio, const std::string& videoFile);

    const std::string& getPodcastTitle() const;
    const std::string& getHost() const;
    const std::string& getEpisodeTitle() const;
    const std::string& getCategory() const;
    const std::string& getAudio() const;
    const std::string& getVideoFile() const;

    void print(std::ostream& ost) const;

    // Friend function to use the print logic with operator<<
    friend std::ostream& operator<<(std::ostream& ost, const Episode& episode);

private:
    std::string podcastTitle;
    std::string host;
    std::string episodeTitle;
    std::string category;
    std::string audio;
    std::string videoFile;
};

#endif // EPISODE_H