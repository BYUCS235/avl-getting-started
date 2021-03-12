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
