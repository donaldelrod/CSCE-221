template <class T>
class Stack2
{
private:
	T *data;


public:
	int csize, maxsize;
	Stack2() {
		data = new T[25];
		csize = 0;
		maxsize = 25;
	}

	~Stack2() {
		//cout << "destroyed" << endl;
	}

	bool isEmpty() {
		return (csize == 0);
	}

	int size() {
		return csize;
	}

	T top() {
		if (csize == 0)
			throw new exception;
		return data[csize - 1];
	}

	T pop() {
		if (csize == 0)
			throw new exception;
		csize -= 1;
		T ret = data[csize];
		data[csize] = NULL;

		return ret;
	}

	void push(T e) {
		if (csize == maxsize) {

			T *newdata = new T[maxsize*2];
			for (int i = 0; i < maxsize; i++) {
				newdata[i] = data[i];
			}

			data = newdata;
			maxsize *= 2;

		}
		csize++;
		data[csize - 1] = e;
	}

	void print() {
		cout << "[ ";
		for (int i = csize - 1; i >= 0; i--) {
			cout << data[i] << ", ";
		}
		cout << " ]" << endl;
	}

	void print2() {
		cout << "[ ";
		for (int i = 0; i < maxsize; i++) {
			cout << data[i] << ", ";
		}
		cout << " ]" << endl;
	}

};