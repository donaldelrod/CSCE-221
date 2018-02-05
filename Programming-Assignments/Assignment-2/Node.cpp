template <class T>
class Node {
private:
	T data;
	Node<T> *prev, *next;
public:
	Node() {
		data = NULL;
		prev = NULL;
		next = NULL;
	}
	Node(T d) {
		data = d;
		prev = NULL;
		next = NULL;
	}
	Node(T d, Node<T> p, Node<T> n) {
		data = d;
		prev = p;
		next = n;
	}
	Node<T>* getNext() {return next;}
	Node<T>* getPrev() {return prev;}
	T getData() { return data; }
	void setData(T d) { data = d; }
	void setNextNode(Node<T>* nn) {next = nn;}
	void setPrevNode(Node<T>* pn) {prev = pn;}
};