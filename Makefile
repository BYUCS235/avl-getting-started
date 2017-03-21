TARGETS = Test_Binary_Search_Tree_Double 

CC = g++
CCFLAGS = -g -std=c++11

all:	$(TARGETS)


Test_Binary_Search_Tree_Word:	Test_Binary_Search_Tree_Word.cpp AVL_Tree.h \
Red_Black_Tree.h BST_With_Rotate.h AVLNode.h RBNode.h
	$(CC) $(CCFLAGS)  -o Test_Binary_Search_Tree_Word \
Test_Binary_Search_Tree_Word.cpp

Test_Binary_Search_Tree_Double:	Test_Binary_Search_Tree_Double.cpp AVL_Tree.h \
Red_Black_Tree.h BST_With_Rotate.h AVLNode.h RBNode.h
	$(CC) $(CCFLAGS)  -o Test_Binary_Search_Tree_Double \
Test_Binary_Search_Tree_Double.cpp

Test_Two_Three_Tree_Word:	Test_Two_Three_Tree_Word.cpp Two_Three_Tree.h
	$(CC) $(CCFLAGS) -o Test_Two_Three_Tree_Word \
Test_Two_Three_Tree_Word.cpp 

Test_Two_Three_Tree_Double:	Test_Two_Three_Tree_Double.cpp Two_Three_Tree.h
	$(CC) $(CCFLAGS) -o Test_Two_Three_Tree_Double \
Test_Two_Three_Tree_Double.cpp 

Test_Two_Three_Four_Tree_Word:	Test_Two_Three_Four_Tree_Word.cpp \
Two_Three_Four_Tree.h
	$(CC) $(CCFLAGS) -o Test_Two_Three_Four_Tree_Word \
Test_Two_Three_Four_Tree_Word.cpp 

Test_Two_Three_Four_Tree_Double:	Test_Two_Three_Four_Tree_Double.cpp \
Two_Three_Four_Tree.h
	$(CC) $(CCFLAGS) -o Test_Two_Three_Four_Tree_Double \
Test_Two_Three_Four_Tree_Double.cpp 

Test_BTree3_Double:	Test_BTree_Double.cpp B_Tree.h
	$(CC) $(CCFLAGS) -DNN=3 -o $@ $<

Test_BTree4_Double:	Test_BTree_Double.cpp B_Tree.h
	$(CC) $(CCFLAGS) -DNN=4 -o $@ $<

Test_BTree5_Double:	Test_BTree_Double.cpp B_Tree.h
	$(CC) $(CCFLAGS) -DNN=5 -o $@ $<

Test_BTree6_Double:	Test_BTree_Double.cpp B_Tree.h
	$(CC) $(CCFLAGS) -DNN=6 -o $@ $<

Test_BTree7_Double:	Test_BTree_Double.cpp B_Tree.h
	$(CC) $(CCFLAGS) -DNN=7 -o $@ $<

.PHONY:	clean

clean:
	rm -f *.o
	rm -f $(TARGETS)
