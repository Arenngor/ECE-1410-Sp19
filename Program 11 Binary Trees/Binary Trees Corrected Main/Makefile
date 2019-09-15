BTree.exe	:	main.o Node.o BTree.o
		g++ main.o Node.o BTree.o -oBTree.exe
			
Node.o	:	Node.cpp Node.h
		g++ -c Node.cpp
		
BinaryTree.o	:	BTree.cpp BTree.h
		g++ -c BTree.cpp
		
main.o	:	main.cpp BTree.h Node.h
		g++ -c main.cpp