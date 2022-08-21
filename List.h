#ifndef _LIST_H_
#define _LIST_H_

class List {
private:
	Node* head;
public:
	List();
	List(const List& list);
	List operator = (const List& list);
	~List();
	void deleteAll();
	void add(int na, int ne);
	void add(Node *node);
	void remove();
	Node* getHead();
	friend ostream& operator << (ostream& out, List& list) {
		Node *t = list.head;
		while (t) {
			out << "(" << t -> getA() << ", " << t -> getE() << ")" << endl;
			t = t -> getNext();
		}
		return out;
	}
};

#endif
