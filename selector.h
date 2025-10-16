#pragma once

#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;
 
class Selector {
	public:

		Selector();

		void selection(const int seats, string selects[]);
		int selection(const int seats);
		void results(const int seats, string selects[]);
		void results(const int seats, const int chair, string selects[]);
		bool loadCandidates();

	private:
		bool areWinSame(const int seats, string selects[]);
		
		int nominees_num;
		vector<string> candidates = {};

};