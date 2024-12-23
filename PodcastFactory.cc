#include "PodcastFactory.h"
#include <fstream>
#include <limits>

/**
 * @brief The PodcastFactory is used to create new Podcast or Episode objects,
 *        as well as different Search "strategy" objects.
 * 
 * Using a factory method keeps object creation separate from the core
 * application logic, allowing easy modifications later (e.g., different 
 * types of Episodes, special subclasses, etc.).
 */
Episode* PodcastFactory::createEpisode(const std::string& pod, 
                                       const std::string& host, 
                                       const std::string& epTitle)
{
    std::cout << "Attempting to load episode " << epTitle << std::endl;
    std::ifstream podFile;
    podFile.open("media/media2.txt");
    std::string episodeTitle, category, content, videoFile;

    while(true){
        if(!getline(podFile, episodeTitle)) break;
        if (epTitle == episodeTitle){
            // found the correct Episode
            getline(podFile, category);
            getline(podFile, content);
            getline(podFile, videoFile);
            return new Episode(pod, host, episodeTitle, category, content, "videos/" + videoFile);
        } else {
            // skip lines we don't need
            podFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            podFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            podFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');    
        }
    }
    std::cout << "Episode " << epTitle << " not found." << std::endl;
    return nullptr;
}

Podcast* PodcastFactory::createPodcast(const std::string& episodeTitle, 
                                       const std::string& owner)
{
    return new Podcast(episodeTitle, owner);
}

Search* PodcastFactory::hostSearch(const std::string& host){
    return new H_Search(host);
}

Search* PodcastFactory::categorySearch(const std::string& category){
    return new C_Search(category);
}

Search* PodcastFactory::hostCatSearch(const std::string& host, 
                                      const std::string& category)
{
    return new HorC_Search(host, category);
}