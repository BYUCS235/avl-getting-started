#ifndef AVLNODE_H_
#define AVLNODE_H_
#include <sstream>
#include "BTNode.h"

/** A node for an AVL Tree. */
  struct AVLNode : public BTNode {

  enum  balance_type {LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = +1};
  // Additional data field
  balance_type balance;

  // Constructor
  AVLNode(const int& the_data, BTNode* left_val = NULL,
          BTNode* right_val = NULL) : 
    BTNode(the_data, left_val, right_val), balance(BALANCED) {}
    
  AVLNode() {}
  // Destructor (to avoid warning message)
  virtual ~AVLNode() {}

  // to_string
  virtual std::string to_string() const {
    std::ostringstream os;
    os << balance << ": " << this->data;
    return os.str();
  }
}; // End AVLNode

#endif
