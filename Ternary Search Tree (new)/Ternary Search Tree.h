#pragma once

enum color { RED, BLACK };

class Node
{
public:
	char16_t character;
	std::string* data;
	Node* left;
	Node* right;
	Node* middle;
	Node* parent;
	bool isEOS;
	color color;
};

class TST
{
public:
	Node* root;
	Node* nil;

	void insert(std::string key, std::string data);
	std::vector<Node*> search(std::string prefix) const;
	void remove(std::string key);

	void readCSV(const std::string& filename);

	TST();
	~TST();

private:
	void left_rotate(Node*& r, Node* x);
	void right_rotate(Node*& r, Node* x);
	Node* insert_fixup(Node* r, Node* z);
	void transplant(Node*& r, Node*& u, Node*& v);
	Node* remove_fixup(Node*& r, Node*& x);
};

std::vector<Node*> spellChecking(TST& dictionary, const std::string& text, int max_wrong_char);
void dfs(Node* node, std::string& currentWord, int index, int modifications, const std::string& text, int max_wrong_char, std::vector<Node*>& result);