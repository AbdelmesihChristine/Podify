#include "View.h"
#include <limits>
#include <vector>
#include <cstdlib>
#include <sstream>

/**
 * @brief The View class is responsible for interacting with the user 
 *        (input/output) and using a PodcastPlayer strategy (Audio or Video).
 * 
 * It demonstrates the **Strategy Pattern**:
 *   - `player` is a pointer to a PodcastPlayer.
 *   - We can switch it at runtime (toggleVideo) between AudioPlayer or VideoPlayer.
 */
View::View() {
    player = &audioPlayer; 
}

void View::menu(std::vector<std::string>& menu, int& choice) {
    std::cout << std::endl;
    std::cout << "Please make a selection:" << std::endl << std::endl;
    for (int i = 0; i < (int)menu.size(); ++i) {
        std::cout << "  (" << i + 1 << ") " << menu[i] << std::endl;
    }
    std::cout << "  (0) Exit" << std::endl << std::endl;

    std::string input;
    while (true) {
        std::cout << "Enter your selection: ";
        getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> choice && ss.eof() && choice >= 0 && choice <= (int)menu.size()) {
            break;
        }
        std::cout << "Invalid selection. Please enter a number between 0 and " 
                  << menu.size() << "." << std::endl;
    }
}

void View::printAllPodcasts(const Array<Podcast*>& podcasts) {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        std::cout << i + 1 << ": " << *podcasts[i] << std::endl;
    }
}

void View::podcastMenu(const Array<Podcast*>& podcasts, int& choice) {
    int numOptions = podcasts.getSize();
    printAllPodcasts(podcasts);

    std::cout << std::endl;
    std::cout << "Choose a podcast" << std::endl;
    std::cout << "or select (0) to exit" << std::endl;

    std::string input;
    while (true) {
        std::cout << "Enter your selection: ";
        getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> choice && ss.eof() && choice >= 0 && choice <= numOptions) {
            break;
        }
        std::cout << "Invalid selection. Please enter a number between 0 and " 
                  << numOptions << "." << std::endl;
    }
    if (choice == 0) return;
    --choice; 
}

void View::printPodcast(const Podcast* podcast) {
    podcast->printWithEpisodes(std::cout);
}

void View::promptHost(std::string& host) {
    std::cout << "Enter host: ";
    getline(std::cin, host);
}

void View::promptCategory(std::string& category) {
    std::cout << "Enter category: ";
    getline(std::cin, category);
}

void View::printPlaylist(const Array<Episode*>& episodes) {
    for (int i = 0; i < episodes.getSize(); ++i) {
        std::cout << *episodes[i] << std::endl;
    }
}

void View::playPlaylist(const Array<Episode*>& episodes) {
    std::cout << "Playing playlist of size " << episodes.getSize() << std::endl;
    for (int i = 0; i < episodes.getSize(); ++i) {
        std::cout << std::endl << *episodes[i] << std::endl;
        player->play(*episodes[i], std::cout);
        std::cout << std::endl;
    }
}

void View::promptVideo() {
    std::cout << std::endl;
    std::cout << "  (0) Exit (no change)" << std::endl;
    std::cout << "  (1) Audio player only" << std::endl;
    std::cout << "  (2) Audio and Video player" << std::endl << std::endl;

    std::string input;
    int choice = -1;

    while (true) {
        std::cout << "Enter your selection: ";
        getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> choice && ss.eof() && choice >= 0 && choice <= 2) {
            break;
        }
        std::cout << "Invalid selection. Please enter 0, 1, or 2." << std::endl;
    }

    if (choice == 0) return;

    toggleVideo(choice == 2);
}

void View::toggleVideo(bool video) {
    if (video) {
        player = &videoPlayer;
    } else {
        player = &audioPlayer;
    }
}
