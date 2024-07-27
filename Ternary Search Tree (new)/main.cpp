#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "Ternary Search Tree.h"

int main()
{
	/*TST dictionary;
	std::vector<std::string> words = { "apple", "banana", "cherry", "grape", "kiwi", "lemon", "mango", "orange", "peach", "pear", "plum", "strawberry", "watermelon" };
	std::vector<std::string> definitions = { "A fruit that is red or green", "A fruit that is yellow", "A fruit that is red", "A fruit that is purple", "A fruit that is brown", "A fruit that is yellow",  "A fruit that is green", "A fruit that is orange", "A fruit that is orange", "A fruit that is green", "A fruit that is purple", "A fruit that is red", "A fruit that is green" };
	for (size_t i = 0; i < words.size(); i++)
	{
		dictionary.insert(words[i], definitions[i]);
	}
	// Test search
	std::vector<Node*> result = dictionary.search("peach");
	for (Node* node : result)
	{
		std::cout << *node->data << std::endl;
	}
	*/

	TST dictionary;
	dictionary.readCSV("X.csv");

	return 0;
}