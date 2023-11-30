#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* makenode(int k) {
    Node *p = new Node();
    p->data = k;
    p->next = NULL;
    return p;
}

Node* insertFirst(Node *head, int k) {
    Node *p = makenode(k);
    if(head) {
        p->next = head;
        head = p;
    }
    else {
        head = p;
    }
    return head;
}

int countnumofpairs(Node *head) {
    int cnt=0;
    for(Node *p = head; p->next != NULL; p = p->next) {
        for(Node *q = p->next; q != NULL; q = q->next) {
            if(p->data == q->data) cnt++;
        }
    }
    return cnt;
}

void print(Node* head) {
    Node *p = new Node();
    p = head;
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }

}

int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        head = insertFirst(head, x);
    }

    cout << countnumofpairs(head);

    return 0;
}
