#ifndef BTNODE_H_
#define BTNODE_H_
#include <sstream>

/** A node for a Binary Tree. */
struct BTNode 
{
  // Data Fields
  int data;
  BTNode* left;
  BTNode* right;
  
  // Constructor
  BTNode(const int& the_data, 
         BTNode* left_val = NULL,
         BTNode* right_val = NULL) : 
    data(the_data), left(left_val),  right(right_val) {}
  BTNode() {}
  // Destructor (to avoid warning message)
  virtual ~BTNode() {}

  // to_string
  virtual std::string to_string() const {
    std::ostringstream os;
    os << data;
    return os.str();
  }
}; // End BTNode

// Overloading the ostream insertion operator
inline  std::ostream& operator<<(std::ostream& out, 
                           const BTNode& node) {
  return out << node.to_string();
}

#endif
