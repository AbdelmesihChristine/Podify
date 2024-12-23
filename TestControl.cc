#include "TestControl.h"
#include <limits>
#include <vector>
#include <algorithm>
#include "Search.h"

/**
 * @brief The TestControl runs a series of tests (like a mini test harness).
 */

using namespace std;

void TestControl::launch(){

    vector<string> menu = {
        "Test add and print Podcasts",
        "Test add and print Episodes",
        "Test get Episodes by host (and demonstration of print in View class)",
        "Test get Episodes by category",
        "Test get Episodes by host or category",
        "Test play current episode list (with video)",
        "Run all tests"
    };

    int choice = -1;

    while (choice != 0){
        view.menu(menu, choice);
        tester.clearInputBuffer();
        switch(choice){
            case 1: 
                testAddPodcasts();
                break;
            case 2: 
                testAddEpisodes();
                break;
            case 3: 
                testGetEpisodesByHost();
                break;
            case 4: 
                testGetEpisodesByCategory();
                break;
            case 5: 
                testGetEpisodesByHostAndCategory();
                break;
            case 6: 
                testPlayCurrentEpisodeList();
                break;
            case 7: 
                testAllAndMark();
                break;
        }
    }
    std::cout << "Exiting test program." << endl;
}

/**
 * @brief Helper function to load only podcasts (no episodes) for testing.
 */
void TestControl::initPodcasts(Podify& podify, vector<string>& podcasts, vector<string>& hosts){
    ifstream podFile;
    podFile.open("media/media.txt");
    string podcast, host, temp;
    string title;
    int numEpisodes = 0;

    while(true){
        if(!getline(podFile, podcast)) break;
        getline(podFile, host);
        getline(podFile, temp);
        numEpisodes = stoi(temp);

        podify.addPodcast(pf.createPodcast(podcast, host));
        podcasts.push_back(podcast);
        hosts.push_back(host);

        // Skip reading the episode titles (but still read them)
        for (int i = 0; i < numEpisodes; ++i){
            getline(podFile, title);
        }
    }
    podFile.close();
}

/**
 * @brief Helper function to load both podcasts and episodes for testing.
 */
void TestControl::initWithEpisodes(Podify& podify,
                                   vector<string>& podcasts, 
                                   vector<string>& hosts, 
                                   vector<string>& epTitles)
{
    ifstream podFile;
    podFile.open("media/media.txt");
    string podcast, host, temp;
    string title;
    int numEpisodes = 0;

    while(true){
        if(!getline(podFile, podcast)) break;
        getline(podFile, host);
        getline(podFile, temp);
        numEpisodes = stoi(temp);

        epTitles.push_back(podcast);
        epTitles.push_back(temp); // store number of episodes as string

        podcasts.push_back(podcast);
        hosts.push_back(host);
        podify.addPodcast(pf.createPodcast(podcast, host));

        for (int i = 0; i < numEpisodes; ++i){
            getline(podFile, title);
            Episode* episode = pf.createEpisode(podcast, host, title);
            if (episode == nullptr){
                cout << "WARNING*** Episode " << title << " not found" << endl;
                continue;
            } else {
                epTitles.push_back(title);
            }
            podify.addEpisode(episode, podcast);
        }
    }
    podFile.close();
}

void TestControl::testAddPodcasts(){
    cout << "\n[TEST] Testing addPodcasts()..." << endl;
    Podify podify;
    vector<string> podcasts;
    vector<string> hosts;
    initPodcasts(podify, podcasts, hosts);

    cout << "\nNow printing all podcasts:\n" << endl;
    tester.initCapture();
    view.printAllPodcasts(podify.getPodcasts());
    tester.endCapture();

    int error = 0;
    // Check if each title and host is present in the captured output
    tester.find(podcasts, error);
    tester.find(hosts, error);

    if (error > 0){
        cout << "[RESULT] Some podcasts or hosts were missing in the output." << endl;
    } else {
        cout << "[RESULT] All podcasts and hosts are present in the output." << endl;
    }
    cout << "[TEST COMPLETE]\n" << endl;
}

void TestControl::testAddEpisodes(){
    cout << "\n[TEST] Testing addEpisodes()..." << endl;
    Podify podify;
    vector<string> podcasts;
    vector<string> hosts;
    vector<string> epTitles;
    initWithEpisodes(podify, podcasts, hosts, epTitles);

    cout << "\nPrinting podcasts with episodes:\n" << endl;
    int errors = 0;
    int index = 0;
    for (int i = 0; i < podify.getPodcasts().getSize(); ++i){
        tester.initCapture();
        podify.getPodcast(i)->printWithEpisodes(cout);
        tester.endCapture();

        string podcast = epTitles[index++];
        int numEps = stoi(epTitles[index++]);
        vector<string> episodes;
        for (int j = 0; j < numEps; ++j){
            episodes.push_back(epTitles[index++]);
        }
        int error = 0;
        tester.find(episodes, error);
        errors += error;
    }
    if (errors > 0){
        cout << "[RESULT] Some episodes were missing in the output." << endl;
    } else {
        cout << "[RESULT] All episodes found for each podcast." << endl;
    }
    cout << "[TEST COMPLETE]\n" << endl;
}

void TestControl::testGetEpisodesByHost(){
    cout << "\n[TEST] Testing getEpisodesByHost and playPlaylist..." << endl;
    Podify podify;
    vector<string> podcasts;
    vector<string> hosts;
    vector<string> epTitles;
    initWithEpisodes(podify, podcasts, hosts, epTitles);

    // We'll just randomly pick some hosts to demonstrate.
    vector<int> findHosts;
    int numHosts = 5;
    tester.ran(findHosts, 2, numHosts); // pick 2 random hosts from first 5

    for (auto hostIndex : findHosts){
        Search* search = pf.hostSearch(hosts[hostIndex]);
        Array<Episode*> episodes;
        podify.getEpisodes(*search, episodes);
        delete search;

        cout << "Playing episodes by host \"" << hosts[hostIndex] << "\"..." << endl;
        tester.initCapture();
        view.playPlaylist(episodes);
        tester.endCapture();
    }

    cout << "[TEST COMPLETE]\n" << endl;
}

void TestControl::testGetEpisodesByCategory(){
    cout << "\n[TEST] Testing getEpisodesByCategory..." << endl;
    Podify podify;
    vector<string> podcasts;
    vector<string> hosts;
    vector<string> epTitles;
    initWithEpisodes(podify, podcasts, hosts, epTitles);

    // For simplicity, we just pick a couple categories at random
    string categories[] = {"History", "Local", "R&B", "Parody", "Grunge", "Politics", "Health"};
    int numCats = 7;
    vector<int> findCats;
    tester.ran(findCats, 2, numCats);

    for (auto catIndex : findCats){
        Search* search = pf.categorySearch(categories[catIndex]);
        Array<Episode*> episodes;
        podify.getEpisodes(*search, episodes);
        delete search;

        cout << "Playing episodes in category \"" << categories[catIndex] << "\"..." << endl;
        view.playPlaylist(episodes);
    }

    cout << "[TEST COMPLETE]\n" << endl;
}

void TestControl::testGetEpisodesByHostAndCategory(){
    cout << "\n[TEST] Testing getEpisodesByHostAndCategory (OR logic)..." << endl;
    Podify podify;
    vector<string> podcasts;
    vector<string> hosts;
    vector<string> epTitles;
    initWithEpisodes(podify, podcasts, hosts, epTitles);

    // We'll pick a random host and a random category
    string categories[] = {"History", "Local", "R&B", "Parody", "Grunge", "Politics", "Health"};
    int catIndex = tester.ran(0, 7);
    int hostIndex = tester.ran(0, 5);

    Search* search = pf.hostCatSearch(hosts[hostIndex], categories[catIndex]);
    Array<Episode*> episodes;
    podify.getEpisodes(*search, episodes);
    delete search;

    cout << "Playing episodes by host \"" << hosts[hostIndex] 
         << "\" or category \"" << categories[catIndex] << "\"...\n" << endl;
    view.playPlaylist(episodes);

    cout << "[TEST COMPLETE]\n" << endl;
}

void TestControl::testPlayCurrentEpisodeList(){
    cout << "\n[TEST] Testing play current episode list (with video)..." << endl;
    Podify podify;
    vector<string> podcasts;
    vector<string> hosts;
    vector<string> epTitles;
    initWithEpisodes(podify, podcasts, hosts, epTitles);

    string host = "Bif";  // pick a known host from your data, e.g. Bif
    Search* search = pf.hostSearch(host);
    Array<Episode*> episodes;
    podify.getEpisodes(*search, episodes);
    delete search;

    // Enable video strategy
    view.toggleVideo(true);
    cout << "Playing episodes (with video) for host \"" << host << "\"...\n" << endl;

    tester.initCapture();
    view.playPlaylist(episodes);
    tester.endCapture();

    // Switch back to audio
    view.toggleVideo(false);

    cout << "[TEST COMPLETE]\n" << endl;
}

void TestControl::testAllAndMark(){
    cout << "\n[TEST] Running all tests sequentially...\n" << endl;
    testAddPodcasts();
    testAddEpisodes();
    testGetEpisodesByHost();
    testGetEpisodesByCategory();
    testGetEpisodesByHostAndCategory();
    testPlayCurrentEpisodeList();
    cout << "[ALL TESTS COMPLETED SUCCESSFULLY]\n" << endl;
}