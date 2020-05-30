#include <iostream>
#include <string.h>
using namespace std;

class Node {
    int data;
    Node *right, *left;
public:
    Node() {
        data = 0;
        right = NULL;
        left = NULL;
    }

    void setData(int d) { data = d; }
    int getData() { return data; }

    void setLeft(Node *l) { left = l; }
    Node *getLeft() { return left; }

    void setRight(Node *r) { right = r; }
    Node *getRight() { return right; }
};

class BST {
    Node *root;
 public:
    BST() { root = NULL; }
    void create();
    void insert(int );
    void display();
    int search(int target);
    void smallest();
    void preorder(Node *temp);
    void postorder(Node *temp);
    void inorder(Node *temp);
    void mirror(Node *);
    void mirr();
    int longestpath(Node *);
    void longpath();
};

void BST :: create() {
    int total;
    int val;
    cout << "Enter total number of nodes to be inserted in tree : ";
    cin >> total;
    for(int i = 0;i < total; i++) {
        cout << "Enter the value: ";
        cin >> val;
        insert(val);
    }
}

void BST :: insert(int val) {
    Node *nn;
    int nfull = 0;
    if(root == NULL) {
        nn = new Node();
        nn->setData(val);
        root = nn;
        cout << "Root of tree is--> " << root->getData() << endl;
        nfull = 1;
    }
    else {
        Node *temp;
        temp = root;
        do {
            if(temp->getData() > val) {
                if(temp->getLeft() == NULL) {
                    nn = new Node();
                    nn->setData(val);
                    temp->setLeft(nn);
                    cout << "Value \"" << temp->getLeft()->getData() << "\" is inserted at the LEFT of " << temp->getData() << endl;
                    nfull = 1;
                }
                else
                    temp = temp->getLeft();
            }
            else if(temp->getData() < val) {
                if(temp->getRight() == NULL) {
                    nn = new Node();
                    nn->setData(val);
                    temp->setRight(nn);
                    cout << "Value \"" << temp->getRight()->getData() << "\" inserted at the RIGHT of " << temp->getData() << endl;
                    nfull = 1;
                }
                else
                    temp = temp->getRight();
            }
            else {
                cout << "Invalid choice!!\n";
                break;
            }
        }
        while(nfull == 0);
    }
}

void BST :: display() {
    Node *temp;
    int ch;
    temp = root;
    cout << "1.Preorder.\n2.Inorder\n3.Postorder\n4.Exit\n";
    cout << "\nEnter the mode of traversal you want to go with:\n";
    cin >> ch;
    cout << "Values are: ";
    switch(ch) {
        case 1: 
            preorder(temp);
            break;
        case 2:
            inorder(temp);
            break;
        case 3:
            postorder(temp);
            break;
        case 4:
            exit(0);
        default:
            cout  << "\nInvalid choice!\n";
            break;
    }
}

void BST :: preorder(Node *temp) {
    if(temp != NULL) {
        cout << temp->getData() << " ";
        preorder(temp->getLeft());
        preorder(temp->getRight());
    }
}

void BST :: postorder(Node *temp) {
    if(temp != NULL) {
        postorder(temp->getLeft());
        postorder(temp->getRight());
        cout << temp->getData() << " ";
    }
}

void BST :: inorder(Node *temp) {
    if(temp != NULL) {
        inorder(temp->getLeft());
        cout << temp->getData() << " ";
        inorder(temp->getRight());
    }
}

int BST :: search(int target) {
    int flag = 0;
    Node *temp;
    temp = root;
    while(temp != NULL) {
        if(temp->getData() == target) {
            flag = 1;
            break;
        }
        else if(temp->getData() < target)
            temp = temp->getRight();
        else
            temp = temp->getLeft();
    }
    return flag;
}

void BST :: smallest() {
    Node *temp;
    temp = root;
    if(temp != NULL) {
        while(temp->getLeft() != NULL)
            temp = temp->getLeft();
        cout << "\nSmallest Node in BST is--> " << temp->getData() << "\n";
    }
}

void BST :: mirror(Node *root) {
    Node *temp;
    if(root != NULL)  {
        temp = root->getLeft();
        root->setLeft(root->getRight());
        root->setRight(temp);
        mirror(root->getLeft());
        mirror(root->getRight());
    }
}

void BST :: mirr() { mirror(root); }

int BST :: longestpath(Node *temp) {
    int heightL, heightR;
    if(temp == NULL)
        return 0;
    heightL = longestpath(temp->getLeft());
    heightR = longestpath(temp->getRight());
    if(heightR > heightL)
        return (heightR+1);
    else
        return (heightL+1);
}

void BST :: longpath() {
    int t;
    t = longestpath(root);
    cout << "Longest Path length is-->" << t;
}


int main() {
    BST obj;
    int ch;
    int val, flag;
    do {
        cout << "\n1.Create Binary Search Tree.\n2.Display Binary Search Tree.\n3.Insert value\n4.Search for a value.\n5.Find Smallest node in BST.\n6.Longest Path.\n7.Mirror\n8.Exit.";
        cout << "\nEnter your choice:\n";
        cin >> ch;
        switch(ch) {
            case 1:
                obj.create();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                cout << "Enter value:\n";
                cin >> val;
                obj.insert(val);
                break;
            case 4:
                cout << "Enter the value to be searched:\n";
                cin >> val;
                flag = obj.search(val);
                if(flag == 1)
                    cout << "\"" << val << "\"has been found\n";
                else
                    cout << "Not found...plz insert that first\n";
                break;
            case 5:
                obj.smallest();
                break;
            case 6:
                obj.longpath();
                break;
            case 7:
                obj.mirr();
                break;
            case 8:
                cout << "See you around.. Have a good day." << endl;
            default:
                cout << "Invalid choice!!\n";
                break;
        }
    }
    while(ch != 8);
    return 0;
}