#include <bits/stdc++.h>
using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];

	// isWordEnd is true if the node represents
	// end of a word
	bool isWordEnd;
};

// Returns new trie node (initialized to NULLs)
TrieNode* getNode()
{
	TrieNode* pNode = new TrieNode;
	pNode->isWordEnd = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void insert(TrieNode* root, const string key)
{
	TrieNode* p = root;

	for (int level = 0; level < key.length(); level++) {
		int index = CHAR_TO_INDEX(key[level]);
		if (!p->children[index])
			p->children[index] = getNode();

		p = p->children[index];
	}

	// mark last node as leaf
	p->isWordEnd = true;
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool isLastNode(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}

// Recursive function to print auto-suggestions for given
// node.
void suggestionsRec(TrieNode* root, string currPrefix) {
	// found a string in Trie with the given prefix
	if (root->isWordEnd)
		cout << currPrefix << endl;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i]) {
			// child node character value
			char child = 'a' + i;
			suggestionsRec(root->children[i],
			               currPrefix + child);
		}
}

// print suggestions for given query prefix.
int printAutoSuggestions(TrieNode* root, const string query)
{
	TrieNode* p = root;
	for (char c : query) {
		int ind = CHAR_TO_INDEX(c);

		// no string in the Trie has this prefix
		if (!p->children[ind])
			return 0;

		p = p->children[ind];
	}
	// If prefix is present as a word, but
	// there is no subtree below the last
	// matching node.
	if (isLastNode(p)) {
		cout << query << endl;
		return -1;
	}
	suggestionsRec(p, query);
	return 1;
}

int main()
{


	TrieNode* root = getNode();

	int n;
	cout << "Enter the No of String to insert" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(root, s);
	}

	int m;
	cin >> m;
	cout << "Enter the no of string to get AutoSuggestions" << endl;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		printAutoSuggestions(root, s);
		cout << "----------------------" << endl;
	}



}
