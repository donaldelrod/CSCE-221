#include "Node.cpp"

template <class T>
class Stack3 {
private:
	Node<T> *head;
	Node<T> *tail;
	int size;

public:

	Stack3() {
		head = NULL;
		tail = NULL;
	}

	Stack3(T d) {
		head(d);
		tail = head;
	}

	T top() {return head.getData();}

	void push(T e) {
		if (head == NULL) {
			head = new Node<T>(e);
			size = 1;
		}
		else {
			Node<T>* t = head;
			Node<T>* nh = new Node<T>(e);
			nh->setNextNode(t);
			t->setPrevNode(nh);
			head = nh;
			size++;
		}
	}

	T pop() {
		if (&head == &tail || &head == NULL)
			throw new exception;
		Node<T> *newhead = (head->getNext());
		T tempdata = head->getData();
		head = newhead;
		size--;
		return tempdata;
	}

	int size() { return size; }

	void print() {
		Node<T> *n = head;
		cout << "[ ";
		while ((n->getNext()) != NULL) {
			cout << n->getData() << ", ";
			n = n->getNext();
		}
		cout << " ]" << endl;
	}

};