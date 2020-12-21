#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define MAXVAL 2020

int main()
{
	vector<bool> listed(MAXVAL + 1, false);


	ifstream myfile("input.txt");
	if (!myfile.is_open()) {
		cout << "Unable to open input file" << endl;
		return 1;
	}

	int val;
	while (myfile >> val)
	{
		listed[val] = true;
	}
	myfile.close();

	bool found = false;
	int i = -1, j = MAXVAL + 1;
	while (!found && i < j) {
		i++;
		j--;
		found = (listed[i] && listed[j]);
	}

	if (!found)
		cout << "Ooops...\n";
	else
		cout << i*j << endl;

	return 0;
}

