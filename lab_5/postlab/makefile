CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g

treeTest: BinarySearchTree.o AVLTree.o TreePathTest.o 
	$(CXX) $(DEBUG) BinarySearchTree.o AVLTree.o TreePathTest.o
	@echo "AVL vs BST"
	
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h 
	$(CXX) -c BinarySearchTree.cpp

AVLTree.o: AVLTree.cpp AVLTree.h
	$(CXX) -c AVLTree.cpp
	
TreePathTest.o: TreePathTest.cpp
	$(CXX) -c TreePathTest.cpp

	
	
clean:
	-rm *.o pizza
