# avllab
Here is working code from Chapter 11 of the text.  You will need to modify it to match the specifications in the AVL Lab, but this should give you an idea of what you need to do. 

From Koffman, Elliot B. (2011-12-01). Objects, Abstraction, Data Structures and Design: Using C++. Wiley Higher Ed. Kindle Edition.

I have removed the template nature of the code so it only works for integers.  You can go back to the original code if you want to generalize your implementation to other data types.  I have also modified the book code so that you can include it directly into your lab implementation.  I hope this will save you time in debugging, but you may wish to ignore this code altogether and start from scratch with your own BST implementation.

First lets talk about the overall UML for the lab.  Look at the UML for the AVL Tree in the book and think of how you would change it to interface with the Lab 7 test harness.

![alt text](https://mjcleme.github.io/avluml.png)

Then you will want to inherit from the interface files that are provided for you.  Given the NodeInterface.h file, you should create a Node.h file.  If you want to interface with the book code, you will want to inherit from both NodeInterface and AVLNode.
```c++
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
```
Put stubs in Node.cpp for the functions you will implement in the lab
```c++
#include "Node.h"

int Node::getData() const
{
    cout << "getData"<<endl;
}

NodeInterface * Node::getLeftChild() const
{
    cout << "getLeftChild"<<endl;
}

NodeInterface * Node::getRightChild() const
{
    cout << "getRightChild"<<endl;
}

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
int Node::getHeight()
{
    cout << "getHeight"<<endl;
}
```
You will also need to inherit from AVLInterface.h to create AVL.h.  Notice that I have included the AVL_Tree code from the book and included a data member "booktree" in case you want to use the book code in your implementation.
```c++
#pragma once

#include "NodeInterface.h"
#include "AVLInterface.h"
#include "AVL_Tree.h"
#include <iostream>

using namespace std;

class AVL : public AVLInterface {
public:
	AVL() {}
	virtual ~AVL() {}

	NodeInterface * getRootNode() const;

	bool add(int data);

	bool remove(int data);

	void clear();
private:
    AVL_Tree booktree;
};
```
Now start filling in the functions for the interface.  Several functions have not been completed in the book code, so you will have to complete them if you choose to use the book code.  If you use your BST lab code, you will need to implement the rotate code along with rebalancing code.
