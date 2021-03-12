#pragma once
#include "NodeInterface.h"
#include "AVLNode.h"
#include <iostream>
using namespace std;

class Node : public NodeInterface, public AVLNode {

public:
	Node(const int& the_data, BTNode* left_val = NULL,
          BTNode* right_val = NULL) : 
    AVLNode(the_data, left_val, right_val) {}
	Node() {}
	virtual ~Node() {}

	int getData() const;

	NodeInterface * getLeftChild() const;

	NodeInterface * getRightChild() const;

	/*
	* Returns the height of this node. The height is the number of nodes
	* along the longest path from this node to a leaf.  While a conventional
	* interface only gives information on the functionality of a class and does
	* not comment on how a class should be implemented, this function has been
	* provided to point you in the right direction for your solution.  For an
	* example on height, see page 448 of the text book.
	*
	* @return the height of this tree with this node as the local root.
	*/
	int getHeight();
};
