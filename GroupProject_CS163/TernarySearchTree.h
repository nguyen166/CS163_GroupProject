#ifndef TERNARYSEARCHTREE_H
#define TERNARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include <vector>


class TSTNode {
public:
    char key;                
    TSTNode* left;          
    TSTNode* middle;        
    TSTNode* right;        
    int priority;           
    bool is_end_of_string;  
    std::vector<std::string> meaning; 

    TSTNode(char key)
        : key(key), left(nullptr), middle(nullptr), right(nullptr),
        priority(rand() % 100), is_end_of_string(false) {}
};

class TST {
private:
    TSTNode* root;
    // Helper function to insert a word into the TST
    TSTNode* _insert(TSTNode* node, const std::string& word, const std::string& meaning, int index);

    // Helper function to rebalance the TST
    TSTNode* _rebalance(TSTNode* node);

    // Helper function to perform a right rotation
    TSTNode* _right_rotate(TSTNode* node);

    // Helper function to perform a left rotation
    TSTNode* _left_rotate(TSTNode* node);

    // Helper function to search for a word and return its meaning
    std::vector<std::string> _search(TSTNode* node, const std::string& word, int index);
    TSTNode* _remove(TSTNode* node, const std::string& word, int index);
    TSTNode* _searchPrefix(TSTNode* node, std::string prefix, int indexx);
    void _collect(TSTNode* node, std::string prefix, std::vector<std::string>& result);
public:
    
    TST() : root(nullptr) {
        std::srand(std::time(nullptr)); 
    }
    TSTNode* getRoot() { return root; }

    void insert(const std::string& word, const std::string& meaning);
    std::vector<std::string> search(const std::string& word);
    void loadCSV(const std::string& filename);
	void remove(const std::string& word);
	std::vector<std::string> searchPrefix(const std::string& prefix);
   
	

};
std::vector<std::string> spellChecking(TST& dictionary, const std::string& text, int max_wrong_char);
void dfs(TSTNode* node, std::string& currentWord, int index, int modifications, const std::string& text, int max_wrong_char, std::vector<std::string>& result);

#endif // !TERNARYSEARCHTREE_H
