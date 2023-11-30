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

int Count(Node *head) {
    int Size = 0;
    while(head != NULL) {
        head = head->next;
        Size++;
    }
    return Size;
}

Node* Insert(Node *head, int p, int x) {
    Node *tmp = makenode(x);
    Node *chay = head;
    int Size = Count(head);

    if(head == NULL) {
        head = tmp;
    }
    else if(p == 0) {
        tmp->next = head;
        head = tmp;
    }
    else if(p == Size) {
        Node *q = head;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = tmp;
    }
    else if((p < Size) && (p > 0)) {
        Node *q = head;
        while(p > 1) {
            q = q->next;
            p--;
        }
        tmp->next = q->next;
        q->next = tmp;
    }

    return head;
}

Node* Delete(Node *head, int p) {
    int Size = Count(head) ;
    if(head == NULL) return head;
    Node *trc = NULL, *sau = head;
    for(int i=0; i<p; i++) {
        trc = sau;
        sau = sau->next;
    }
    if(trc == NULL) head = head->next;
    else trc->next = sau->next;

    return head;
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
        string s;
        cin >> s;
        if(s == "insert"){
            int p, x;
            cin >> p >> x;
            head = Insert(head, p, x);
        }
        else {
            int p;
            cin >> p;
            head = Delete(head, p);
        }
    }

    print(head);

    return 0;
}
