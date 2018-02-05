#pragma once
#include "Node.cpp"
#include <exception>
#include <string>

using namespace std;

class BinaryTreeException : exception {
private:
	string errorMessage;
	int errorCode;
public:
	const int TREE_EMPTY = 1;
	const int HAS_LEFT = 2;
	const int HAS_RIGHT = 3;
	const int HAS_BOTH = 4;
	BinaryTreeException(int code) {
		errorCode = code;
		switch (code) {
		case 1:
			errorMessage = "Operation not allowed: Tree is empty";
			break;
		case 2:
			errorMessage = "Node has a left child already";
			break;
		case 3:
			errorMessage = "Node has a right child already";
			break;
		default:
			errorMessage = "Error using deque function\n";
		}
	}
	string getErrorMessage() { return errorMessage; }
	friend ostream &operator<<(ostream &o, BinaryTreeException &bte) {
		o << bte.getErrorMessage() << endl;
		return o;
	}
};


template <class T>
class BinaryTree {
private:
	Node<T>* root;


public:

	/** 
		Checks if the Binary Tree is empty

		@return returns true if empty (no root), false otherwise
	*/
	bool isEmpty() { retrun root == nullptr; }

	/**
		Adds a left child to the parent defined at p* with the data d

		@param Node<T>* p - pointer to the parent the data should be a child of
		@param T d - generic data type that the node will store
		@return throws a BinaryTreeException if the left node is already populated
	*/
	void addLeft(Node<T>* p, T d) throw(BinaryTreeException) {
		if (p->hasLeft())
			throw BinaryTreeException(BinaryTreeException.HAS_LEFT);
		Node<T>* newLeft = new Node<T>(d, p);
		p->setLeftNode(new Node<T>(d));
	}

	/**
		Adds lc* as the left child to the parent defined at p*

		@param Node<T>* p - pointer to the parent the node should be a child of
		@param Node<T>* lc - pointer to the new left child of *p
		@return throws a BinaryTreeException if the left node is already populated
	*/
	void addLeft(Node<T>* p, Node<T>* lc) throw(BinaryTreeException) {
		if (p->hasLeft()
			throw BinaryTreeException(BinaryTreeException.HAS_LEFT);
		p->setLeftNode(lc);
		lc->setParentNode(p);
	}

	/**
		Adds a right child to the parent defined at p* with the data d

		@param Node<T>* p - pointer to the parent the data should be a child of
		@param T d - generic data type that the node will store
		@return throws a BinaryTreeException if the right node is already populated
	*/
	void addRight(Node<T>* p, T d) throw(BinaryTreeException) {
		if (p->hasRight())
			throw BinaryTreeException(BinaryTreeException.HAS_RIGHT);
		Node<T>* newRight = new Node<T>(d, p);
		p->setLeftNode(newRight);
	}

	/**
		Adds rc* as the right child to the parent defined at p*

		@param Node<T>* p - pointer to the parent the node should be a child of
		@param Node<T>* rc - pointer to the new right child of *p
		@return throws a BinaryTreeException if the right node is already populated
	*/
	void addRight(Node<T>* p, Node<T>* nr) throw(BinaryTreeException) {
		if (p->hasRight())
			throw BinaryTreeException(BinaryTreeException.HAS_RIGHT);
		p->setLeftNode(nr);
		nr->setParentNode(p);
	}

	/** 
		
	*/
	void addChild(Node<T>* p, Node<T>* c) throw(BinaryTreeException) {
		if (!p->hasLeft())
			addLeft(p, c);
		else if (!p->hasRight()) 
			addRight(p, c);
		else
			throw BinaryTreeException(BinaryTreeException.HAS_BOTH);

		c->setParentNode(p);


	}

};

/*template <class T>
void BinaryTree::addNode(Node<T>* nn) {
	if (root == nullptr)
		root = nn;
	else {

	}
}

template <class T>
void BinaryTree::addLeft(Node<T>* p, T d) throw(BinaryTreeException) {
	if (p->hasLeft())
		throw BinaryTreeException(2);
	p->setLeftNode(new Node<T>(d));
	return true;
}

template <class T>
void BinaryTree::addChild(Node<T>* p, Node<T>* c) {

}*/