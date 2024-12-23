#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Podcast.h"
#include "PodcastPlayer.h"
#include "Array.h"

/**
 * @brief The View class handles user input/output and uses a PodcastPlayer 
 *        strategy to play episodes (AudioPlayer or VideoPlayer).
 */
class View {
public:
    View();
    void menu(std::vector<std::string>&, int& choice);
    void printAllPodcasts(const Array<Podcast*>& podcasts);
    void podcastMenu(const Array<Podcast*>& podcasts, int& choice);
    void printPodcast(const Podcast* podcast);
    void promptHost(std::string& host);
    void promptCategory(std::string& category);
    void printPlaylist(const Array<Episode*>& episodes);
    void playPlaylist(const Array<Episode*>& episodes);
    void promptVideo();
    void toggleVideo(bool video);

private:
    // Strategy Pattern: we hold a pointer to an abstract base class
    PodcastPlayer* player;
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;
};

#endif // VIEW_H