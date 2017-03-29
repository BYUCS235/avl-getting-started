TARGETS = lab7 Test_Binary_Search_Tree_Double 

CC = g++
CCFLAGS = -g -std=c++11

all:	$(TARGETS)

lab7:	main.cpp AVL.h AVL.cpp AVLInterface.h NodeInterface.h Node.h Node.cpp 
	$(CC) $(CCFLAGS)  -o lab7 main.cpp AVL.cpp Node.cpp

Test_Binary_Search_Tree_Double:	Test_Binary_Search_Tree_Double.cpp AVL_Tree.h \
BST_With_Rotate.h AVLNode.h
	$(CC) $(CCFLAGS)  -o Test_Binary_Search_Tree_Double \
Test_Binary_Search_Tree_Double.cpp


.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
