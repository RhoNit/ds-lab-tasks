#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

struct Node {
	char label[50];
	int ch_count;
	struct Node *child[50];
} *root;

class BinTree {
public:
	BinTree() { root = NULL; }
	void create();
	void display(Node *r);
};

void BinTree :: create() {
	int tot_books, tot_chapters;
	root = new Node();
	cout << "Enter the name of BOOK:\n";
	cin >> root->label;

	cout << "Enter total number of CHAPTERS in the book:\n";
	cin >> tot_chapters;
	root->ch_count = tot_chapters;

	for(int i = 0; i < tot_chapters; i++) {
		root->child[i] = new Node();

		cout << "Enter the CHAPTER name:\n";
		cin >> root->child[i]->label;

		cout << "Enter the number of MODULES in chapter \"" << root->child[i]->label << "\":\n";
		cin >> root->child[i]->ch_count;

		for(int j = 0; j < root->child[i]->ch_count; j++) {
			root->child[i]->child[j] = new Node();

			cout << "Enter the name of MODULE " << j+1 << " :\n";
			cin >> root->child[i]->child[j]->label;

			//cout << "Enter no. of subsecons in " << r1->child[i]->child[j]->label;
			//cin>>r1->child[i]->ch_count;
		}
	}
}

void BinTree :: display(Node *r) {
	int k, tot_chapters;
	if(r != NULL) {
		cout << "\n-----Book Hierarchy-----\n";
		cout << "Book title--> " << r->label;

		tot_chapters = r->ch_count;
		
		for(int i = 0; i < tot_chapters; i++) {
			cout << "\nChapter " << i+1 << "--> " << r->child[i]->label;
			
			cout << "\n Module";
			for(int j = 0; j < r->child[i]->ch_count; j++) {
				//cin>>r1->child[i]->child[j]->label;
				cout << "\n " << r->child[i]->child[j]->label;
			}
		}
	}
}


int main() {
	BinTree obj;
	int ch;
	while(1) {
		cout << "-----------------" << endl;
		cout << "Book Tree Creation" << endl;
		cout << "-----------------" << endl;
		cout << "1.Create" << endl;
		cout << "2.Display" << endl;
		cout << "3.Quit" << endl;

		cout << "Enter your choice : ";
		cin >> ch;

		switch(ch) {
			case 1:
				obj.create();
				break;
			case 2:
				obj.display(root);
				break;
			case 3:
				exit(1);
			default:
				cout << "Wrong choice" << endl;
		}
	}
}