#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAX 50
using namespace std;

class Stack {
    int data[MAX];
    int top;
public:
    Stack() { top = -1; }
    int getStackTop() { return data[top]; }
    void push(int d) {
        if(top == (MAX-1)) {
            cout << "\nStack is Full\n";
            return;
        }
        data[++top] = d;
    }
    int poppedElement() { return data[top--]; }
    int isempty() { return (top == -1); }
};

class Evaluate {
    char input[MAX], post[MAX];
    Stack s;
public:
    void getinfix() {
        //cin.ignore();
        cout << "\nEnter the infix expression to be converted:\n";
        cin.getline(input,MAX);
    }
    void inf_to_post() {
        int i, j;
        char ch, ch1;
        s = Stack();
        for(i = 0,j = 0; input[i] != '\0'; i++) {
            ch = input[i];
            switch(ch) {
                case '(':
                    s.push(ch);
                    break;
                case '+':

                case '-':

                case '/':

                case '*':
                    if(s.isempty()) { s.push(ch); }
                    else {
                        ch1 = s.getStackTop();
                        while(priority(ch1) >= priority(ch)) {
                            ch1 = s.poppedElement();
                            post[j++] = ch1;
                            ch1 = s.getStackTop();
                        }
                        s.push(ch);
                    }
                    break;
                case')':
                    ch1 = s.poppedElement();
                    while(ch1 != '(') {
                        post[j++] = ch1;
                        ch1 = s.poppedElement();
                    }
                    break;
                default:
                    post[j++] = ch;
            }
        }
        while(!s.isempty())
            post[j++] = s.poppedElement();
        post[j] = '\0';
        cout << "\nTHE POSTFIX EXPRESSION IS --> " << post << "\n";
    }
    int priority(char ch) {
        switch(ch) {
            case '*':

            case '/':
                return 2;
            case '+':

            case '-':
                return 1;
            case '(':
                return 0;
        }
        return -1;
    }
    void find() {
        char ch;
        int op1, op2, v, i;
        float r;
        cout << "\nEvaluation....\n";
        for(i = 0; post[i] != '\0'; i++) {
            ch = post[i];
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                cout << "\nPlease enter value of variable " << ch << "\n";
                cin >> v;
                s.push(v);
            }
            else {
                op2 = s.poppedElement();
                op1 = s.poppedElement();
                switch(ch) {
                    case '+':
                        r = op1+op2;
                        break;
                    case '-':
                        r = op1-op2;
                        break;
                    case '*':
                        r = op1*op2;
                        break;
                    case '/':
                        r = op1/op2;
                        break;
                }
                s.push(r);
            }
        }
        r = s.poppedElement();
        cout << "Result is --> " << r << "\n";
    }
};

int main() {
    Evaluate e1;
    e1.getinfix();
    e1.inf_to_post();
    e1.find();
    return 0;
}

