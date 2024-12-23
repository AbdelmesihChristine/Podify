#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include <iostream>
#include "Episode.h"

/**
 * @brief Abstract base class (Strategy interface) for playing podcasts. 
 *        We can easily swap in AudioPlayer or VideoPlayer at runtime 
 *        (Strategy Pattern).
 */
class PodcastPlayer {
public:
    virtual ~PodcastPlayer() {}
    virtual void play(const Episode& episode, std::ostream& ost) = 0;
};

class AudioPlayer : public PodcastPlayer {
public:
    void play(const Episode& episode, std::ostream& ost) override;
};

class VideoPlayer : public AudioPlayer {
public:
    void play(const Episode& episode, std::ostream& ost) override;
};

#endif // PODCASTPLAYER_H