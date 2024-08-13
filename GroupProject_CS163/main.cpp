#include"TernarySearchTree.h"
#include "SuffixArray.h"
#include <fstream>
using namespace std;



int main() {
	TST tst;

	for (char c = 'A'; c <= 'Z'; c++) {
		string s = "Data_Storage/Eng2Eng/Origin/";
		s += c;
		s += ".csv";
		tst.loadCSV(s);
	}
	ifstream fin;
	ofstream fout;

	fin.open("Data_Storage/Eng2Eng/Games/Words/EasyMode.txt");
	fout.open("Data_Storage/Eng2Eng/Games/Definitions/HardMode.txt");
	
	string word;
	// Read text file, each line is one word
	while (getline(fin, word))
	{
		vector<string> defs;
		defs = tst.search(word);
		if (defs.size() != 0) {
			fout << defs[0] << endl;
			cout << word << endl;
		}
	}
	fin.close();

	fin.open("Data_Storage/Eng2Eng/Games/Words/MediumMode.txt");
	// Read text file, each line is one word
	while (getline(fin, word))
	{
		vector<string> defs;
		defs = tst.search(word);
		if (defs.size() != 0) {
			fout << defs[0] << endl;
			cout << word << endl;
		}
	}
	fin.close();

	fin.open("Data_Storage/Eng2Eng/Games/Words/HardMode.txt");
	// Read text file, each line is one word
	while (getline(fin, word))
	{
		vector<string> defs;
		defs = tst.search(word);
		if (defs.size() != 0) {
			fout << defs[0] << endl;
			cout << word << endl;
		}
	}
	fin.close();
	fout.close();


	return 0;
}
