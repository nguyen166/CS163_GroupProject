#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include<iostream>

#include "Ternary Search Tree.h"

std::ofstream fout;
std::ifstream fin;


TST::TST()
{
	this->nil = new Node;
	this->nil->color = BLACK;
	this->root = this->nil;
}

TST::~TST()
{
	std::stack<Node*> stack;
	stack.push(this->root);
	while (!stack.empty())
	{
		Node* node = stack.top();
		stack.pop();
		if (node != this->nil)
		{
			stack.push(node->left);
			stack.push(node->middle);
			stack.push(node->right);
			delete node;
		}
	}
	delete this->nil;
}

void TST::insert(std::string key, std::string data)
{
	Node* z = new Node;
	int i = 0;
	z->character = key[i];
	Node* x = this->root;
	Node* y = this->nil;
	while (x != this->nil)
	{
		y = x;
		if (z->character < x->character)
		{
			x = x->left;
		}
		else if (z->character > x->character)
		{
			x = x->right;
		}
		else
		{
			if (i == key.size() - 1)
			{
				if (x->isEOS)
				{
					*x->data += ' ' + key + ": " + data;
				}
				else
				{
					x->data = new std::string(key + ": " + data);
					x->isEOS = true;
				}
				delete z;
				return;
			}
			x = x->middle;
			i++;
			z->character = key[i];
		}
	}
	if (y == this->nil)
	{
		this->root = z;
	}
	else if (z->character < y->character)
	{
		y->left = z;
	}
	else if (z->character > y->character)
	{
		y->right = z;
	}
	else if (i < key.size() - 1)
	{
		y->middle = z;
	}
	z->parent = y;

	Node* t = z;
	i++;
	while (i < key.size())
	{
		Node* temp = new Node;
		temp->parent = t;
		temp->left = this->nil;
		temp->right = this->nil;
		temp->middle = this->nil;
		temp->isEOS = false;
		temp->color = BLACK;
		temp->character = key[i];
		t->middle = temp;
		t = t->middle;
		i++;
	}
	t->data = new std::string(key + ": " + data);
	t->isEOS = true;

	if (z == t)
	{
		z->left = this->nil;
		z->right = this->nil;
		z->middle = this->nil;
		z->color = BLACK;
		return;
	}
	if (z != z->parent->middle)
	{
		z->color = RED;
		z->left = this->nil;
		z->right = this->nil;
		z->isEOS = false;
		Node* r = z;
		while (r->parent != this->nil && r != r->parent->middle)
		{
			r = r->parent;
		}
		Node* temp = r->parent;
		r->parent = this->nil;
		r = insert_fixup(r, z);
		r->parent = temp;
		if (temp == this->nil)
		{
			this->root = r;
		}
	}
	else
	{
		z->color = BLACK;
		z->left = this->nil;
		z->right = this->nil;
		z->isEOS = false;
	}
}

std::vector<Node*> TST::search(std::string prefix) const
{
	std::vector<Node*> result;
	Node* x = this->root;
	size_t i = 0;
	while (x != this->nil && i < prefix.size())
	{
		if (prefix[i] < x->character)
		{
			x = x->left;
		}
		else if (prefix[i] > x->character)
		{
			x = x->right;
		}
		else
		{
			if (i == prefix.size() - 1)
			{
				break;
			}
			x = x->middle;
			i++;
		}
	}
	if (x != this->nil)
	{
		std::stack<Node*> stack;
		stack.push(x);
		while (!stack.empty())
		{
			Node* node = stack.top();
			stack.pop();
			if (node->isEOS)
			{
				result.push_back(node);
			}
			if (node->right != this->nil)
			{
				stack.push(node->right);
			}
			if (node->middle != this->nil)
			{
				stack.push(node->middle);
			}
			if (node->left != this->nil)
			{
				stack.push(node->left);
			}
		}
	}
	return result;
}

void TST::remove(std::string key)
{
	Node* z = this->root;
	// Find z
	size_t i = 0;
	while (z != this->nil && i < key.size())
	{
		if (key[i] < z->character)
		{
			z = z->left;
		}
		else if (key[i] > z->character)
		{
			z = z->right;
		}
		else
		{
			if (i == key.size() - 1)
			{
				break;
			}
			z = z->middle;
			i++;
		}
	}
}

void TST::readCSV(const std::string& filename)
{
	fin.open(filename);
	if (!fin.is_open())
	{
		return;
	}
	std::string line;
	while (std::getline(fin, line))
	{
		if (line.empty())
			continue;
		std::string key;
		std::string data;
		size_t i = 0;
		while (i < line.size() && line[i] != ' ')
		{
			key.push_back(line[i]);
			i++;
		}
		i++;
		while (i < line.size())
		{
			data.push_back(line[i]);
			i++;
		}
		this->insert(key, data);
	}
	fin.close();
}

Node* TST::left_rotate(Node*& r, Node* x)
{
	Node* y = x->right;
	x->right = y->left;
	if (y->left != this->nil)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	std::cout << "y: " << y->character << " " << y->parent->character << "\n";
	if (x->parent == this->nil)
	{
		r = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
	return y;
}

Node* TST::right_rotate(Node*& r, Node* x)
{
	Node* y = x->left;
	x->left = y->right;
	if (y->right != this->nil)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x == this->nil)
	{
		r = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
	return y;
}

Node* TST::insert_fixup(Node* r, Node*& z)
{
	while (z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			Node* y = z->parent->parent->right;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right)
				{
					z = z->parent;
					z = left_rotate(r, z)->left;
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				z->parent->parent = right_rotate(r, z->parent->parent)->parent;
			}
		}
		else
		{
			Node* y = z->parent->parent->left;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					z = right_rotate(r, z)->right;
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				z->parent->parent = left_rotate(r, z->parent->parent)->parent;
			}
		}
	}
	r->color = BLACK;
	return r;
}

void TST::transplant(Node*& r, Node*& u, Node*& v)
{
	if (u->parent == this->nil)
	{
		r = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else if (u == u->parent->right)
	{
		u->parent->right = v;
	}
	else
	{
		u->parent->middle = v;
	}
	v->parent = u->parent;
}

Node* TST::remove_fixup(Node*& r, Node*& x)
{
	while (x != r && x->color == BLACK)
	{
		if (x == x->parent->left)
		{
			Node* w = x->parent->right;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				x->parent = left_rotate(r, x->parent)->left;
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					w = right_rotate(r, w)->right;
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				x->parent = left_rotate(r, x->parent)->left;
				x = r;
			}
		}
		else
		{
			Node* w = x->parent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				x->parent = right_rotate(r, x->parent)->right;
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					w = left_rotate(r, w)->left;
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				x->parent = right_rotate(r, x->parent)->right;
				x = r;
			}
		}
	}
	x->color = BLACK;
	return r;
}

std::vector<Node*> spellChecking(TST& dictionary, const std::string& text, int max_wrong_char)
{
	std::vector<Node*> result;

	// Start the DFS from the root node
	std::string currentWord;
	dfs(dictionary.root, currentWord, 0, 0, text, max_wrong_char, result);

	return result;
}

void dfs (Node* node, std::string& currentWord, int index, int modifications, const std::string& text, int max_wrong_char, std::vector<Node*>& result)
{
	if (!node || modifications > max_wrong_char) return;

	char currentChar = text[index];

	// Traverse the left child
	dfs(node->left, currentWord, index, modifications, text, max_wrong_char, result);

	// Check the middle child (current character)
	if (index < text.size()) {
		// If characters match
		if (node->character == currentChar) {
			currentWord.push_back(node->character);
			if (node->isEOS && index == text.size() - 1) {
				result.push_back(node);
			}
			dfs(node->middle, currentWord, index + 1, modifications, text, max_wrong_char, result);
			currentWord.pop_back();
		}
		else {
			// If characters do not match
			currentWord.push_back(node->character);
			dfs(node->middle, currentWord, index + 1, modifications + 1, text, max_wrong_char, result);  // Substitute
			currentWord.pop_back();

			// Insertion and Deletion
			dfs(node, currentWord, index + 1, modifications + 1, text, max_wrong_char, result);  // Deletion
			currentWord.push_back(currentChar);
			dfs(node->middle, currentWord, index, modifications + 1, text, max_wrong_char, result);  // Insertion
			currentWord.pop_back();
		}
	}

	// Traverse the right child
	dfs(node->right, currentWord, index, modifications, text, max_wrong_char, result);
}
