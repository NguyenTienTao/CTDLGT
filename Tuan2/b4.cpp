#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct Stack {
    Node *Front = NULL;
    Node *rear = NULL;
};

Node* makenode(int k) {
    Node *p = new Node();
    p->data = k;
    p->next = NULL;
    return p;
}

bool isEmpty(Stack s) {
    return s.Front == NULL;
}

void EnQueue(Stack &s, int k) {
    Node *p = makenode(k);
    if(isEmpty(s)) {
        s.Front = s.rear = p;
    }
    else {
        s.rear->next = p;
        s.rear = p;
    }
}

void DeQueue(Stack &s) {
    if(isEmpty(s)) return ;
    s.Front = s.Front->next;
    if(s.Front == NULL) {
        s.rear = NULL;
    }
}

void print(Stack s) {
    while(s.Front) {
        cout << s.Front->data << " ";
        s.Front = s.Front->next;
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
        if(a == "enqueue"){
            int k;
            cin >> k;
            EnQueue(s, k);
        }
        else {
            DeQueue(s);
        }
    }

    print(s);
}
