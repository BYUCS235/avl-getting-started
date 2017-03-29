#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Binary_Tree.h"

/** Definition of the Binary Search Tree class. 
    @param int The type of item to be stored in the tree
    Note: int must define the less-than operator as a 
    total ordering.
*/

  class Binary_Search_Tree : public Binary_Tree
{
  public:
  // Constructor
  /** Construct an empty Binary_Search_Tree */
  Binary_Search_Tree() : Binary_Tree() {}

  // Public Member Functions
  /** Insert an item into the tree. 
      post: The item is in the tree.
      @param item The item to be inserted
      @return true if the item was not already
              in the tree, false otherwise
  */ 
  virtual bool insert(const int& item);

  /** Remove an item from the tree. 
      post: The item is no longer in the tree.
      @param item The item to be removed
      @return true if the item was in the tree,
              false otherwise
  */  
  virtual bool erase(const int& item);

  /** Determine whether an item is in the tree.
      @param item The item sought
      @return A const pointer to the item if in the
              tree, or NULL if not
  */
  const int* find(const int& target) const;

  private:

  // Private Member Functions
  /** Insert an item into the tree. 
      post: The item is in the tree.
      @param local_root A reference to the current root
      @param item The item to be inserted
      @return true if the item was not already in the
              tree, false otherwise
  */  
  virtual bool insert(BTNode*& local_root, 
		      const int& item);

  /** Remove an item from the tree. 
      post: The item is no longer in the tree.
      @param local_root A reference to the current root
      @param item The item to be removed
      @return true if the item was in the tree,
              false otherwise
  */  
  virtual bool erase(BTNode*& local_root, 
		     const int& item);

  /** Determine whether an item is in the tree.
      @param local_root A reference to the current root
      @param target The item sought
      @return A const pointer to the item in the tree
  */
  const int* find(BTNode* local_root, 
                        const int& target) const;
  
  /** Find a replacement for a node that is being deleted.
      This function finds the rightmost local root that 
      does not have a right child. The data in this local_root
      replaces the data in old_root. The pointer to local_root
      is then saved in old_root and local_root is replaced
      by its left child.
      @param old_root Reference to the pointer to old parent
      @param local_root Reference to the pointer to local root
  */
  virtual void replace_parent(BTNode*& old_root, 
                              BTNode*& local_root);

}; // End binary search tree

// Implementation of member functions
inline bool Binary_Search_Tree::insert(const int& item) {
  return insert(this->root, item);
}

inline bool Binary_Search_Tree::insert(BTNode*& local_root,const int& item) {
  if (local_root == NULL) {
    local_root = 
      new BTNode(item);
    return true;
  } else {
    if (item < local_root->data)
      return insert(local_root->left, item);
    else if (local_root->data < item)
      return insert(local_root->right, item);
    else {
      return false;
    }
  }
}


inline bool Binary_Search_Tree::erase(const int& item) {
  return erase(this->root, item);
}

inline bool Binary_Search_Tree::erase(BTNode*& local_root, const int& item) {
  if (local_root == NULL) {
    return false;
  } else {
    if (item < local_root->data)
      return erase(local_root->left, item);
    else if (local_root->data < item)
      return erase(local_root->right, item);
    else { // Found item
      BTNode* old_root = local_root;
      if (local_root->left == NULL) {
        local_root = local_root->right;
      } else if (local_root->right == NULL) {
        local_root = local_root->left;
      } else {
        replace_parent(old_root, old_root->left);
      }
      delete old_root;
      return true;
    }
  }
}


inline void Binary_Search_Tree::replace_parent(BTNode*& old_root,
					      BTNode*& local_root) {
  if (local_root->right != NULL) {
    replace_parent(old_root, local_root->right);
  } else {
    old_root->data = local_root->data;
    old_root = local_root;
    local_root = local_root->left;
  }
}

inline const int* Binary_Search_Tree::find(
    const int& target) const {
  return find(this->root, target);
}


inline const int* Binary_Search_Tree::find(
    BTNode* local_root, 
    const int& target) const {
  if (local_root == NULL)
    return NULL;
  if (target < local_root->data)
    return find(local_root->left, target);
  else if (local_root->data < target)
    return find(local_root->right, target);
  else
    return &(local_root->data);
}

#endif
