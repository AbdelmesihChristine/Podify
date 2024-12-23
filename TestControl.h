#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "Podify.h"
#include "View.h"
#include "Tester.h"
#include "PodcastFactory.h"
#include <fstream>

/**
 * @brief Orchestrates a series of tests, using Podify, View, and 
 *        the Tester utility to confirm correct behaviors.
 */
class TestControl {
public:
	void launch();
	
private:
	void initPodcasts(Podify& podify, std::vector<std::string>& podcasts, std::vector<std::string>& hosts);
	void initWithEpisodes(Podify& podify, 
						  std::vector<std::string>& podcasts, 
						  std::vector<std::string>& hosts, 
						  std::vector<std::string>& epTitles);

	void testAddPodcasts();
	void testAddEpisodes();
	void testGetEpisodesByHost();
	void testGetEpisodesByCategory();
	void testGetEpisodesByHostAndCategory();
	void testPlayCurrentEpisodeList();
	void testAllAndMark();

	View view;
	Tester tester;
	PodcastFactory pf;	
};

#endif