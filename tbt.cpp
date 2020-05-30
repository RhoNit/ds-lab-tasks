#include <iostream>
#include <string.h>
using namespace std;

class Node {
	char *data;
	int bitL, bitR;
	Node *left, *right;
public:
	Node() {
		data = new char[50];
		right = NULL;
		left = NULL;
		bitL = 0;
		bitR = 0;
	}

	void setData(char *d) { strcpy(data,d); }
	char *getData() { return data; }

	void setLeft(Node *l) { left = l; }
	Node *getLeft() { return left; }

	void setRight(Node *r) { right = r; }
	Node *getRight() { return right; }

	void setbitL(int l) { bitL = l; }
	int getbitL() { return bitL; }

	void setbitR(int r) { bitR = r; }
	int getbitR() { return bitR; } 
};


class TBT {
	Node *root, *head;
public:
	TBT() { head = root = NULL; }

	void setHead(Node *h) { head = h; }
	Node *getHead() { return head; }

	void create();
	void insert(char *);
	void display();
	Node *init();
};

void TBT :: create() {
	int total;
	char val[50];
	cout << "Enter total number of nodes to be inserted in tree:\n";
	cin >> total;
	for(int i = 0; i < total; i++) {
		cout << "Enter value:\n";
		cin >> val;
		insert(val);
	}
}

Node* TBT :: init() {
	head = new Node();
	head->setLeft(head);
	head->setRight(head);
	return head;
}

void TBT :: insert(char *val) {
	Node *curr, *temp;
	char option;
	int flag = 0;

	if(root == NULL) {
		head = init();
		root = new Node();
		root->setData(val);
		root->setRight(head);
		root->setLeft(head);
		head->setLeft(root);
		head->setbitL(1);
		cout << "Root of tree is-->" << root->getData() << endl;
		flag = 1;
	}
	else {
		Node *temp;
		temp = root;
		do {
			cout << "Where do you want to add new node(value) in l/r of "<<temp->getData()<<" : ";
			cin >> option;
			if(option == 'l' || option == 'L') {
				if(temp->getbitL() == 1) {
					temp = temp->getLeft();
				}
				else {
					curr = new Node();
					curr->setData(val);
					cout << "\"" << curr->getData() << "\" is inserted at the LEFT of " << temp->getData() << endl;
					curr->setLeft(temp->getLeft());
					curr->setRight(temp);
					temp->setLeft(curr);
					temp->setbitL(1);
					flag = 1;
				}
			}
			else if(option == 'r' || option =='R') {
				if(temp->getbitR() == 1) {
					temp = temp->getRight();
				}
				else {
					curr = new Node();
					curr->setData(val);
					cout << "\"" << curr->getData() << "\" inserted at the RIGHT of " << temp->getData() << endl;
					curr->setRight(temp->getRight());
					curr->setLeft(temp);
					temp->setRight(curr);
					temp->setbitR(1);
					flag = 1;
				}
			}
			else
				cout << "Invalid choice!!\n";
		}
		while(flag == 0);
	}
}

void TBT :: display() {
	Node *temp;
	temp = root;
	if(root == NULL) {
		cout << "Tree dose not exit!!\n\n";
	}
	else {
		while(temp != NULL) {
			while(temp->getbitL() == 1) {
				temp = temp->getLeft();
			}
			cout << temp->getData() << " ";
			while(temp->getbitR() == 0) {
				temp = temp->getRight();
				if(temp == head)
					return;
				cout << temp->getData() << " ";
			}
			temp = temp->getRight();
		}
		cout << "\n\n";
	}
}


int main() {
	TBT obj;
	int ch;
	do {
		cout << "\n1.Create Threaded Binary Tree\n2.Display Threaded Binary Tree\n3.Exit\n";
		cout << "\nEnter choice:\n";
		cin >> ch;
		switch(ch) {
			case 1:
				obj.create();
				break;
			case 2:
				cout << "\nThreaded Binary Tree \n";
				obj.display();
				break;
			case 3:
				cout << "\nSee you around...\n";
				break;
			default:
				cout << "Invalid choice!!\n";
				break;
		}
	}
 	while(ch != 3);
 	return 0;
 }