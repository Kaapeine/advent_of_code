#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main(int argc, char** argv) {
	ifstream InputFile("input.txt");

	string myText;

	int maxCal = 0;
	int currCal = 0;

	priority_queue<int> calQ;

	while (getline (InputFile, myText)) {
		if (myText.empty()) {
			if (currCal >= maxCal)
				maxCal = currCal;
			calQ.push(currCal);
			currCal = 0;
		}
		else {
			currCal += stoi(myText);
		}
	}

	cout << "Max cal is: " << maxCal << endl;
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += calQ.top();
		cout << calQ.top() << endl;
		calQ.pop();
	}

	cout << "Sum of top 3: " << sum << endl;

	InputFile.close();

	return 0;
}
