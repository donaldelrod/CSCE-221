template <class T>
class Node {
private:
	T data;
	Node<T> *parent, *left, *right;
public:
	Node() {
		data = nullptr;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Node(T d) {
		data = d;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	Node(T d, Node<T> p) {
		data = d;
		parent = p;
		left = nullptr;
		right = nullptr;
	}

	Node(T d, Node<T> l, Node<T> r) {
		data = d;
		parent = nullptr;
		left = l;
		right = r;
	}

	bool hasLeft() { return left == nullptr; }
	bool hasRight() { return right == nullptr; }
	bool hasParent() { return parent == nullptr; }
	bool hasData() { return data == nullptr; }
	bool isRoot() { return parent == nullptr; }
	bool isInternal() { return (left != nullptr || right != nullptr); }
	bool isLeaf() { return (left == nullptr && right == nullptr); }

	Node<T>* getLeft() {return left;}
	Node<T>* getRight() {return right;}
	Node<T>* getParent() { return parent; }

	T getData() { return data; }

	void setData(T d) { data = d; }
	void setLeftNode(Node<T>* ln) {left = ln;}
	void setRightNode(Node<T>* rn) {right = rn;}
	void setParentNode(Node<T>* pn) { parent = pn;}
};