#include "PodcastPlayer.h"
#include <fstream>

void AudioPlayer::play(const Episode& episode, ostream& ost) {
    ost << "Playing audio: " << episode.getAudio() << endl;
}

void VideoPlayer::play(const Episode& episode, ostream& ost) {
    AudioPlayer::play(episode, ost); // Play audio
    // Load and display video (ASCII art) from file
    ifstream file(episode.getVideoFile());
    if (!file) {
        ost << "Unable to open video file: " << episode.getVideoFile() << endl;
        return;
    }
    ost << "Playing video from: " << episode.getVideoFile() << endl;
    string line;
    while (getline(file, line)) {
        ost << line << endl;
    }
    file.close();
}