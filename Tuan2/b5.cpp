#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    Node *top = NULL;
};

Node* makenode(int k) {
    Node *p = new Node();
    p->data = k;
    p->next = NULL;
    return p;
}

bool isEmpty(Stack s) {
    return s.top == NULL;
}

void Push(Stack &s, int k) {
    Node *p = makenode(k);
    p->next = s.top;
    s.top = p;
}

void Pop(Stack &s) {
    if(isEmpty(s)) return ;
    s.top = s.top->next;
}

void Reverse(Stack &s) {
    Node *next = NULL, *prev = NULL, *curr = s.top;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    s.top = prev;
}

void print(Stack s) {
    Reverse(s);
    while(s.top) {
        cout << s.top->data << " ";
        s.top = s.top->next;
    }

}

int main()
{
    int n;
    cin >> n;
    Stack s;
    for(int i=0; i<n; i++) {
        string a;
        cin >> a;
        if(a == "push"){
            int k;
            cin >> k;
            Push(s, k);
        }
        else {
            Pop(s);
        }
    }

    print(s);

    return 0;
}
