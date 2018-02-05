#ifndef DEQUE_H
#define DEQUE_H

#include <exception>
#include "Node.cpp"
#include <string>
#include <iostream>

using namespace std;

//Deque Exception for throwing Deque errors
class DequeException : public exception {
private:
	string errorMessage;
public:
	const int DEQUE_EMPTY = 1;
	DequeException(int code) {
		switch (code) {
		case 1:
			errorMessage = "Operation not allowed: Deque is empty";
			break;
		default:
			errorMessage = "Error using deque function\n";
		}
	}
	string getErrorMessage() { return errorMessage; }
	friend ostream &operator<<(ostream &o, DequeException &de) { 
		o << de.getErrorMessage() << endl;
		return o;
	}
};


template <class T>
class Deque {
private:
	Node<T> *head;
	Node<T> *tail;
	int sz;

public:
	//default constructor
	Deque() {
		head = NULL;
		tail = NULL;
		sz = 0;
   }

	~Deque() {
		head = NULL;
		tail = NULL;
   }

	bool isEmpty() { return sz == 0; }

	int size() { return sz; }

	//exception should be changed to DequeException but you told us not to change anything so it gives errors
	T first() throw(exception) {
		if (head == NULL) {
			DequeException de(1);
			throw de;
		}
		return head->getData();
   }

	//exception should be changed to DequeException but you told us not to change anything so it gives errors
	T last() throw(exception) {
		if (tail == NULL)
			throw DequeException(1);
		return tail->getData();
   }

	void insertFirst(T o) {
		Node<T> *newNode = new Node<T>();
		newNode->setData(o);
		if (head == NULL) { //if there is nothing in the deque
			head = newNode;
			tail = head;
		}
		else if (tail == head) { //if there is one thing in the deque
			newNode->setNextNode(head);
			newNode->setPrevNode(head);
			tail = head;
			head = newNode;
			tail->setPrevNode(head);
		}
		else {
			newNode->setPrevNode(tail);
			newNode->setNextNode(head);
			head->setPrevNode(newNode);
			tail->setNextNode(newNode);
			head = newNode;
		}
		sz++;
   }

	void insertLast(T o) {
		Node<T> *newNode = new Node<T>();
		newNode->setData(o);
		if (head == NULL) { //if there is nothing in the deque
			tail = newNode;
			head = tail;
		}
		else if (tail == head) { //if there is one thing in the deck
			newNode->setNextNode(head);
			newNode->setPrevNode(head);
			tail = newNode;
			head->setPrevNode(tail);
			head->setNextNode(tail);
		}
		else {
			newNode->setPrevNode(tail);
			newNode->setNextNode(head);
			head->setPrevNode(newNode);
			tail->setNextNode(newNode);
			tail = newNode;
		}
		sz++;
   }

	T removeFirst() throw(exception) {
		T tdat;
		if (head == NULL) //if the deque is empty
			throw DequeException(1);
		else if (head == tail) { //if there is one thing in the deque
			tdat = head->getData();
			head = NULL;
			tail = NULL;
		}
		else {
			Node<T> *temp = head;
			tail->setNextNode(head->getNext());
			tdat = head->getData();
			head = temp->getNext();
			delete temp;
		}
		sz--;
		return tdat;
	}

	//exception should be changed to DequeException but you told us not to change anything so it gives errors
	T removeLast() throw(exception) {
		if (tail == NULL)								//if the deque is empty
			throw DequeException(1);

		T tdat;
		if (head == tail) { //if there is one thing in the deque
			
			tdat = head->getData();
			head = NULL;
			tail = NULL;
		}
		else {
			Node<T> *temp = tail;
			head->setPrevNode(tail->getPrev());
			tdat = tail->getData();
			tail = temp->getPrev();
			tail->setNextNode(head);
			delete temp;
		}
		sz--;
		return tdat;
   }

	void print() {
		cout << "[ ";
		Node<T> *temp = head;
		for (int i = 0; i < sz; i++) {
			cout << temp->getData() << ", ";
			temp = temp->getNext();
		}
		cout << "]" << endl;
	}

	void print2() {
		Node<T> *temp = head;
		for (int i = 0; i < sz; i++) {
			cout << "node at address: " << temp << "\tdata member: " << temp->getData() << "\tprevious node address: " << temp->getPrev() << "\tnext node address: " << temp->getNext() << endl;
			temp = temp->getNext();
		}
		cout << endl;
	}
};

#endif