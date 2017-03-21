#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BST_With_Rotate.h"
#include "AVLNode.h"
#include <iostream>
using namespace std;

/** Definition of the AVL Binary Search Tree class.
    @param Item_Type The type of item to be stored in the tree
    Note: Item_Type must define the less-than operator as a 
    total ordering.
*/
template<typename Item_Type>
class AVL_Tree : public BST_With_Rotate<Item_Type> {
  
 public:
  // Constructor
  /** Construct an empty AVL_Tree */
  AVL_Tree() : BST_With_Rotate<Item_Type>() {}
  
  // Public Member Functions
  /** Insert an item into the tree by calling overridden insert function. 
      post: The item is in the tree.
      @param item The item to be inserted
      @return true only if the item was not already in the tree
  */
  virtual bool insert(const Item_Type& item) {
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
  virtual bool insert(BTNode<Item_Type>*&, const Item_Type&);
  
  /** Correct a critical left balance condition
      pre:  local_root is the root of an AVL subtree that is
      critically heavy.
      post: balance is restored
      @param local_root is the root of the AVL subtree
      that needs rebalancing
  */
  void rebalance_left(BTNode<Item_Type>*& local_root);
  
  /** Correct a critical right balance condition
      pre:  local_root is the root of an AVL subtree that is
      critically heavy.
      post: balance is restored
      @param local_root is the root of the AVL subtree
      that needs rebalancing
  */
  void rebalance_right(BTNode<Item_Type>*& local_root);


  // Data Fields
  /** A flag to indicate that the height of the tree has increased */
  bool increase;

}; // End of AVL_Tree class definition

// Implementation of member functions
template<typename Item_Type>
bool 
AVL_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root,
			    const Item_Type& item) {
  if (local_root == NULL) {
    local_root = new AVLNode<Item_Type>(item);
    increase = true;
    return true;
  }
  else {
    if (item < local_root->data) {
      bool return_value = insert(local_root->left, item);
      if (increase) {
	// Height of the left subtree has increased
	AVLNode<Item_Type>* AVL_local_root =
	  dynamic_cast<AVLNode<Item_Type>*>(local_root);
	switch (AVL_local_root->balance) {
	case AVLNode<Item_Type>::BALANCED :
	  // local root is now left heavy
	  AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
	  break;
	case AVLNode<Item_Type>::RIGHT_HEAVY :
	  // local root is now right heavy
	  AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
	  // Overall height of local root remains the same
	  increase = false;
	  break;
	case AVLNode<Item_Type>::LEFT_HEAVY :
	  // local root is now critically unbalanced
	  this->rebalance_left(local_root);
	  increase = false;
	  break;
	} // End switch
      } // End if (increase)
      return return_value;
    }
    else if (local_root->data < item) {
    }
    else {
      increase = false;
      return false;
    }
  }
}

template<typename Item_Type>
  void AVL_Tree<Item_Type>::rebalance_left(BTNode<Item_Type>*& local_root) {

  // Cast local_root to an AVLNode pointer
  AVLNode<Item_Type>* AVL_local_root =
    dynamic_cast<AVLNode<Item_Type>*>(local_root);
  // Obtain reference to the left child
  AVLNode<Item_Type>* left_child = 
    dynamic_cast<AVLNode<Item_Type>*>(local_root->left);
  // See whether left-right-heavy
  if (left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
    // Obtain a reference to the left-right child
    AVLNode<Item_Type>* left_right_child = 
      dynamic_cast<AVLNode<Item_Type>*>(left_child->right);
    // Adjust the balances to be the new values after rotations are 
    // performed
    if (left_right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
      left_child->balance = AVLNode<Item_Type>::BALANCED;
      left_right_child->balance = AVLNode<Item_Type>::BALANCED;
      AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
    } else if (left_right_child->balance 
               == AVLNode<Item_Type>::BALANCED) {
      left_child->balance = AVLNode<Item_Type>::BALANCED;
      left_right_child->balance = AVLNode<Item_Type>::BALANCED;
      AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    } else {
      left_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
      left_right_child->balance = AVLNode<Item_Type>::BALANCED;
      AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    }
    // Perform left rotation
    this->rotate_left(local_root->left);
  } else { // Left-Left case
    /* In this case the left child (the new root) and the
       local root (new right child) will both be balanced
       after the rotation.
    */
    left_child->balance = AVLNode<Item_Type>::BALANCED;
    AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
  }
  // Finally rotate right
  this->rotate_right(local_root);
}

template<typename Item_Type>
void
AVL_Tree<Item_Type>::rebalance_right(BTNode<Item_Type>*& local_root) {
}


#endif
