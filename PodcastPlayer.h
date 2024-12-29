#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include <iostream>
#include "Episode.h"

using namespace std;

class PodcastPlayer {
public:
    virtual ~PodcastPlayer() {}
    virtual void play(const Episode& episode, ostream& ost) = 0;
};

class AudioPlayer : public PodcastPlayer {
public:
    void play(const Episode& episode, ostream& ost) override;
};

class VideoPlayer : public AudioPlayer {
public:
    void play(const Episode& episode, ostream& ost) override;
};

#endif // PODCASTPLAYER_H