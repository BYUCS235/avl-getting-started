#include "Node.h"

int Node::getData() const
{
    cout << "getData"<<endl;
    return(0);
}

NodeInterface * Node::getLeftChild() const
{
    cout << "getLeftChild"<<endl;
    return(NULL);
}

NodeInterface * Node::getRightChild() const
{
    cout << "getRightChild"<<endl;
    return(NULL);
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
    return(0);
}
