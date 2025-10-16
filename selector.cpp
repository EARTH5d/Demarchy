#include "selector.h"

Selector::Selector() {
	//srand(time(0));
	loadCandidates();
	nominees_num = candidates.size();
};

void Selector::selection(const int seats, string selects[]) {
	srand(time(0));
	int index = 0;
	do {
		for (int i = 0; i < seats; i++) {
			index = rand() % nominees_num;
			//cout << index << ":" << candidates.at(index) << endl;
			selects[i] = candidates.at(index);
		}
		//cout << "_______________________________________________________" << endl;
	} while (areWinSame(seats, selects));
}

int Selector::selection(const int seats) {
	srand(time(0));
	int chair;
	chair = rand() % seats;
	return chair;
}

bool Selector::areWinSame(int seats, string selects[]) {
	for (int i = 0; i < seats; i++) {
		for (int j = (i + 1); j < seats; j++) {
			if ((selects[i] == selects[j]) && (i != j)) {
				return true;
			}
		}
	}
	return false;
}

void Selector::results(const int seats, string selects[]) {

	cout << "Members of the city counicl are :" << endl;

	for (int i = 0; i < seats; i++) {
		cout << "City Couniclor " << selects[i] << endl;
	}
}

void Selector::results(const int seats, const int chair, string selects[]) {
	cout << "Members of the city counicl are :" << endl;
	cout << "Chair: " << selects[chair] << endl;
	cout << "City Couniclors: " << endl;
	
	for (int i = 0; i < seats; i++) {
		if (i != chair) {
			cout << "Couniclor " << selects[i] << endl;
		}
	}
}

bool Selector::loadCandidates() {
	ifstream nomineeFile;
	int listSize = candidates.size();
	string temp;
	nominees_num = 0;

	nomineeFile.open("candidates.txt");
	if (nomineeFile.is_open()) {
		while (!nomineeFile.eof()) {
			getline(nomineeFile, temp, '\n');
			if (nominees_num < listSize) {
				candidates.at(nominees_num) = temp;
			} else {
				candidates.push_back(temp);
				listSize = candidates.size();
				listSize *= 2;
				candidates.resize(listSize);
			}
			nominees_num++;
		}
		candidates.shrink_to_fit();
		candidates.resize(nominees_num);
		return true;
	} else {
		cout << "File does not exist." << endl;
		return false;
	}
}
