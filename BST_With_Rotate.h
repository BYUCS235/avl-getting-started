#ifndef BST_WITH_ROTATE_H_
#define BST_WITH_ROTATE_H_
#include "Binary_Search_Tree.h"
#include <iostream>
using namespace std;

/** This class extends the Binary_Search_Tree by adding the rotate
    operations. Rotate will change the balance of a search
    tree while preserving the search tree property.
    Used as a common base class for self-adjusting trees.
*/

  class BST_With_Rotate : public Binary_Search_Tree {

  protected:
  
  /** rotate_right
      pre:  local_root is the root of a binary search tree
      post: local_root->left is the root of a binary search tree
            local_root->left->left is raised one level
            local_root->left->right does not change levels
            local_root->right is lowered one level
            local_root is set to the new root
     @param local_root The root of the binary tree to be rotated
  */
  void rotate_right(BTNode*& local_root) {
    BTNode* temp = local_root->left;
    local_root->left = temp->right;
    temp->right = local_root;
    local_root = temp;
  }

  // Insert rotate_left here
  void rotate_left(BTNode*&) { 
    cout << "rotate_left not implemented"<<endl;
  }
};

#endif
