#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Podcast.h"
#include "PodcastPlayer.h"
#include "Array.h"

using namespace std;

class View {
public:
    View();
    void menu(vector<string>&, int& choice);
    void printAllPodcasts(const Array<Podcast*>& podcasts);
    void podcastMenu(const Array<Podcast*>& podcasts, int& choice);
    void printPodcast(const Podcast* podcast);
    void promptHost(string& host);
    void promptCategory(string& category);
    void printPlaylist(const Array<Episode*>& episodes);
    void playPlaylist(const Array<Episode*>& episodes);
    void promptVideo();
    void toggleVideo(bool video);

private:
    PodcastPlayer* player;
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;
};

#endif // VIEW_H