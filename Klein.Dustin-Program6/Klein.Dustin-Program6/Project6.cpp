#include <iostream>

using namespace std;

int tablets(int t, int i);

void main() {
	int start, moves;
	bool validEntry = false;
	char cont = 'y';

	while (cont == 'y' || cont == 'Y') {
		while (!validEntry) {
			cout << "How many tablets are you starting with? ";
			cin >> start;

			if (start > 10000)
				cout << "Enter a number less than 10,000" << endl;
			else if (start <= 0)
				cout << "Enter a number greater than 0" << endl;
			else
				validEntry = true;
		}

		moves = tablets(start, 0);
		if (moves == 21)
			cout << "No solution found within 21 moves. Sorry." << endl;
		else
			cout << "Found solution. I have exactly 18 Tablets, with " << 21 - moves << " moves left." << endl;

		cout << "Would you like go again? [Y/N] ";
		cin >> cont;

		validEntry = false;
	}
}

int tablets(int t, int i) {
	if (i == 21) {
		return i;
	}

	if (t == 18) {
		return i;
	}
	else if (t % 2 == 1) {
		cout << "After incrementing, Reduce " << t + 1 << " by half to get " << (t + 1) / 2 << "." << endl;
		return tablets((t + 1) / 2, i + 1);
	}
	else if (t % 3 == 0) {
		if (i < 5) {
			if (((t / 3) + 24) % 3 == 0) {
				cout << "With " << t << ", divide by three to get " << t / 3 << "." << endl;
				return tablets(t / 3, i + 1);
			}
			else {
				cout << "With " << t << ", add 24 to get " << t + 24 << "." << endl;
				return tablets(t + 24, i + 1);
			}
		}
		else {
			cout << "With " << t << ", divide by three to get " << t / 3 << "." << endl;
			return tablets(t / 3, i + 1);
		}
	}
	else {
		cout << "With " << t << ", add 24 to get " << t + 24 << "." << endl;
		return tablets(t + 24, i + 1);
	}
}