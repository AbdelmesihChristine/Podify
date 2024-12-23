#include "View.h"
#include <limits>
#include <vector>
#include <cstdlib>
#include <sstream> 

View::View() {
    player = &audioPlayer; 
}

void View::menu(vector<string>& menu, int& choice) {
    cout << endl;
    cout << "Please make a selection:" << endl << endl;
    for (int i = 0; i < menu.size(); ++i) {
        cout << "  (" << i + 1 << ") " << menu[i] << endl;
    }
    cout << "  (0) Exit" << endl << endl;

    string input;
    while (true) {
        cout << "Enter your selection: ";
        getline(cin, input);

        stringstream ss(input);
        if (ss >> choice && ss.eof() && choice >= 0 && choice <= menu.size()) {
            break;
        }
        cout << "Invalid selection. Please enter a number between 0 and " << menu.size() << "." << endl;
    }
}

void View::printAllPodcasts(const Array<Podcast*>& podcasts) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        cout << i + 1 << ": " << *podcasts[i] << endl;
    }
}

void View::podcastMenu(const Array<Podcast*>& podcasts, int& choice) {
    int numOptions = podcasts.getSize();

    printAllPodcasts(podcasts);

    cout << endl;
    cout << "Choose a podcast" << endl;
    cout << "or select (0) to exit" << endl;

    string input;
    while (true) {
        cout << "Enter your selection: ";
        getline(cin, input);

        stringstream ss(input);
        if (ss >> choice && ss.eof() && choice >= 0 && choice <= numOptions) {
            break;
        }
        cout << "Invalid selection. Please enter a number between 0 and " << numOptions << "." << endl;
    }
    if (choice == 0)
        return;
    --choice; 
}

void View::printPodcast(const Podcast* podcast) {
    podcast->printWithEpisodes(cout);
}

void View::promptHost(string& host) {
    cout << "Enter host: ";
    getline(cin, host);
}

void View::promptCategory(string& category) {
    cout << "Enter category: ";
    getline(cin, category);
}

void View::printPlaylist(const Array<Episode*>& episodes) {
    for (int i = 0; i < episodes.getSize(); ++i) {
        cout << *episodes[i] << endl;
    }
}

void View::playPlaylist(const Array<Episode*>& episodes) {
    cout << "Playing playlist of size " << episodes.getSize() << endl;
    for (int i = 0; i < episodes.getSize(); ++i) {
        cout << endl << *episodes[i] << endl;
        player->play(*episodes[i], cout);
        cout << endl;
    }
}

void View::promptVideo() {
    cout << endl;
    cout << "  (0) Exit (no change)" << endl;
    cout << "  (1) Audio player only" << endl;
    cout << "  (2) Audio and Video player" << endl << endl;

    string input;
    int choice = -1;

    while (true) {
        cout << "Enter your selection: ";
        getline(cin, input);

        stringstream ss(input);
        if (ss >> choice && ss.eof() && choice >= 0 && choice <= 2) {
            break;
        }
        cout << "Invalid selection. Please enter 0, 1, or 2." << endl;
    }

    if (choice == 0)
        return;

    toggleVideo(choice == 2);
}

void View::toggleVideo(bool video) {
    if (video) {
        player = &videoPlayer;
    } else {
        player = &audioPlayer;
    }
}