#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BST_With_Rotate.h"
#include "AVLNode.h"
#include <iostream>
using namespace std;

/** Definition of the AVL Binary Search Tree class.
    @param int The type of item to be stored in the tree
    Note: int must define the less-than operator as a 
    total ordering.
*/

class AVL_Tree : public BST_With_Rotate {
  
 public:
  // Constructor
  /** Construct an empty AVL_Tree */
  AVL_Tree() : BST_With_Rotate() {}
  
  // Public Member Functions
  /** Insert an item into the tree by calling overridden insert function. 
      post: The item is in the tree.
      @param item The item to be inserted
      @return true only if the item was not already in the tree
  */
  virtual bool insert(const int& item) {
    cout << "AVL Insert "<<item<<endl;
    return insert(this->root, item); }
  
  
 private:
  
  // Private member functions declarations
  /** Insert an item into the tree. Called by starter function (see
      listing 11.2) with this->root as first argument.
      post: The item is in the tree.
      @param local_root A reference to the current root
      @param item The item to be inserted
      @return true only if the item was not already in the
  */
  virtual bool insert(BTNode*&, const int&);
  
  /** Correct a critical left balance condition
      pre:  local_root is the root of an AVL subtree that is
      critically heavy.
      post: balance is restored
      @param local_root is the root of the AVL subtree
      that needs rebalancing
  */
  void rebalance_left(BTNode*& local_root);
  
  /** Correct a critical right balance condition
      pre:  local_root is the root of an AVL subtree that is
      critically heavy.
      post: balance is restored
      @param local_root is the root of the AVL subtree
      that needs rebalancing
  */
  void rebalance_right(BTNode*& local_root);


  // Data Fields
  /** A flag to indicate that the height of the tree has increased */
  bool increase;

}; // End of AVL_Tree class definition

// Implementation of member functions
inline bool AVL_Tree::insert(BTNode*& local_root,
			    const int& item) {
	cout << "Insert "<<item<<endl;
  if (local_root == NULL) {
    local_root = new AVLNode(item);
    increase = true;
    return true;
  }
  else {
    if (item < local_root->data) {
      bool return_value = insert(local_root->left, item);
      if (increase) {
      	// Height of the left subtree has increased
      	AVLNode* AVL_local_root =
      	  dynamic_cast<AVLNode*>(local_root);
      	switch (AVL_local_root->balance) {
      	case AVLNode::BALANCED :
      	  // local root is now left heavy
      	  AVL_local_root->balance = AVLNode::LEFT_HEAVY;
      	  break;
      	case AVLNode::RIGHT_HEAVY :
      	  // local root is now right heavy
      	  AVL_local_root->balance = AVLNode::BALANCED;
      	  // Overall height of local root remains the same
      	  increase = false;
      	  break;
      	case AVLNode::LEFT_HEAVY :
      	  // local root is now critically unbalanced
      	  this->rebalance_left(local_root);
      	  increase = false;
      	  break;
      	} // End switch
      } // End if (increase)
      return return_value;
    }
    else if (local_root->data < item) {
      cout << "Insert on right not implemented"<<endl;
      return false;
    }
    else {
      increase = false;
      return false;
    }
  }
}

inline  void AVL_Tree::rebalance_left(BTNode*& local_root) {

  // Cast local_root to an AVLNode pointer
  AVLNode* AVL_local_root =
    dynamic_cast<AVLNode*>(local_root);
  // Obtain reference to the left child
  AVLNode* left_child = 
    dynamic_cast<AVLNode*>(local_root->left);
  // See whether left-right-heavy
  if (left_child->balance == AVLNode::RIGHT_HEAVY) {
    // Obtain a reference to the left-right child
    AVLNode* left_right_child = 
      dynamic_cast<AVLNode*>(left_child->right);
    // Adjust the balances to be the new values after rotations are 
    // performed
    if (left_right_child->balance == AVLNode::LEFT_HEAVY) {
      left_child->balance = AVLNode::BALANCED;
      left_right_child->balance = AVLNode::BALANCED;
      AVL_local_root->balance = AVLNode::RIGHT_HEAVY;
    } else if (left_right_child->balance 
               == AVLNode::BALANCED) {
      left_child->balance = AVLNode::BALANCED;
      left_right_child->balance = AVLNode::BALANCED;
      AVL_local_root->balance = AVLNode::BALANCED;
    } else {
      left_child->balance = AVLNode::LEFT_HEAVY;
      left_right_child->balance = AVLNode::BALANCED;
      AVL_local_root->balance = AVLNode::BALANCED;
    }
    // Perform left rotation
    this->rotate_left(local_root->left);
  } else { // Left-Left case
    /* In this case the left child (the new root) and the
       local root (new right child) will both be balanced
       after the rotation.
    */
    left_child->balance = AVLNode::BALANCED;
    AVL_local_root->balance = AVLNode::BALANCED;
  }
  // Finally rotate right
  this->rotate_right(local_root);
}

inline void AVL_Tree::rebalance_right(BTNode*& local_root) {
  cout <<"rebalance_right not implemented"<<endl;
}


#endif
