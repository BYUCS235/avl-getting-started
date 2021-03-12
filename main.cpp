#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "AVL.h"
using namespace std;

// This is just a small set of the tests you should perform
//  to make sure your code is working.  Download the git repository
//  for the lab when you have your own tests working.
string BSTtoString(AVL* bst);
int main() {

	AVL* avlptr = NULL;//the AVL
	avlptr = new AVL();


	if (avlptr->add(5)) {
		cout << "Add Worked" << endl;
	}
	else {
		cout << "Add Failed" << endl;
	}
	if (avlptr->remove(5)) {
		cout << "Remove Worked" << endl;
	}
	else {
		cout << "Remove Failed" << endl;
	}
	avlptr->clear();
	avlptr->add(5);
	avlptr->add(13);
	avlptr->add(15);
	avlptr->add(17);

	cout << BSTtoString(avlptr) << endl;
}


//a function that takes a BST and returns a level-order string representation of the BST
//returns a string representation of the nodes in level order
string BSTtoString(AVL* bst) {
	queue<NodeInterface*> readQ; // used to read in the levels of the tree, contains Node*
	stringstream nodeReader_ss; // used to store the values of the nodes and the level-order sequence
	int depth = 0; // the depth of a node on the tree

	if (bst->getRootNode() == NULL) {
		return "BST is empty\n";
	}

	readQ.push(bst->getRootNode()); // push the root node of the tree into the queue

	while (!readQ.empty()) { // as long as the queue has a remaining node:
		int i = readQ.size(); // store the number of nodes on this level of the tree
		nodeReader_ss << depth << ":  ";
		for (; i > 0; i--) { // for each node on this level,
			NodeInterface* nextNode = readQ.front(); // store the next node in the queue
			nodeReader_ss << nextNode->getData() << " "; // store the data from the node into the ss
			if (nextNode->getLeftChild() != NULL) { // if there is a left child, push the left child into the queue
				readQ.push(nextNode->getLeftChild());
			}
			if (nextNode->getRightChild() != NULL) { // if there is a right child, push the left child into the queue
				readQ.push(nextNode->getRightChild());
			}
			readQ.pop(); // pop the node off of the queue, leaving its children in the queue
		}
		nodeReader_ss << "\n"; // push an endl into the ss to distinguish levels
		depth++;
	}

	return nodeReader_ss.str();
}





// Version of getline which does not preserve end of line characters
namespace ta {
	std::istream& getline(std::istream& in, std::string& line) {
		line.clear();

		std::istream::sentry guard(in, true); // Use a sentry to maintain the state of the stream
		std::streambuf *buffer = in.rdbuf();  // Use the stream's internal buffer directly to read characters
		int c = 0;

		while (true) { // Continue to loop until a line break if found (or end of file)
			c = buffer->sbumpc(); // Read one character
			switch (c) {
			case '\n': // Unix style, return stream for further parsing
				return in;
			case '\r': // Dos style, check for the following '\n' and advance buffer if needed
				if (buffer->sgetc() == '\n') { buffer->sbumpc(); }
				return in;
			case EOF:  // End of File, make sure that the stream gets flagged as empty
				in.setstate(std::ios::eofbit);
				return in;
			default:   // Non-linebreak character, go ahead and append the character to the line
				line.append(1, (char)c);
			}
		}
	}
}
