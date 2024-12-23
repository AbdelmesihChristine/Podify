#include "Controller.h"
#include "View.h"
#include <fstream>
#include <limits>
#include <vector>

/**
 * @brief The Controller handles application logic, bridging between 
 *        the View (UI) and the underlying data model (Podify).
 */
void Controller::launch(){
    std::cout << "Launching..." << std::endl;
    initFromFile();
    std::cout << "Done initializing" << std::endl;
    int choice = -1;

    while (true){
        choice = -1;
        std::vector<std::string> menu = {
            "Show all Podcasts",
            "Show single Podcast",
            "Get episode by host",
            "Get episode by category",
            "Get episode by host or category",
            "Print current episode list",
            "Play current episode list",
            "Toggle video"
        };
        view.menu(menu, choice);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) break;
        switch (choice)
        {
            case 1: showAllPodcasts();     break;
            case 2: showSinglePodcast();   break;
            case 3: getEpisodeByH();       break;
            case 4: getEpisodeByC();       break;
            case 5: getEpisodeByHandC();   break;
            case 6: printCurrentEpisode(); break;
            case 7: playCurrentEpisode();  break;
            case 8: toggleVideo();         break;
        }
    }
    std::cout << "Good-bye!" << std::endl;
}

void Controller::initFromFile(){
    std::ifstream episodeFile;
    episodeFile.open("media/media.txt");
    std::string podcast, host, temp;
    std::string title;
    int numEpisodes = 0;

    // Reading from file and populating the Podify object
    while(true){
        if(!getline(episodeFile, podcast)) break;
        getline(episodeFile, host);

        getline(episodeFile, temp);
        numEpisodes = std::stoi(temp);

        // Using the factory to create a new Podcast object
        av.addPodcast(pf.createPodcast(podcast, host));

        // For each line, create episodes and add them to the Podcast
        for (int i = 0; i < numEpisodes; ++i){
            getline(episodeFile, title);
            Episode* episode = pf.createEpisode(podcast, host, title);
            if (episode == nullptr){
                std::cout << "WARNING*** Episode " << title << " not found" << std::endl;
                continue;
            }
            av.addEpisode(episode, podcast);
        }
    }
    episodeFile.close();
}

void Controller::showAllPodcasts(){
    std::cout << "Showing all podcasts: " << std::endl;
    view.printAllPodcasts(av.getPodcasts());
}

void Controller::showSinglePodcast(){
    int choice = -1;
    view.podcastMenu(av.getPodcasts(), choice);
    if (choice < 0) return; // user chose 0 -> exit
    Podcast* podcast = av.getPodcast(choice);
    view.printPodcast(podcast);
}

void Controller::getEpisodeByH(){
    std::string host;
    view.promptHost(host);
    // Using the Factory to create a "host search" strategy object
    Search* crit = pf.hostSearch(host);
    playlist.clear();
    av.getEpisodes(*crit, playlist);
    delete crit;
} 

void Controller::getEpisodeByC(){
    std::string cat;
    view.promptCategory(cat);
    // Another strategy object: "category search"
    Search* crit = pf.categorySearch(cat);
    playlist.clear();
    av.getEpisodes(*crit, playlist);
    delete crit;
} 

void Controller::getEpisodeByHandC(){
    std::string host, cat;
    view.promptHost(host);
    view.promptCategory(cat);
    // Another strategy object: "host or category" search
    Search* crit = pf.hostCatSearch(host, cat);
    playlist.clear();
    av.getEpisodes(*crit, playlist);
    delete crit;
}

void Controller::printCurrentEpisode(){
    std::cout << "Playlist size: " << playlist.getSize() << std::endl;
    view.printPlaylist(playlist);
} 

void Controller::playCurrentEpisode(){
    view.playPlaylist(playlist);
}

void Controller::toggleVideo(){
    view.promptVideo();
}