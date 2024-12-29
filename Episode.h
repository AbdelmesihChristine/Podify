#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

class Episode {
public:
    Episode(const string& podcastTitle, const string& host, const string& episodeTitle,
            const string& category, const string& audio, const string& videoFile);
    const string& getPodcastTitle() const;
    const string& getHost() const;
    const string& getEpisodeTitle() const;
    const string& getCategory() const;
    const string& getAudio() const;
    const string& getVideoFile() const;
    void print(ostream& ost) const;
    friend ostream& operator<<(ostream& ost, const Episode& episode);
private:
    string podcastTitle;
    string host;
    string episodeTitle;
    string category;
    string audio;
    string videoFile;
};

#endif // EPISODE_H