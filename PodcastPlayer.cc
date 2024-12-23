#include "PodcastPlayer.h"
#include <fstream>

/**
 * @brief The strategy for playing audio-only or audio+video episodes.
 * 
 * AudioPlayer is the "base strategy".
 * VideoPlayer extends AudioPlayer with video playback (diamond inheritance
 * is not here, but the pattern is that View can switch between these strategies).
 */
void AudioPlayer::play(const Episode& episode, std::ostream& ost) {
    ost << "Playing audio: " << episode.getAudio() << std::endl;
}

void VideoPlayer::play(const Episode& episode, std::ostream& ost) {
    // First play the audio
    AudioPlayer::play(episode, ost);

    // Then attempt to play video
    std::ifstream file(episode.getVideoFile());
    if (!file) {
        ost << "Unable to open video file: " << episode.getVideoFile() << std::endl;
        return;
    }
    ost << "Playing video from: " << episode.getVideoFile() << std::endl;
    std::string line;
    while (getline(file, line)) {
        ost << line << std::endl;
    }
    file.close();
}