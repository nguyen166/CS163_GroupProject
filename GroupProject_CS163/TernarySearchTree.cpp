#include"TernarySearchTree.h"


TSTNode* TST::_insert(TSTNode* node, const std::string& word, const std::string& meaning, int index) {
    char char_key = word[index];

    if (node == nullptr) {
        node = new TSTNode(char_key);
    }

    if (char_key < node->key) {
        node->left = _insert(node->left, word, meaning, index);
    }
    else if (char_key > node->key) {
        node->right = _insert(node->right, word, meaning, index);
    }
    else {
        if (index + 1 == word.size()) {
            node->is_end_of_string = true;
            node->meaning.push_back(meaning);
        }
        else {
            node->middle = _insert(node->middle, word, meaning, index + 1);
        }
    }

    node = _rebalance(node);
    return node;
}

// Helper function to rebalance the TST
TSTNode* TST::_rebalance(TSTNode* node) {
    if (node == nullptr) {
        return node;
    }

    if (node->left && node->left->priority < node->priority) {
        node = _right_rotate(node);
    }
    else if (node->right && node->right->priority < node->priority) {
        node = _left_rotate(node);
    }

    return node;
}

// Helper function to perform a right rotation
TSTNode* TST::_right_rotate(TSTNode* node) {
    TSTNode* left_child = node->left;
    node->left = left_child->right;
    left_child->right = node;
    return left_child;
}

// Helper function to perform a left rotation
TSTNode* TST::_left_rotate(TSTNode* node) {
    TSTNode* right_child = node->right;
    node->right = right_child->left;
    right_child->left = node;
    return right_child;
}

// Helper function to search for a word and return its meaning
std::vector<std::string> TST::_search(TSTNode* node, const std::string& word, int index) {
    if (node == nullptr) {
        return {};
    }
    char char_key = word[index];

    if (char_key < node->key) {
        return _search(node->left, word, index);
    }
    else if (char_key > node->key) {
        return _search(node->right, word, index);
    }
    else {
        if (index + 1 == word.size()) {
            if (node->is_end_of_string) {
                return node->meaning;
            }
        }
        return _search(node->middle, word, index + 1);
    }
}

TSTNode* TST::_remove(TSTNode* node, const std::string& word, int index) {
	if (node == nullptr) {
		return nullptr;
	}

	char char_key = word[index];

	if (char_key < node->key) {
		node->left = _remove(node->left, word, index);
	}
	else if (char_key > node->key) {
		node->right = _remove(node->right, word, index);
	}
	else {
		if (index + 1 == word.size()) {
			if (node->is_end_of_string) {
				node->is_end_of_string = false;
				node->meaning.clear();
			}
		}
		else {
			node->middle = _remove(node->middle, word, index + 1);
		}
	}
	if (node->left == nullptr && node->right == nullptr && node->middle == nullptr && node->is_end_of_string == false)
    {
		delete node;
		return nullptr;
	}
	node = _rebalance(node);
	return node;
}

void TST::insert(const std::string& word, const std::string& meaning) {
    root = _insert(root, word, meaning, 0);
}

// Search for a word and return its meaning if found
std::vector<std::string> TST::search(const std::string& word) {
    return _search(root, word, 0);
}

void TST::remove(const std::string& word) {
	root = _remove(root, word, 0);
}

void TST::loadCSV(const std::string& filename) {
    std::ifstream fin;
    fin.open(filename);
    if (!fin.is_open())
    {
        return;
    }
    std::string line;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        // Ignore characters at the beginning of the line that are not in the alphabet
        size_t j = 0;
        while (j < line.size() && !isalpha(line[j]))
        {
            j++;
        }
        line = line.substr(j);
        std::string key;
        std::string data;
        size_t i = 0;
        while (i < line.size() && line[i] != ' ')
        {
            if (i == 0)
            {
                key.push_back(tolower(line[i]));
            }
            else key.push_back(line[i]);
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

TSTNode* TST::_searchPrefix(TSTNode* node,std::string prefix, int index)
{
    if (node == nullptr) {
        return nullptr;
    }

    char char_key = prefix[index];

    if (char_key < node->key) {
        return _searchPrefix(node->left, prefix, index);
    }
    else if (char_key > node->key) {
        return _searchPrefix(node->right, prefix, index);
    }
    else {
        if (index + 1 == prefix.size()) {
            return node;
        }
        return _searchPrefix(node->middle, prefix, index + 1);
    }
   
}

void TST::_collect(TSTNode* node, std::string prefix, std::vector<std::string>& result)
{
	if (node == nullptr) {
		return;
	}
	_collect(node->left, prefix, result);
	prefix.push_back(node->key);
	if (node->is_end_of_string) {
		for (const auto& m : node->meaning)
		result.push_back(prefix+node->key+":"+m);
	}
	_collect(node->middle, prefix, result);
	prefix.pop_back();
	_collect(node->right, prefix, result);
}

std::vector<std::string> TST::searchPrefix(const std::string& prefix)
{
	std::vector<std::string> result;
	TSTNode* node = _searchPrefix(root, prefix, 0);
	if (node == nullptr) {
		return result;
	}
	std::string prefixx = prefix;
	_collect(node->middle, prefixx, result);
	return result;
}

std::vector<std::string> spellChecking(TST& dictionary, const std::string& text, int max_wrong_char)
{
    std::vector<std::string> result;

    // Start the DFS from the root node
    std::string currentWord;
    dfs(dictionary.getRoot(), currentWord, 0, 0, text, max_wrong_char, result);

    return result;
}

void dfs(TSTNode* node, std::string& currentWord, int index, int modifications, const std::string& text, int max_wrong_char, std::vector<std::string>& result)
{
    if (!node || modifications > max_wrong_char) return;

    char currentChar = text[index];

    // Traverse the left child
    dfs(node->left, currentWord, index, modifications, text, max_wrong_char, result);

    // Check the middle child (current character)
    if (index < text.size()) {
        // If characters match
        if (node->key == currentChar) {
            currentWord.push_back(node->key);
            if (node->is_end_of_string && index == text.size() - 1) {
				result.push_back(currentWord);
            }
            dfs(node->middle, currentWord, index + 1, modifications, text, max_wrong_char, result);
            currentWord.pop_back();
        }
        else {
            // If characters do not match
            currentWord.push_back(node->key);
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