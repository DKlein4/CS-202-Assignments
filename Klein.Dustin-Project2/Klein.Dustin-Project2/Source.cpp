/* 
* Morse code encoder and decoder using a binary tree
* Dustin Klein
*/

#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>

#include "Binary_Tree.h"
#include "BTNode.h"

using namespace std;

// Creates a binary tree given the map of <value, path>
Binary_Tree<string> create_morse_tree(map<string, string> codes) {
	// Make the root a dummy node
	Binary_Tree<string> new_tree;
	new_tree.setRoot(new BTNode<string>("root", NULL, NULL));

	// Iterate through every item in the given map
	std::map<string, string>::iterator it;
	for (it = codes.begin(); it != codes.end(); it++) {
		string val = it->first;
		string path = it->second;

		try {
			// Take the path and move a pointer to the correct place in the tree
			BTNode<string>* location = new_tree.getRoot();
			for (size_t i = 0; i < path.length(); i++) {
				char c = path[i];
				if (c == '.') {
					// if no left child, create temperary node
					if (location->left == NULL) {
						location->left = new BTNode<string>("tempL", NULL, NULL);
					}
					location = location->left;
				}
				else if (c == '_') {
					// if no right child, create temperary node
					if (location->right == NULL) {
						location->right = new BTNode<string>("tempR", NULL, NULL);
					}
					location = location->right;
				}
				else {
					throw invalid_argument("Invalid character: Cannot decode " + c);
				}
			}
			// store the value in the node at the correct location
			location->data = val;
		}
		catch (const invalid_argument e) {
			cout << e.what() << endl;
		}
	}

	return new_tree;
}

// take a string of morse code and return a string of letters
string decode(Binary_Tree<string> morse_tree, string code) {
	string result = "";

	istringstream ss(code);
	string token;

	try {
		// break the string into smaller strings with the delimeter space
		while (getline(ss, token, ' ')) {
			// ignores extra spaces between the inputs
			if (token == "")
				continue;

			// move through the tree to the location
			BTNode<string>* location = morse_tree.getRoot();
			for (size_t i = 0; i < token.length(); i++) {

				if (location == NULL)
					throw invalid_argument("Invalid Path: Null node found on path to destination");

				char c = token[i];
				if (c == '.')
					location = location->left;
				else if (c == '_')
					location = location->right;
				else
					throw invalid_argument("Invalid character: Cannot decode " + c);
			}

			result += location->data;
		}
	}
	catch (const invalid_argument e) {
		cout << e.what() << endl;
	}

	return result;
}

// Pass in a string of letters and return a string of morse code
string encode(map<string, string> codes, string code) {
	string result = "";

	// remove spaces since our tree does not contain spaces
	code.erase(std::remove_if(code.begin(), code.end(), ::isspace), code.end()); 

	try {
		// loop through every character in the string and add its morse code to the result
		for (int i = 0; i < code.length(); i++) {
			string s = code.substr(i, 1);

			if (!isalpha(s[0])) {
				throw invalid_argument("Invalid Character: Cannot encode " + s);
			}

			result += codes[s] + " ";
		}
	}
	catch (const invalid_argument e) {
		cout << e.what() << endl;
		return "";
	}

	return result;
}

void main() {

	// read in the file
	ifstream codes_file("morse.txt");

	// store the data from the file into a map
	std::map<string, string> codes;
	string line;
	while (getline(codes_file, line)) {
		codes[line.substr(0, 1)] = line.substr(1);
	}

	// close the file
	codes_file.close();

	// create the tree
	Binary_Tree<string> morse_tree;
	morse_tree = create_morse_tree(codes);


	cout << decode(morse_tree, "_... ._. . _ _") << endl;
	cout << encode(codes, " bre   tt") << endl;

	system("pause");
}