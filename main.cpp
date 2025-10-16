#include "main.h"

int main() {

	int conSeatsUp;
	cout << "How many seats are up?" << endl;
	cin >> conSeatsUp;
	int chair;
	string conucil[conSeatsUp];

	Selector select = Selector();

	select.loadCandidates();

	select.selection(conSeatsUp, conucil);
	chair = select.selection(conSeatsUp);

	//select.results(conSeatsUp, conucil);
	select.results(conSeatsUp, chair, conucil);
	return 0;
}

/*void results(const int seats, string selects[]) {

	cout << "Members of the city counicl are :" << endl;

	for (int i = 0; i < seats; i++) {
		cout << "City Couniclor " << selects[i] << endl;
	}
}

void results(const int seats, const int chair, string selects[]) {
	cout << "Members of the city counicl are :" << endl;
	cout << "Chair: " << selects[chair] << endl;
	cout << "City Couniclors: " << endl;

	for (int i = 0; i < seats; i++) {
		if (i != chair) {
			cout << "Couniclor " << selects[i] << endl;
		}
	}
}*/

