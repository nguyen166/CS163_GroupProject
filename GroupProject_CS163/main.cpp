#include"TernarySearchTree.h"




int main() {
	TST tst;

	tst.loadCSV("Data_Storage/Eng2Eng/A.csv");
	/*tst.loadCSV("B.csv");
	tst.loadCSV("C.csv");
	tst.loadCSV("D.csv");
	tst.loadCSV("E.csv");
	tst.loadCSV("F.csv");
	tst.loadCSV("G.csv");
	tst.loadCSV("H.csv");
	tst.loadCSV("I.csv");
	tst.loadCSV("J.csv");
	tst.loadCSV("K.csv");
	tst.loadCSV("L.csv");
	tst.loadCSV("M.csv");
	tst.loadCSV("N.csv");
	tst.loadCSV("O.csv");
	tst.loadCSV("P.csv");
	tst.loadCSV("Q.csv");
	tst.loadCSV("R.csv");
	tst.loadCSV("S.csv");
	tst.loadCSV("T.csv");
	tst.loadCSV("U.csv");
	tst.loadCSV("V.csv");
	tst.loadCSV("W.csv");
	tst.loadCSV("X.csv");
	tst.loadCSV("Y.csv");
	tst.loadCSV("Z.csv");*/


	std::string search_word;

	while (true) {
		std::cout << "Enter a word to search: ";
		std::cin >> search_word;
		if (search_word == "exit") {
			break;
		}
		std::vector<std::string> meaning = tst.search(search_word);
		if (meaning.empty()) {
			std::cout << "Did you mean: \n";
			//std::vector<std::string> suggestions = spellChecking(tst, search_word, 2);
			std::vector<std::string> suggestions = tst.searchPrefix(search_word);
			for (const auto& s : suggestions) {
				std::cout << s << " \n";
			}
		}
		else {
			std::cout << "Meaning: ";
			for (const auto& m : meaning) {
				std::cout << m << " \n";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}