#ifndef PRE_ORDER_TRAVERSAL_H
#define PRE_ORDER_TRAVERSAL_H

#include "Binary_Tree.h"
#include <ostream>


void pre_order_traversal(const Binary_Tree& the_tree, 
			 std::ostream& out, int level)
{
  if (the_tree.is_null()) { 
    for (int i = 0; i < level; i++)
      out << "  ";
    out << "null\n";
  }
  else {
    for (int i = 0; i < level; i++)
      out << "  ";
    out << the_tree.get_data() << std::endl;
    pre_order_traversal(the_tree.get_left_subtree(), out, level + 1);
    pre_order_traversal(the_tree.get_right_subtree(), out, level + 1);
  }
}

#endif
