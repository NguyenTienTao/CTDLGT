#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node* makenode(int k) {
    Node *p = new Node();
    p->data = k;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

Node* insertFirst(Node *head, int k) {
    Node *p = makenode(k);
    p->next = head;
    if(head) {
        head->prev = p;
    }
    head = p;
    return head;
}

int count_triplets(Node *head) {
    int cnt=0;
    Node *p = head->next;
    while(p->next != NULL) {
        if((p->prev->data + p->data + p->next->data) == 0) cnt++;
        p = p->next;
    }
    return cnt;
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

    cout << count_triplets(head);

    return 0;
}
