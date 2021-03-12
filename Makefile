TARGETS = AVLlab Test_Binary_Search_Tree_Int 

CC = g++
CCFLAGS = -g -std=c++11

all:	$(TARGETS)

AVLlab:	main.cpp AVL.h AVL.cpp AVLInterface.h NodeInterface.h Node.h Node.cpp 
	$(CC) $(CCFLAGS)  -o AVLlab main.cpp AVL.cpp Node.cpp

Test_Binary_Search_Tree_Int:	Test_Binary_Search_Tree_Int.cpp AVL_Tree.h \
BST_With_Rotate.h AVLNode.h
	$(CC) $(CCFLAGS)  -o Test_Binary_Search_Tree_Int \
Test_Binary_Search_Tree_Int.cpp


.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
