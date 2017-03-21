#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdexcept>
#include "BST_With_Rotate.h"
#include "RBNode.h"

/** Definition of the Red-Black Tree class 
 @param Item_Type the type of item to be stored in the tree
 Note: Item_Type must define the less than operator as a 
 total order.
*/
template <typename Item_Type>
class Red_Black_Tree : public BST_With_Rotate<Item_Type>
{
 public:
  // Constructor
  /** Construct an empty Red_Black_Tree */
  Red_Black_Tree() : BST_With_Rotate<Item_Type>() {}

  // Public Member Functions
  /** Insert an item into the tree 
      @param item The item to be inserted
      @return true if the item was not already
      in the tree, false otherwise.
      post: The item is in the tree.
  */
  virtual bool insert(const Item_Type& item);


private:

  // Private member functions

  /** Insert an item into a the tree 
      @param local_root A reference to the current root
      @param item The item to be inserted
      @return true if the item was not already in the
      tree, false otherwise
      post: The item is in the tree.
  */
  bool insert(BTNode<Item_Type>*& local_root, 
			  const Item_Type& item);
  
  /** Function to make the two children of the a sub-tree
      balck and the localRoot black.
      @param RB_local_root The root of the sub-tree
      cast to a RBNode<Item_Type>*
  */
  void move_black_down(BTNode<Item_Type>* RB_local_root);
/** Determine whether a node is red.
    @param node A pointer to a BTNode<Item_Type>
    @return true if node points to a RBNode<Item_Type> that is red
*/
static bool is_red(BTNode<Item_Type>* node) {
  RBNode<Item_Type>* RB_node = 
    dynamic_cast<RBNode<Item_Type>*>(node);
  if (RB_node != NULL) {
    return RB_node->is_red;
  } else {
    return false;
  }
}

/** Set the color of a node.
    @param node A pointer to a BTNode<Item_Type>
    @param red A bool value that is true if the
           node is to be set red, false if to be set black
*/
static void set_red(BTNode<Item_Type>* node, bool red) {
  RBNode<Item_Type>* RB_node =
    dynamic_cast<RBNode<Item_Type>*>(node);
  if (RB_node != NULL) {
    RB_node->is_red = red;
  }
}

 
  /** Function to find a replacement for a node that is being
      deleted from a Red-Black tree.  If the node has a NULL
      child, then the replacement is the other child.  If neither
      are NULL, then the replacement is the largest value less
      than the item being removed.
      @pre  node is not NULL
      @post a node replaced by its replacement 
      @param node The node to be deleted or replaced
  */
  void find_replacement(BTNode<Item_Type>*& node);
  
  /** Find the node such that parent->right->right == NULL
      @post The found node is removed from the tree and replaced
      by its left child (if any)
      @param parent - The possible parent
      @return the value of the found node
  */
  Item_Type find_largest_child(BTNode<Item_Type>* parent);

  /** Method to restore black balance to a subtree whose right black
      height is currently one less than the left black height.
      @param local_root - The root of the tree needing fixing
  */
  void fixup_right(BTNode<Item_Type>*& local_root);

  /** Method to restore black balance to a subtree whose left black
      height is currently one less than the right black height.
      @param local_root - The root of the tree needing fixing
  */
  void fixup_left(BTNode<Item_Type>*& local_root);


  // Data Fields
  /** A boolean variable to indicate that the black height
      was reduced by a call to the recursive erase function
      or one of its subfunctions. 
  */
  bool fixup_required;

}; // Red-Black tree

// Implementation of member functions
template<typename Item_Type>
  bool Red_Black_Tree<Item_Type>::insert(const Item_Type& item) {
  if (this->root == NULL) {
    RBNode<Item_Type>* new_root = new RBNode<Item_Type>(item);
    new_root->is_red = false;
    this->root = new_root;
    return true;
  }
  else {
    // Call the recursive insert function.
    bool return_value = insert(this->root, item);
    // Force the root to be black
    set_red(this->root, false);
    return return_value;
  }
}

template<typename Item_Type>
bool 
Red_Black_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root,
				      const Item_Type& item) {
if (item < local_root->data) {
  if (local_root->left == NULL) {
    local_root->left = new RBNode<Item_Type>(item);
    return true;
  }
else {
  // Check for two red children, swap colors if found
  move_black_down(local_root);
  // Recusively insert into the left subtree
  bool return_value = insert(local_root->left, item);
// See if the left-child is red
if (is_red(local_root->left)) {
	// Need to check grandchildren
	// Now check left grand child
if (is_red(local_root->left->left)) {
  // Child and left-left grandchild are both red
// Need to change colors and rotate
set_red(local_root->left, false);
set_red(local_root, true);
rotate_right(local_root);
return return_value;
	}
// Else check right grandchild
else if (is_red(local_root->left->right)) {
  // This will require a double rotation.
  set_red(local_root->left->right, false);
  set_red(local_root, true);
  rotate_left(local_root->left);
  rotate_right(local_root);
  return return_value;
}
	// else do nothing, the grandchildren are black
      } // else do nothing, the left child is black
      return return_value;
    }
  } 
  else if (local_root->data < item) {
  } 
  else {
    return false;
  }
}

template<typename Item_Type>
void Red_Black_Tree<Item_Type>::move_black_down(BTNode<Item_Type>* local_root) {
  // see if both children are red
  if (is_red(local_root->left) && is_red(local_root->right)) {
    //make them black and local root red
    set_red(local_root->left, false);
    set_red(local_root->right, false);
    set_red(local_root, true);
  }
}



#endif
