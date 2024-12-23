#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "Podify.h"
#include "View.h"
#include "PodcastFactory.h"

/**
 * @brief The Controller class coordinates interactions between the View
 *        and the Podify data model, including loading from file and 
 *        handling user actions.
 */
class Controller {
		
	public:
		void launch();
	
	private:
		void initFromFile();
		void showAllPodcasts();
		void showSinglePodcast();
		void getEpisodeByH(); 
		void getEpisodeByC(); 
		void getEpisodeByHandC(); 
		void printCurrentEpisode(); 
		void playCurrentEpisode(); 
		void toggleVideo(); 

		View view;
		Podify av;
		PodcastFactory pf;

        // A dynamic list of Episodes
		Array<Episode*> playlist;
};

#endif
