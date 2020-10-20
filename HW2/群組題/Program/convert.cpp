/**
* CONVERTING BINARY TO DECIMAL IN C++
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <climits>

using namespace std;

const size_t maxBits = sizeof(short) * CHAR_BIT;

int main(int argc, char *argv[]) {
	string line;
	bool inputOk;
	short n;

	while (true) {
		cout << "Enter binary number (" << maxBits;
		cout << " bits or less) : " << endl;
		do {
			cout << "> ";
			getline(cin,line);
			inputOk = true;
			for (size_t i = 0; (i < line.size()) && (inputOk == true); i++) {
				if ((line[i] != '0') && (line[i] != '1')) {
					inputOk = false;
					cout << "non-bit entered" << endl;
				}
			}
			if ((inputOk == true) && (line.size() > maxBits)) {
				inputOk = false;
				cout << "too big for " << maxBits << "-bit integer" << endl;
			}
		} while (inputOk == false);

		// Convert string of bits to an integer
		n = 0;
		for (int i = line.size()-1, j = 0; i >= 0; --i,j++) {
			n |= (line[i] - '0') << j;
		}
		cout << line << " = " << n << endl;
	}
	return 0;
}