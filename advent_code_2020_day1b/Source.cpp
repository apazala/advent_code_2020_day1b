#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cinttypes>

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
	
	int i = 0, j = 0, k = MAXVAL+1;
	while (!found && k > 0)
	{
		k--;
		if (listed[k]) {
			i = 0, j = MAXVAL - k;
			while (!found && i < j)
			{
				i++;
				j--;
				found = listed[i] && listed[j];
			}
		}
	}


	if (!found)
		cout << "Ooops...\n";
	else {
		int64_t res = i*j;
		res *= k;
		cout << res << endl;
	}
		

	return 0;
}

